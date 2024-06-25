#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution{
  public:
  bool detectCycle( int node,int parent,vector<int> adj[],int vis[]){
    vis[node]=1;
    for(auto adjacent:adj[node]){
      if(!vis[adjacent]){
        if(detectCycle(adjacent,node,adj,vis)==true){
          return true;
        }
      }
      else if(adjacent!=parent){
        return true;
      }
    }
    
    return false;
  }
  bool isCycle(int V,vector<int>adj[]){
    int vis[V]={0};
    for(int i=0;i<V;i++){
      if(!vis[i]){
           if(detectCycle(i,-1,adj,vis)==true){
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
    adj[v].push_back(u);
  }
  Solution object;
  cout<<endl<<"Is there cycle in the graph? "<<((object.isCycle(n, adj) == 1) ? "yes" : "no");

}