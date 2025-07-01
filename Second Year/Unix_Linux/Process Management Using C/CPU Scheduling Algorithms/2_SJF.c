#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

void sjf(int n, int bt[]) {
    int wt[n], tat[n], total_wt = 0, total_tat = 0;
    for (int i = 0; i < n; i++) {
        if (bt[i] > bt[i + 1]) {
            int temp = bt[i];
            bt[i] = bt[i + 1];
            bt[i + 1] = temp;
        }    }
    for (int i = 0; i < n; i++) {
        pid_t pid = fork();
        if (pid == 0) {
            printf("Process %d is executing\n", i + 1);
            sleep(bt[i]); 
            printf("Process %d finished execution\n", i + 1);
            _exit(0); 
        } else if (pid < 0) {
            perror("Fork failed");
            return;
        }
    }
    for (int i = 0; i < n; i++) {
        wait(NULL); 
    }
    printf("All processes have finished execution\n");
    for (int i = 0; i < n; i++) {
        wt[i] = total_wt;
        total_wt += bt[i];
        tat[i] = total_wt;
        total_tat += tat[i];
    }
    printf("Average waiting time: %.2f\n", (float)total_wt / n);
}
int main() {
    int bt[] = {10, 5, 8}; 
    int n = sizeof(bt) / sizeof(bt[0]);
    sjf(n, bt);
    return 0;
}
