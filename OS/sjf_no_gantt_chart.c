#include <stdio.h>

struct Process {
    int pid, arrival_time, burst_time;
    int start_time, completion_time, waiting_time, turnaround_time;
    int completed;
} p[10];

int main() {
    int n, i, current_time = 0, completed = 0;
    float total_wt = 0, total_tat = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        p[i].pid = i + 1;
        printf("\nProcess %d:\n", p[i].pid);
        printf("Arrival Time: ");
        scanf("%d", &p[i].arrival_time);
        printf("Burst Time: ");
        scanf("%d", &p[i].burst_time);
        p[i].completed = 0;
    }

    while(completed < n) {
        int idx = -1;
        int min_bt = 9999;

        for(i = 0; i < n; i++) {
            if(p[i].arrival_time <= current_time && p[i].completed == 0) {
                if(p[i].burst_time < min_bt) {
                    min_bt = p[i].burst_time;
                    idx = i;
                } else if(p[i].burst_time == min_bt && p[i].arrival_time < p[idx].arrival_time) {
                    idx = i;
                }
            }
        }

        if(idx != -1) {
            p[idx].start_time = current_time;
            p[idx].completion_time = current_time + p[idx].burst_time;
            p[idx].waiting_time = p[idx].start_time - p[idx].arrival_time;
            p[idx].turnaround_time = p[idx].waiting_time + p[idx].burst_time;

            total_wt += p[idx].waiting_time;
            total_tat += p[idx].turnaround_time;

            current_time = p[idx].completion_time;
            p[idx].completed = 1;
            completed++;
        } else {
            current_time++; // CPU is idle
        }
    }

    // Print table
    printf("\nProcess\tAT\tBT\tST\tCT\tWT\tTAT\n");
    for(i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
               p[i].pid, p[i].arrival_time, p[i].burst_time, p[i].start_time,
               p[i].completion_time, p[i].waiting_time, p[i].turnaround_time);
    }

    printf("\nAverage Waiting Time = %.2f", total_wt / n);
    printf("\nAverage Turnaround Time = %.2f\n", total_tat / n);

    return 0;
}
 
