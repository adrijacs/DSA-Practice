#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int* dijkstra(int V,vector<vector<int>>adj[],int S){
      int *dist=new int[V];
      for(int i=0;i<V;i++)dist[i]=1e9;
      priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
      dist[S]=0;
      pq.push({0,S});
      while(!pq.empty()){
        int dis=pq.top().first;
        int node=pq.top().second;
        pq.pop();
        for(auto it:adj[node]){
           int edgeWeight=it[1];
           int adjNode=it[0];
           if(dis+edgeWeight<dist[adjNode]){
            dist[adjNode]=dis+edgeWeight;
            pq.push({dist[adjNode],adjNode});
           }
        }
      }
     return dist;
    }
};

int main() {
    int V, E;
    cout << "Enter the number of vertices and edges: ";
    cin >> V >> E;
    
    vector<vector<int>> adj[V];
    
    cout << "Enter the edges (source, destination, weight) one by one:\n";
    for (int i = 0; i < E; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});  
    }
    
    int S;
    cout << "Enter the source vertex: ";
    cin >> S;
    Solution object;
    int* distances = object.dijkstra(V, adj, S);
    
    cout << "Shortest distances from source vertex " << S << ":\n";
    for (int i = 0; i < V; ++i) {
        cout << "Vertex " << i << ": " << distances[i] << endl;
    }
    
    delete[] distances;
    
    return 0;
}