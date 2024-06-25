#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution{
  public:
  bool detectCycle( int src,vector<int> adj[],int vis[]){
    vis[src]=1;
    queue<pair<int,int>> q;
    q.push({src,-1});
    while(!q.empty()){
      int node=q.front().first;
      int parent=q.front().second;
      q.pop();
      for(int adjacent:adj[node]){
        if(!vis[adjacent]){
          vis[adjacent]=1;
          q.push({adjacent,node});
        }
        else if(parent!=adjacent){
          return true;
        }
      }
    }
    return false;
  }
  bool isCycle(int V,vector<int>adj[]){
    int vis[V]={0};
    for(int i=0;i<V;i++){
      if(!vis[i]){
           if(detectCycle(i,adj,vis)){
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