#include<bits/stdc++.h>
using namespace std;

class DisjointSet{
  vector<int>rank,parent,size;
  public:
  DisjointSet(int n){
    rank.resize(n+1,0);
    parent.resize(n+1);
    size.resize(n+1);
    for(int i=0;i<=n;i++){
      parent [i]=i;
      size[i]=1;
    }
  }
  int findUPar(int node){
    if(node==parent[node]){
      return node;
    }
    return parent[node]=findUPar(parent[node]);
  }
  void unionByRank(int u, int v){
    int ulp_u=findUPar(u);
    int ulp_v=findUPar(v);
    if(ulp_u==ulp_v)return;
    if(rank[ulp_u]<rank[ulp_v]){
      parent[ulp_u]=ulp_v;
    }
    else if(rank[ulp_v]<rank[ulp_u]){
        parent[ulp_v]=ulp_u;
    }
    else{
      parent[ulp_v]=ulp_u;
      rank[ulp_u]++;
    }
  }
  void unionBySize(int u, int v){
    int ulp_u=findUPar(u);
    int ulp_v=findUPar(v);
    if(ulp_u==ulp_v)return;
     if(size[ulp_u]<size[ulp_v]){
      parent[ulp_u]=ulp_v;
      size[ulp_v]+=size[ulp_u];
    }
    else{
        parent[ulp_v]=ulp_u;
        size[ulp_u]+=size[ulp_v];
    }
    
    
  }
};


class Solution{
   public:
   int spanningTree(int V, vector<vector<int>>adj[]){
    vector<pair<int,pair<int,int>>> edges;
    for(int i=0;i<V;i++){
      for(auto it:adj[i]){
        int node=i;
        int adjNode=it[0];
        int wt=it[1];
        edges.push_back({wt,{node,adjNode}});
      }
    }
    DisjointSet ds(V);
    sort(edges.begin(),edges.end());
    int mstWt=0;
    for(auto it:edges){
      int weight=it.first;
      int u=it.second.first;
      int v=it.second.second;
      if(ds.findUPar(u)!=ds.findUPar(v)){
        mstWt+=weight;
        ds.unionByRank(u,v);
      }
    }
    return mstWt;
   }
};

int main()
{
   
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
           
            adj[u].push_back({v,w});
           
            adj[v].push_back({u,w});
        }
        
  Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    

    return 0;
}