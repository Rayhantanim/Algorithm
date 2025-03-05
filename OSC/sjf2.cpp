#include <iostream>
#include <algorithm>

using namespace std;

// Structure to store process details
struct Process {
    int id;        // Process ID
    int arrival;   // Arrival Time
    int burst;     // Burst Time
    int waiting;   // Waiting Time
    int turnaround;// Turnaround Time
};

// Function to compare processes based on burst time (for sorting)
// bool compareBurst(Process a, Process b) {
//     return a.burst < b.burst;
// }

// Function to implement SJF Scheduling
void sjfScheduling(Process proc[], int n) {
    int currentTime = 0;
    int completed = 0;
    bool visited[n] = {false};

    while (completed < n) {
        int minIndex = -1;
        int minBurst = 1e9;

        // Find the process with the shortest burst time that has arrived
        for (int i = 0; i < n; i++) {
            if (!visited[i] && proc[i].arrival <= currentTime && proc[i].burst < minBurst) {
                minBurst = proc[i].burst;
                minIndex = i;
            }
        }

        if (minIndex == -1) { // If no process is found, increment time
            currentTime++;
        } else {
            // Process execution
            visited[minIndex] = true;
            proc[minIndex].waiting = currentTime - proc[minIndex].arrival;
            proc[minIndex].turnaround = proc[minIndex].waiting + proc[minIndex].burst;
            currentTime += proc[minIndex].burst;
            completed++;
        }
    }
}

// Function to calculate and display results
void displayProcesses(Process proc[], int n) {
    float totalWaiting = 0, totalTurnaround = 0;
    
    cout << "\nProcess\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n";
    for (int i = 0; i < n; i++) {
        cout << proc[i].id << "\t\t" << proc[i].arrival << "\t\t" 
             << proc[i].burst << "\t\t" << proc[i].waiting << "\t\t" 
             << proc[i].turnaround << endl;
        totalWaiting += proc[i].waiting;
        totalTurnaround += proc[i].turnaround;
    }
    
    cout << "\nAverage Waiting Time: " << (totalWaiting / n) << endl;
    cout << "Average Turnaround Time: " << (totalTurnaround / n) << endl;
}

int main() {
    int n;
    
    cout << "Enter the number of processes: ";
    cin >> n;
    
    Process proc[n];
    
    cout << "Enter Arrival Time and Burst Time for each process:\n";
    for (int i = 0; i < n; i++) {
        proc[i].id = i + 1;
        cout << "Process " << i + 1 << ": ";
        cin >> proc[i].arrival >> proc[i].burst;
    }

    // Apply SJF Scheduling
    sjfScheduling(proc, n);

    // Display the results
    displayProcesses(proc, n);

    return 0;
}
