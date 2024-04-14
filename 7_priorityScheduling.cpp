// Priority Scheduling
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Process {
    int id;
    int arrivalTime;
    int burstTime;
    int remainingTime;
    int priority;
};

struct ComparePriority {
    bool operator()(const Process& p1, const Process& p2) {
        return p1.priority > p2.priority;
    }
};

void priorityScheduling(vector<Process>& processes) {
    priority_queue<Process, vector<Process>, ComparePriority> priorityQueue;
    int currentTime = 0;
    int totalProcesses = processes.size();
    int completedProcesses = 0;

    while (completedProcesses < totalProcesses) {
        // Adding arriving processes to the priority queue
        for (int i = 0; i < totalProcesses; ++i) {
            if (processes[i].arrivalTime <= currentTime && processes[i].remainingTime > 0) {
                priorityQueue.push(processes[i]);
            }
        }

        if (!priorityQueue.empty()) {
            Process currentProcess = priorityQueue.top();
            priorityQueue.pop();

            int executeTime = min(currentProcess.remainingTime, currentProcess.burstTime);
            currentTime += executeTime;
            currentProcess.remainingTime -= executeTime;

            cout << "Process " << currentProcess.id << " executed for " << executeTime << " units at time " << currentTime << endl;

            if (currentProcess.remainingTime <= 0) {
                completedProcesses++;
                cout << "Process " << currentProcess.id << " completed at time " << currentTime << endl;
            } else {
                priorityQueue.push(currentProcess);
            }
        } else {
            currentTime++;
        }
    }
}

int main() {
    vector<Process> processes = {
        {1, 0, 5, 5, 2},
        {2, 1, 3, 3, 1},
        {3, 2, 8, 8, 3},
        {4, 3, 6, 6, 2}
    };

    priorityScheduling(processes);

    return 0;
}