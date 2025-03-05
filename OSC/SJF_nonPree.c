#include <stdio.h>
struct Process {
    int id, at, bt, wt, tat;
};

void sort(struct Process p[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (p[i].bt > p[j].bt) {
                struct Process temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }
}

void SJF(struct Process p[], int n) {
    int currentTime = 0;
    
    sort(p, n);
    
    for (int i = 0; i < n; i++) {
        if (currentTime < p[i].at) {
            currentTime = p[i].at;
        }
        p[i].wt = currentTime - p[i].at;
        p[i].tat = p[i].wt + p[i].bt;
        currentTime += p[i].bt;
    }
}

void display(struct Process p[], int n) {
    float totalWaiting = 0, totalTurnaround = 0;
    
    printf("\nProcess\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", p[i].id, p[i].at, p[i].bt, p[i].wt, p[i].tat);
        totalWaiting += p[i].wt;
        totalTurnaround += p[i].tat;
    }
    
    printf("\nAverage Waiting Time: %.2f\n", totalWaiting / n);
    printf("Average Turnaround Time: %.2f\n", totalTurnaround / n);
}
int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    struct Process p[n];
    printf("Enter Arrival Time and Burst Time for each process:\n");
    for (int i = 0; i < n; i++) {
        p[i].id = i + 1;
        printf("P%d: ", i + 1);
        scanf("%d %d", &p[i].at, &p[i].bt);
    }
    SJF(p, n);
    display(p, n);
    return 0;
}