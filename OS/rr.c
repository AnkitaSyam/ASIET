#include <stdio.h>

#define MAX 100

typedef struct {
    int process_id;        
    int burst_time;         
    int remaining_time;   
    int completion_time;    
    int turnaround_time;    
    int waiting_time;       
} Process;

int main() {
    int num_processes, time_quantum;
    Process p[MAX];

    printf("Enter number of processes: ");
    scanf("%d", &num_processes);

    for (int i = 0; i < num_processes; i++) {
        p[i].process_id = i + 1;
        printf("Enter burst time for Process P%d: ", p[i].process_id);
        scanf("%d", &p[i].burst_time);
        p[i].remaining_time = p[i].burst_time;
    }

    printf("Enter Time Quantum: ");
    scanf("%d", &time_quantum);

    int time = 0, all_done;

    // Round Robin Scheduling Logic
    do {
        all_done = 1;
        for (int i = 0; i < num_processes; i++) {
            if (p[i].remaining_time > 0) {
                all_done = 0;
                if (p[i].remaining_time > time_quantum) {
                    time += time_quantum;
                    p[i].remaining_time -= time_quantum;
                } else {
                    time += p[i].remaining_time;
                    p[i].completion_time = time;
                    p[i].remaining_time = 0;
                }
            }
        }
    } while (!all_done);

    // Calculate Turnaround Time and Waiting Time
    float total_turnaround_time = 0, total_waiting_time = 0;
    printf("\nProcessID\tBurstTime\tCompletionTime\tTurnaroundTime\tWaitingTime\n");

    for (int i = 0; i < num_processes; i++) {
        p[i].turnaround_time = p[i].completion_time;
        p[i].waiting_time = p[i].turnaround_time - p[i].burst_time;
        total_turnaround_time += p[i].turnaround_time;
        total_waiting_time += p[i].waiting_time;

        printf("P%d\t\t%d\t\t%d\t\t%d\t\t%d\n",
               p[i].process_id,
               p[i].burst_time,
               p[i].completion_time,
               p[i].turnaround_time,
               p[i].waiting_time);
    }

    printf("\nAverage Turnaround Time = %.2f", total_turnaround_time / num_processes);
    printf("\nAverage Waiting Time = %.2f\n", total_waiting_time / num_processes);

    return 0;
}
