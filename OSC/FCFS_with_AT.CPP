#include <iostream>
#include <vector>
using namespace std;

struct Process
{
    int id, at, bt, ct, wt, tat;
};

void calculateFCFS(vector<Process> &proc){
    int time = 0;
    for (int i =0; i < proc.size(); i++){
        if (time < proc[i].at)
        {
            time = proc[i].at;
        }

        proc[i].ct = time + proc[i].bt;
        proc[i].tat = proc[i].ct - proc[i].at;
        proc[i].wt = proc[i].tat - proc[i].bt;
        time = proc[i].ct;
    }
}
void display(vector<Process> &proc){
    float totalWait = 0, totaltat = 0;

    cout << "\nID\tArrival\tBurst\tCompletion\tWaiting\tTurnaround\n";
    for (int i = 0; i < proc.size(); i++){
        cout << proc[i].id << "\t" << proc[i].at << "\t" << proc[i].bt << "\t"
             << proc[i].ct << "\t\t" << proc[i].wt << "\t" << proc[i].tat << endl;
        totalWait += proc[i].wt;
        totaltat += proc[i].tat;
    }
    cout << "\nAvg Waiting Time: " << totalWait / proc.size() << "\nAvg tat Time: " << totaltat / proc.size() << endl;
}

int main(){
    int n;
    cout << "Enter number of processes: ";
    cin >> n;
    vector<Process> proc(n);

    for (int i = 0; i < n; i++){
        proc[i].id = i + 1;
        cout << "Arrival & bt Time for P" << proc[i].id << ": ";
        cin >> proc[i].at >> proc[i].bt;
    }

    for (int i = 0; i < n - 1; i++){
        for (int j = i + 1; j < n; j++){
            if (proc[i].at > proc[j].at){
                Process temp = proc[i];
                proc[i] = proc[j];
                proc[j] = temp;
            }
        }
    }
    calculateFCFS(proc);
    display(proc);
}

// 5 0 4 2 5 1 4 3 6 4 2
// Output:
// Enter number of processes: 5
// Arrival & bt Time for P1: 0 4
// Arrival & bt Time for P2: 2 5
// Arrival & bt Time for P3: 1 4
// Arrival & bt Time for P4: 3 6
// Arrival & bt Time for P5: 4 2

// ID      Arrival Burst   Completion      Waiting Turnaround
// 1       0       4       4               0       4
// 3       1       4       8               3       7
// 2       2       5       13              6       11
// 4       3       6       19              10      16
// 5       4       2       21              15      17

// Avg Waiting Time: 6.8
// Avg tat Time: 11