#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>


void Priority(int n, int bt[], int pr[]) {
    int wt[n], tat[n], total_wt = 0, total_tat = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (pr[i] > pr[j]) {
                int temp = pr[i];
                pr[i] = pr[j];
                pr[j] = temp;
                temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;
            }
        }
    }
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
    int pr[] = {2, 3, 1}; 
    int n = sizeof(bt) / sizeof(bt[0]);
    Priority(n, bt, pr);
    return 0;
}
