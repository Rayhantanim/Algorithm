#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Process {
    int id, at, bt, ct, wt, tat;
};

bool compareArrival(const Process &a, const Process &b) {
    return a.at < b.at;
}

bool compareBurst(const Process &a, const Process &b) {
    return a.bt < b.bt;
}

void calculateSJF(vector<Process> &proc) {
    int time = 0;
    int completed = 0;
    int n = proc.size();
    vector<bool> isCompleted(n, false);

    while (completed != n) {
        int idx = -1;
        int minBurst = INT_MAX;

        for (int i = 0; i < n; i++) {
            if (proc[i].at <= time && !isCompleted[i] && proc[i].bt < minBurst) {
                minBurst = proc[i].bt;
                idx = i;
            }
        }

        if (idx != -1) {
            time += proc[idx].bt;
            proc[idx].ct = time;
            proc[idx].tat = proc[idx].ct - proc[idx].at;
            proc[idx].wt = proc[idx].tat - proc[idx].bt;
            isCompleted[idx] = true;
            completed++;
        } else {
            time++;
        }
    }
}

void display(const vector<Process> &proc) {
    float totalWait = 0, totalTat = 0;

    cout << "\nID\tArrival\tBurst\tCompletion\tWaiting\tTurnaround\n";
    for (const auto &p : proc) {
        cout << p.id << "\t" << p.at << "\t" << p.bt << "\t"
             << p.ct << "\t\t" << p.wt << "\t" << p.tat << endl;
        totalWait += p.wt;
        totalTat += p.tat;
    }
    cout << "\nAvg Waiting Time: " << totalWait / proc.size() << "\nAvg Turnaround Time: " << totalTat / proc.size() << endl;
}

int main() {
    int n;
    cout << "Enter number of processes: ";
    cin >> n;
    vector<Process> proc(n);

    for (int i = 0; i < n; i++) {
        proc[i].id = i + 1;
        cout << "Arrival & Burst Time for P" << proc[i].id << ": ";
        cin >> proc[i].at >> proc[i].bt;
    }

    sort(proc.begin(), proc.end(), compareArrival);
    calculateSJF(proc);
    display(proc);

    return 0;
}
