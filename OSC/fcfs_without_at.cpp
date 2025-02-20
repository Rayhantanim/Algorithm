#include <iostream> 
#include <vector> 
using namespace std;

struct Process { 
int id, bt, ct, wt, tat; 
};

void calculateFCFS(vector<Process> &proc) { 
	int time = 0; 
	for (int i = 0; i < proc.size(); i++) { 
		proc[i].ct = time + proc[i].bt; 
        proc[i].tat = proc[i].ct; 
 	    proc[i].wt = proc[i].tat - proc[i].bt; 
 	    time = proc[i].ct; 
  } 
}

void display(vector<Process> &proc) { 
  float totalWait = 0, totalTat = 0; 
	cout << "\nID\tBurst\tCompletion\tWaiting\tTurnaround\n"; 
  for (int i = 0; i < proc.size(); i++) { 
	  cout << proc[i].id << "\t" << proc[i].bt << "\t" << proc[i].ct << "\t\t" << proc[i].wt << "\t" << proc[i].tat << endl; 
	  totalWait += proc[i].wt; 
	  totalTat += proc[i].tat; 
	} 
	cout << "\nAvg Waiting Time: " 
	<< totalWait / proc.size() 
	<< "\nAvg Turnaround Time: " 
	<< totalTat / proc.size() << endl; 
}

int main() { 
   int n; 
	 cout << "Enter number of processes: "; 
	 cin >> n; 
	 vector<Process> proc(n); 
	 for (int i = 0; i < n; i++) { 
		 proc[i].id = i + 1; 
		 cout << "Burst Time for P" << proc[i].id << ": "; 
		 cin >> proc[i].bt; 
	 } 
	 calculateFCFS(proc); 
	 display(proc); 
}
// 3 5 3 8
// Output:
// Enter number of processes: 3
// Burst Time for P1: 5
// Burst Time for P2: 3
// Burst Time for P3: 8
// ID      Burst   Completion      Waiting Turnaround
// 1       5       5               0       5
// 2       3       8               5       8
// 3       8       16              8       16
// Avg Waiting Time: 4.33333
// Avg Turnaround Time: 9.66667
//