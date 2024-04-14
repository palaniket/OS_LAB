#include <iostream>
#include <vector>

using namespace std;

struct Process {
    int pid;        // Process ID
    int arrival;    // Arrival time
    int burst;      // Burst time
};

// Function to simulate FCFS (First-Come, First-Served) scheduling
void FCFS(const vector<Process>& processes) {
    int n = processes.size();
    int currentTime = 0;
    double totalTurnaround = 0, totalWaiting = 0;

    cout << "FCFS Schedule: " << endl;
    for (const Process& p : processes) {
        // Wait until arrival time if necessary
        if (currentTime < p.arrival) {
            currentTime = p.arrival;
        }

        // Process the current process
        cout << "Process " << p.pid << " starts at time " << currentTime << endl;
        totalWaiting += currentTime - p.arrival;
        currentTime += p.burst;
        totalTurnaround += currentTime - p.arrival;
        cout << "Process " << p.pid << " finishes at time " << currentTime << endl;
    }

    // Calculate average turnaround and waiting time
    double avgTurnaround = totalTurnaround / n;
    double avgWaiting = totalWaiting / n;

    cout << "Average Turnaround Time: " << avgTurnaround << endl;
    cout << "Average Waiting Time: " << avgWaiting << endl;
}

int main() {
    vector<Process> processes = {
        {1, 0, 6},
        {2, 1, 8},
        {3, 2, 7},
        {4, 3, 3}
    };

    FCFS(processes);

    return 0;
}
