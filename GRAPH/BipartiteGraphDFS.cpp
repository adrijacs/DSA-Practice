#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution{
  public:
   bool check(int start, int V, vector<int>adj[],vector<int>&color){
  
    color[start]=0;
    for(int node:adj[start]){
      if(color[node]==-1){
        color[node]=!color[start];
      }
      else if(color[node]==color[start]){
        return false;
      }
    }
    return true;
   }

   bool isBipartite(int V,vector<int>adj[]){
    vector<int>color(V,-1);
    for(int i=0;i<V;i++){
      if(color[i]==-1){
        if(check(i,V,adj,color)==false){
          return false;
        }
      }
    }
    return true;
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
  cout<<endl<<"Is this a bipartite graph?"<<((object.isBipartite(n, adj) == 1) ? "yes" : "no");

}