#include <stdio.h>

struct Process {
    int pid;
    int arrival_time, burst_time, start_time, waiting_time, turnaround_time, completion_time;
};

// Swap function
void swap(struct Process *a, struct Process *b) {
    struct Process temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    struct Process p[10];
    int n, i, j;
    int total_wt = 0, total_tat = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        p[i].pid = i + 1;
        printf("\nProcess %d:\n", p[i].pid);
        printf("Arrival Time: ");
        scanf("%d", &p[i].arrival_time);
        printf("Burst Time: ");
        scanf("%d", &p[i].burst_time);
    }

    // Sort by arrival time
    for(i = 0; i < n - 1; i++) {
        for(j = i + 1; j < n; j++) {
            if(p[i].arrival_time > p[j].arrival_time) {
                swap(&p[i], &p[j]);
            }
        }
    }

    // First process
    p[0].start_time = p[0].arrival_time;
    p[0].waiting_time = 0;
    p[0].turnaround_time = p[0].burst_time;
    p[0].completion_time = p[0].start_time + p[0].burst_time;

    total_tat += p[0].turnaround_time;

    // Remaining processes
    for(i = 1; i < n; i++) {
        if(p[i-1].completion_time > p[i].arrival_time)
            p[i].start_time = p[i-1].completion_time;
        else
            p[i].start_time = p[i].arrival_time;

        p[i].waiting_time = p[i].start_time - p[i].arrival_time;
        p[i].turnaround_time = p[i].waiting_time + p[i].burst_time;
        p[i].completion_time = p[i].start_time + p[i].burst_time;

        total_wt += p[i].waiting_time;
        total_tat += p[i].turnaround_time;
    }

    // Display Table
    printf("\nProcess\tAT\tBT\tST\tWT\tTAT\n");
    for(i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", 
               p[i].pid, p[i].arrival_time, p[i].burst_time, 
               p[i].start_time, p[i].waiting_time, p[i].turnaround_time);
    }

    // Averages
    printf("\nAverage Waiting Time = %.2f\n", total_wt / (float)n);
    printf("Average Turnaround Time = %.2f\n", total_tat / (float)n);

    // Gantt Chart
    printf("\nGantt Chart:\n");
    printf(" ");

    for(i = 0; i < n; i++) {
        printf("-------");
    }
    printf("\n|");

    for(i = 0; i < n; i++) {
        printf("  P%d  |", p[i].pid);
    }

    printf("\n ");
    for(i = 0; i < n; i++) {
        printf("-------");
    }

    printf("\n");
    printf("%d", p[0].start_time);
    for(i = 0; i < n; i++) {
        printf("     %d", p[i].completion_time);
    }
    printf("\n");

    return 0;
}
