#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution{
  public:
  bool detectCycle( int src,vector<int> adj[],int vis[],int path[]){
    vis[src]=1;
    path[src]=1;
    
    for(auto it:adj[src]){
      if(!vis[it]){
         if(detectCycle(it,adj,vis,path)==true){
          return true;
         }
      }
      else if(path[it]==1){
        return true;
      }
    }
    path[src]=0;
    return false;
  }
  bool isCycle(int V,vector<int>adj[]){
    int vis[V]={0};
    int pathVis[V]={0};
    for(int i=0;i<V;i++){
      if(!vis[i]){
           if(detectCycle(i,adj,vis,pathVis)){
                return true;
         }
      }
    }
    return false;
  }
};

int main(){
  int n,m;
  cin>>n>>m;
  vector<int>adj[n];

  vector<int>list;
  //storing the graph
  for(int i=0;i<m;i++){
    int u,v;             
    cout<<"Enter first node";
    cin>>u;
    cout<<"Enter second node";
    cin>>v;
    adj[u].push_back(v);
  }
  Solution object;
  cout<<endl<<"Is there cycle in the graph? "<<((object.isCycle(n, adj) == 1) ? "yes" : "no");

}