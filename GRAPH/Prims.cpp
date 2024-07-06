#include<bits/stdc++.h>
using namespace std;

class Solution{
  public:
  int spanningTree(int V, vector<vector<int>>adj[]){
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>p;
    
    vector<int>visited(V,0);
    p.push({0,0});
    int sum=0;
    while(!p.empty()){
      auto it=p.top();
      p.pop();
      int node=it.second;
      int wt=it.first;
      if(visited[node]==1)continue;
      visited[node]=1;
      sum+=wt;
      for(auto it:adj[node]){
          int adjNode=it[0];
          int edge=it[1];
          if(!visited[adjNode]){
            p.push({edge,adjNode});
          }
      }

    }
    return sum;
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
    
   
    Solution object;
    int minspanwt = object.spanningTree(V, adj);
    
    cout<<"The minimum spanning tree path weight is "<<minspanwt;
    
  
    
    return 0;
}