#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Process {
    int pid;        // Process ID
    int arrival;    // Arrival time
    int burst;      // Burst time
    int remaining;  // Remaining burst time
};



// Function to simulate SRTF (Shortest Remaining Time First) scheduling
void SRTF(vector<Process>& processes) {
    int currentTime = 0;
    int n = processes.size();
    int completed = 0;
    vector<int> completionTime(n);
    
    while (completed < n) {
        int shortest = -1;
        int shortestBurst =INT16_MAX;
        for (int i = 0; i < n; ++i) {
            if (processes[i].arrival <= currentTime && processes[i].remaining < shortestBurst && processes[i].remaining > 0) {
                shortest = i;
                shortestBurst = processes[i].remaining;
            }
        }
        if (shortest == -1) {
            currentTime++;
        } else {
            processes[shortest].remaining--;
            if (processes[shortest].remaining == 0) {
                completed++;
                completionTime[shortest] = currentTime + 1;
            }
            currentTime++;
        }
    }

    // Calculate turnaround and waiting time
    double totalTurnaround = 0, totalWaiting = 0;
    for (int i = 0; i < n; ++i) {
        int turnaround = completionTime[i] - processes[i].arrival;
        int waiting = turnaround - processes[i].burst;
        totalTurnaround += turnaround;
        totalWaiting += waiting;
    }

    // Print average turnaround and waiting time
    cout << "SRTF Average Turnaround Time: " << totalTurnaround / n << endl;
    cout << "SRTF Average Waiting Time: " << totalWaiting / n << endl;
}

int main() {
    vector<Process> processes = {
        {1, 0, 6, 0},
        {2, 1, 8, 0},
        {3, 2, 7, 0},
        {4, 3, 3, 0}
    };

    // Make a copy of processes for SRTF
    vector<Process> processesSRTF = processes;


    SRTF(processesSRTF);

    return 0;
}
