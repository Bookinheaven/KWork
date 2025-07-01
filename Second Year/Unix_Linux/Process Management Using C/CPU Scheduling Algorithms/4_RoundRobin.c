#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

void roundRobin(int n, int bt[], int quantum) {
    int remaining_time[n];
    for (int i = 0; i < n; i++) {
        remaining_time[i] = bt[i];
    }
    int time = 0;

    while (1) {
        int done = 1;
        for (int i = 0; i < n; i++) {
            if (remaining_time[i] > 0) {
                done = 0;
                if (remaining_time[i] > quantum) {
                    printf("Process %d is executing\n", i + 1);
                    time += quantum;
                    remaining_time[i] -= quantum;
                } else {
                    printf("Process %d is executing\n", i + 1);
                    time += remaining_time[i];
                    remaining_time[i] = 0;
                    printf("Process %d finished execution\n", i + 1);
                }
            }
        }
        if (done) {
            break;
        }
    }

    printf("All processes have finished execution\n");
    for (int i = 0; i < n; i++) {
        wait(NULL);
    }
}

int main() {
    int bt[] = {10, 5, 8};
    int quantum = 2;
    int n = sizeof(bt) / sizeof(bt[0]);
    roundRobin(n, bt, quantum);
    return 0;
}
