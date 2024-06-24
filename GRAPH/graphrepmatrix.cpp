#include<iostream>
using namespace std;

int main(){
  int n,m;
  cout<<"Enter the number of nodes";
  cin>>n;
  cout<<"Enter the number of edges";
  cin>>m;
  int adj[n+1][n+1];
  //storing the graph         // 1 2, 1 3, 3 4, 2 4, 2 5, 4 5
  for(int i=0;i<m;i++){
    int u,v; 
    cout<<"Enter first node";
    cin>>u;
    cout<<"Enter second node";
    cin>>v;
    adj[u][v]=1;
    adj[v][u]=1;
  }
  //displaying the graph
  for(int i=1;i<n+1;i++){
    for(int j=1;j<n+1;j++){
      if(adj[i][j]==1){
        cout<<adj[i][j]<<" ";
      }
      else{
        cout<<"0"<<" ";
      }
    }
    cout<<endl;
  }
}