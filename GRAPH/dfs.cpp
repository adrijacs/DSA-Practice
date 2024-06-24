#include <iostream>
#include <vector>

using namespace std;

void dfs_recursive(int vertex, const vector<vector<int>>& adjList, vector<bool>& visited) {
    visited[vertex] = true; // Mark the current vertex as visited
    cout << vertex << " "; // Process the vertex (print it)

    // Recur for all the vertices adjacent to this vertex
    for (int neighbor : adjList[vertex]) {
        if (!visited[neighbor]) {
            dfs_recursive(neighbor, adjList, visited);
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

    // Start DFS traversal from vertex 0
    vector<bool> visited(numVertices, false); // To keep track of visited vertices
    cout << "DFS traversal starting from vertex 0: ";
    dfs_recursive(0, adjList, visited);
    cout << endl;

    return 0;
}
