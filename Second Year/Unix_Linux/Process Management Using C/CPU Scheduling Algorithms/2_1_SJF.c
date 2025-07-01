#include <stdio.h>

int main() {
    typedef struct {
        int process_id;
        int burst_time;
    } Process;

    int n, i;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int wt[n], tat[n];
    float total_wt = 0, total_tat = 0;
    Process p[n];

    printf("Enter the burst time for each process:\n");
    for (i = 0; i < n; i++) {
        p[i].process_id = i + 1;
        printf("Process %d: ", i + 1);
        scanf("%d", &p[i].burst_time);
    }

    Process temp;
    for (i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (p[j].burst_time > p[j + 1].burst_time) {
                temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }

    wt[0] = 0;
    for (i = 1; i < n; i++) {
        wt[i] = p[i - 1].burst_time + wt[i - 1];
    }

    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < n; i++) {
        tat[i] = p[i].burst_time + wt[i];
        total_wt += wt[i];
        total_tat += tat[i];
        printf("%d\t%d\t\t%d\t\t%d\n", p[i].process_id, p[i].burst_time, wt[i], tat[i]);
    }

    printf("\nAverage Waiting Time: %.2f\n", total_wt / n);
    printf("Average Turnaround Time: %.2f\n", total_tat / n);

    return 0;
}