#include <stdio.h>

typedef struct {
    int burst_time;
    int id;
    int priority;
} Process;

int main() {
    int n, i, j;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    Process proc[n];
    int wt[n], tat[n];
    float total_wt = 0, total_tat = 0;
    
    printf("Enter burst times and priorities:\n");
    for(i = 0; i < n; i++) {
        printf("P%d Burst Time: ", i+1);
        scanf("%d", &proc[i].burst_time);
        printf("P%d Priority (lower number = higher priority): ", i+1);
        scanf("%d", &proc[i].priority);
        proc[i].id = i+1; 
    }

    for(i = 0; i < n-1; i++) {
        for(j = 0; j < n-i-1; j++) {
            if(proc[j].priority > proc[j+1].priority) {
                Process temp = proc[j];
                proc[j] = proc[j+1];
                proc[j+1] = temp;
            }
        }
    }
    wt[0] = 0;  
    for(i = 1; i < n; i++) {
        wt[i] = wt[i-1] + proc[i-1].burst_time;
    }
    printf("\nProcess\tPriority\tBT\tWT\tTAT\n");
    for(i = 0; i < n; i++) {
        tat[i] = proc[i].burst_time + wt[i]; 
        total_wt += wt[i];
        total_tat += tat[i];
        printf("P%d\t%d\t\t%d\t%d\t%d\n", proc[i].id, proc[i].priority, proc[i].burst_time, wt[i], tat[i]);
    }

    printf("\nAverage Waiting Time: %.2f\n", total_wt/n);
    printf("Average Turnaround Time: %.2f\n", total_tat/n);

    return 0;
}
