#include<iostream>
#include<vector>
#include <queue>

using namespace std;

void bfs(int n, vector<int>adj[]){
    int vis[n+1]={0};
    vis[6]=1;
    queue <int> q;
    q.push(6);
    vector<int> bfs;
    while(!q.empty()){
      int node=q.front();
      q.pop();                                 // 9 9 1 2 1 6 2 3 2 4 4 5 5 8 6 7 6 9 7 8
      bfs.push_back(node);
      for(auto item:adj[node]){
        if(!vis[item]){
          vis[item]=1;
          q.push(item);
        }
      }
    }
    cout<<"The BFS traversal looks like: ";
    for(auto item:bfs){
      cout<<item<<" ";
    }
}

int main(){
  int n,m;
  cout<<"Enter the number of nodes";
  cin>>n;
  cout<<"Enter the number of edges";
  cin>>m;
  vector<int>adj[n+1];
  //storing the graph
  for(int i=0;i<m;i++){
    int u,v;              // 1 2, 1 3, 3 4, 2 4, 2 5, 4 5
    cout<<"Enter first node";
    cin>>u;
    cout<<"Enter second node";
    cin>>v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  //displaying the graph
  for(int i=1;i<n+1;i++){
    cout<<i<<":";
    for(int neighbour:adj[i]){
      cout<<neighbour<<" ";
    }
    cout<<endl;
  }
  bfs(n,adj);
}