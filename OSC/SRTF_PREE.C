#include <stdio.h>
struct Process {
    int id, at, bt, remaining, wt, tat, completion;
};
void SRTF(struct Process p[], int n) {
    int completed = 0, currentTime = 0, minIndex;
    int minBurst = 9999;
    int shortest = -1;
    int isCompleted[n];
    
    for (int i = 0; i < n; i++) {
        isCompleted[i] = 0;
        p[i].remaining = p[i].bt;
    }
    while (completed < n) {
        minBurst = 9999;
        for (int i = 0; i < n; i++) {
            if (p[i].at <= currentTime && !isCompleted[i] && p[i].remaining < minBurst) {
                minBurst = p[i].remaining;
                shortest = i;
            }
        }
        if (shortest == -1) {
            currentTime++;
        } else {
            p[shortest].remaining--;
            currentTime++;

            if (p[shortest].remaining == 0) {
                p[shortest].completion = currentTime;
                p[shortest].tat = p[shortest].completion - p[shortest].at;
                p[shortest].wt = p[shortest].tat - p[shortest].bt;
                isCompleted[shortest] = 1;
                completed++;
            }
        }
    }
}
void display(struct Process p[], int n) {
    float totalwt = 0, totaltat = 0;
    printf("\nProcess\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", p[i].id, p[i].at, p[i].bt, p[i].wt, p[i].tat);
        totalwt += p[i].wt;
        totaltat += p[i].tat;
    }
    printf("\nAverage Waiting Time: %.2f\n", totalwt / n);
    printf("Average Turnaround Time: %.2f\n", totaltat / n);
}

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    struct Process p[n];
    printf("Enter Arrival Time and Burst Time for each process:\n");
    for (int i = 0; i < n; i++) {
        p[i].id = i + 1;
        printf("Process %d: ", i + 1);
        scanf("%d %d", &p[i].at, &p[i].bt);
    }
    SRTF(p, n);
    display(p, n);
    return 0;
}