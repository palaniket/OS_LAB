// Dekers algo
#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

#define INF INT_MAX

// Data structure to represent a graph edge
struct Edge {
    int source, destination, weight;
};

// Data structure to represent a graph
class Graph {
public:
    // An array of vectors to represent adjacency list
    vector<vector<Edge>> adjList;

    // Constructor
    Graph(int n) {
        adjList.resize(n);
    }

    // Function to add an edge to the graph
    void addEdge(int source, int destination, int weight) {
        adjList[source].push_back({source, destination, weight});
        adjList[destination].push_back({destination, source, weight}); // For undirected graph
    }

    // Dijkstra's Algorithm
    void dijkstra(int startVertex) {
        // Create a priority queue to store vertices that need to be processed
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        // Create a vector to store distances initialized to infinity
        vector<int> distance(adjList.size(), INF);

        // Set distance of the start vertex to 0
        distance[startVertex] = 0;

        // Add start vertex to the priority queue
        pq.push({0, startVertex});

        while (!pq.empty()) {
            // Extract the minimum distance vertex from the priority queue
            int u = pq.top().second;
            pq.pop();

            // Iterate through all adjacent vertices of u
            for (const auto& edge : adjList[u]) {
                int v = edge.destination;
                int weight = edge.weight;

                // Update distance if a shorter path is found
                if (distance[u] != INF && distance[u] + weight < distance[v]) {
                    distance[v] = distance[u] + weight;
                    pq.push({distance[v], v});
                }
            }
        }

        // Print shortest distances
        cout << "Vertex\tDistance from Source" << endl;
        for (int i = 0; i < distance.size(); ++i) {
            cout << i << "\t" << distance[i] << endl;
        }
    }
};

int main() {
    // Create a graph
    int numVertices = 6;
    Graph graph(numVertices);

    // Add edges
    graph.addEdge(0, 1, 4);
    graph.addEdge(0, 2, 3);
    graph.addEdge(1, 2, 1);
    graph.addEdge(1, 3, 2);
    graph.addEdge(2, 3, 4);
    graph.addEdge(3, 4, 2);
    graph.addEdge(4, 5, 6);

    // Perform Dijkstra's Algorithm starting from vertex 0
    graph.dijkstra(0);

    return 0;
}