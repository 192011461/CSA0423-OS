include <stdio.h>
#include <stdlib.h>

struct process {
    int id;
    int arrival_time;
    int burst_time;
};

int compare(const void* a, const void* b) {
    struct process* p1 = (struct process*) a;
    struct process* p2 = (struct process*) b;
    return p1->burst_time - p2->burst_time;
}

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct process processes[n];
    for (int i = 0; i < n; i++) {
        processes[i].id = i;
        printf("Enter arrival time and burst time for process %d: ", i);
        scanf("%d %d", &processes[i].arrival_time, &processes[i].burst_time);
    }

    qsort(processes, n, sizeof(struct process), compare);

    int current_time = 0;
    float total_waiting_time = 0, total_turnaround_time = 0;
    printf("\nProcess execution order: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", processes[i].id);
        total_waiting_time += current_time - processes[i].arrival_time;
        current_time += processes[i].burst_time;
        total_turnaround_time += current_time - processes[i].arrival_time;
    }

    printf("\nAverage waiting time: %f\n", total_waiting_time / n);
    printf("Average turnaround time: %f\n", total_turnaround_time / n);

    return 0;
}
