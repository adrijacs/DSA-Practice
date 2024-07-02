#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    vector<int> dijkstra(int V,vector<vector<int>>adj[],int S){
      vector<int>dist(V,1e9);
      for(int i=0;i<V;i++)dist[i]=1e9;
      set<pair<int,int>>st;
      dist[S]=0;
      st.insert({0,S});
      while(!st.empty()){
       auto it=*(st.begin());
       int node=it.second;
       int edgeweight=it.first;
       st.erase(it);
       for(auto item:adj[node]){
           int adjNode=item[0];
           int weight=item[1];
           if(edgeweight+weight<dist[adjNode]){
              if(dist[adjNode]!=1e9){
                st.erase({dist[adjNode],adjNode});
              }
              dist[adjNode]=edgeweight+weight;
              st.insert({dist[adjNode],adjNode});
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
    vector<int> distances = object.dijkstra(V, adj, S);
    
    cout << "Shortest distances from source vertex " << S << ":\n";
    for (int i = 0; i < V; ++i) {
        cout << "Vertex " << i << ": " << distances[i] << endl;
    }
    
  
    
    return 0;
}