#include<bits/stdc++.h>
using namespace std;
class Solution{
  public:
  vector<int> bellman(int V,vector<vector<int>>adj,int src){
    vector<int>dist(V,1e8);
    dist[src]=0;
    for(int i=0;i<V-1;i++){
      for(auto it:adj){
        int u=it[0];
        int v=it[1];
        int w=it[2];
        if(dist[u]!=1e8 && dist[u]+w<dist[v]){
          dist[v]=dist[u]+w;
        }
      }
    }
    for(auto it:adj){
      int u=it[0];
      int v=it[1];
      int w=it[2];
      if(dist[u]!=1e8 && dist[u]+w<dist[v]){
          return {-1};
        }
    }
    return dist;
  }
};


int main() {
    int V, E;
    cout << "Enter the number of vertices and edges: ";
    cin >> V >> E;
    
    vector<vector<int>> adj;
    
    cout << "Enter the edges (source, destination, weight) one by one:\n";
    for (int i = 0; i < E; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adj.push_back({u,v,w});
    }
    
    int S;
    cout << "Enter the source vertex: ";
    cin >> S;
    Solution object;
    vector<int> distances = object.bellman(V, adj, S);
    
    cout << "Shortest distances from source vertex " << S << ":\n";
    for (int i = 0; i < V; ++i) {
        cout << "Vertex " << i << ": " << distances[i] << endl;
    }
    
  
    
    return 0;
}