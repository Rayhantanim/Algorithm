#include <stdio.h>
int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int at[n], bt[n], rt[n], ct[n], tat[n], wt[n], completed = 0, time = 0;
    float total_wt = 0, total_tat = 0;
    printf("Enter Arrival Time and Burst Time:\n");
    for (int i = 0; i < n; i++) {
        printf("Process %d: ", i + 1);
        scanf("%d %d", &at[i], &bt[i]);
        rt[i] = bt[i];
    }
    while (completed < n) {
        int min_index = -1, min_rt = 99999;
        for (int i = 0; i < n; i++) {
            if (at[i] <= time && rt[i] > 0 && rt[i] < min_rt) {
                min_rt = rt[i];
                min_index = i;
            }
        }
        if (min_index == -1) {
            time++;
            continue;
        }
        rt[min_index]--;
        time++;
        
        if (rt[min_index] == 0) {
            completed++;
            ct[min_index] = time;
            tat[min_index] = ct[min_index] - at[min_index];
            wt[min_index] = tat[min_index] - bt[min_index];
            total_wt += wt[min_index];
            total_tat += tat[min_index];
        }
    }
    printf("\nPID  AT  BT  CT  TAT  WT\n");
    for (int i = 0; i < n; i++) {
        printf("%3d  %2d  %2d  %2d   %2d   %2d\n", i + 1, at[i], bt[i], ct[i], tat[i], wt[i]);
    }
    
    printf("\nAverage Turnaround Time: %.2f", total_tat / n);
    printf("\nAverage Waiting Time: %.2f\n", total_wt / n);
    return 0;
}
