#include <iostream>
#include <vector>
using namespace std;

struct Process {
    int id, at, bt, remaining, wt, tat, completion;
};

int main() {
    int n;
    cout << "Enter the number of processes: ";
    cin >> n;

    vector<Process> proc(n);

    cout << "Enter Arrival Time and Burst Time for each process:\n";
    for (int i = 0; i < n; i++) {
        proc[i].id = i + 1;
        cout << "Process " << i + 1 << ": ";
        cin >> proc[i].at >> proc[i].bt;
        proc[i].remaining = proc[i].bt;
    }

    int completed = 0, currentTime = 0;
    int minBurst = 9999; // Use a large constant value for minBurst
    int shortest = -1;
    vector<bool> isCompleted(n, false);

    while (completed < n) {
        minBurst = 9999; // Reset minBurst to a large value
        for (int i = 0; i < n; i++) {
            if (proc[i].at <= currentTime && !isCompleted[i] && proc[i].remaining < minBurst) {
                minBurst = proc[i].remaining;
                shortest = i;
            }
        }

        if (shortest == -1) {
            currentTime++;
        } else {
            proc[shortest].remaining--;
            currentTime++;

            if (proc[shortest].remaining == 0) {
                proc[shortest].completion = currentTime;
                proc[shortest].tat = proc[shortest].completion - proc[shortest].at;
                proc[shortest].wt = proc[shortest].tat - proc[shortest].bt;
                isCompleted[shortest] = true;
                completed++;
            }
        }
    }

    float totalwt = 0, totaltat = 0;
    cout << "\nProcess\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n";
    for (const auto& p : proc) {
        cout << p.id << "\t\t" << p.at << "\t\t" << p.bt << "\t\t" << p.wt << "\t\t" << p.tat << endl;
        totalwt += p.wt;
        totaltat += p.tat;
    }

    cout << "\nAverage Waiting Time: " << fixed << setprecision(2) << totalwt / n << endl;
    cout << "Average Turnaround Time: " << fixed << setprecision(2) << totaltat / n << endl;

    return 0;
}