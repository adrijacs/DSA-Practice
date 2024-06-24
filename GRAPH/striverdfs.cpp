#include<iostream>
#include<vector>
using namespace std;

void dfs(int node,vector<int>adj[],int vis[],vector<int>&list){
 vis[node]=1;
 list.push_back(node);
 for(auto it:adj[node]){
  if(!vis[it]){
    vis[it]=1;
    dfs(it,adj,vis,list);
  }
 }
}

int main(){
  int n,m;
  cout<<"Enter the number of nodes";
  cin>>n;
  cout<<"Enter the number of edges";
  cin>>m;
  vector<int>adj[n+1];
  int vis[n+1]={0};
  int start=1;
  vector<int>list;
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
  dfs(start,adj,vis,list);
  cout<<"The dfs traversal of the graph looks like.."<<endl;
  for(auto it:list){
    cout<<it<<" ";    //8 8 1 2 1 3 2 5 2 6 3 4 3 7 4 8 7 8 
  }
}