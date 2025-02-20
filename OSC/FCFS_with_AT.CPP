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
            time = proc[i].at;

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
// 3 5 2 2 4 4 2