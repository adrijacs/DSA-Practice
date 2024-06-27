#include<iostream>
#include<vector>
using namespace std;

class Solution{
  public:
  bool detectCycle( int src,vector<int> adj[],int vis[],int path[],int check[]){
    vis[src]=1;
    path[src]=1;
    check[src]=0;
    for(auto it:adj[src]){
      if(!vis[it]){
         if(detectCycle(it,adj,vis,path,check)==true){
          check[src]=0;
          return true;
         }
      }
      else if(path[it]==1){
        check[src]=0;
        return true;
      }
    }
    check[src]=1;
    path[src]=0;
    return false;
  }
  vector<int> eventualSafe(int V,vector<int>adj[]){
    int vis[V]={0};
    int pathVis[V]={0};
    int check[V]={0};
    vector<int>safeStates;
    for(int i=0;i<V;i++){
      if(!vis[i]){
          detectCycle(i,adj,vis,pathVis,check);
         }
      }
     for(int i=0;i<V;i++){
      if(check[i]==1){
        safeStates.push_back(i);
      }
     }
     return safeStates;
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
  vector<int>safeStates=object.eventualSafe(n,adj);
  cout<<"The safe states are :"<<endl;
  for(int item:safeStates){
    cout<<item<<" ";
  }

}