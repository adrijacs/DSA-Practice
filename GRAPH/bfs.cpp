#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Function to perform BFS on the graph
void bfs(int startVertex, const vector<vector<int>>& adjList) {
    vector<bool> visited(adjList.size(), false); // To keep track of visited vertices
    queue<int> q; // Queue to manage the BFS process

    visited[startVertex] = true; // Mark the start vertex as visited
    q.push(startVertex); // Enqueue the start vertex

    while (!q.empty()) {
        int vertex = q.front(); // Get the vertex at the front of the queue
        q.pop(); // Remove the vertex from the queue
        cout << vertex << " "; // Process the vertex (print it)

        // Iterate over all adjacent vertices
        for (int neighbor : adjList[vertex]) {
            if (!visited[neighbor]) { // If the neighbor hasn't been visited yet
                visited[neighbor] = true; // Mark it as visited
                q.push(neighbor); // Enqueue it
            }
        }
    }
}

int main() {
    int numVertices = 5; // Number of vertices in the graph
    vector<vector<int>> adjList(numVertices); // Adjacency list representation of the graph

    // Example graph
    // Adding edges (undirected graph for simplicity)
    adjList[0].push_back(1);
    adjList[0].push_back(2);
    adjList[1].push_back(0);
    adjList[1].push_back(3);
    adjList[2].push_back(0);
    adjList[2].push_back(3);
    adjList[3].push_back(1);
    adjList[3].push_back(2);
    adjList[3].push_back(4);
    adjList[4].push_back(3);

    // Start BFS traversal from vertex 0
    cout << "BFS traversal starting from vertex 0: ";
    bfs(0, adjList);
    cout << endl;

    return 0;
}
