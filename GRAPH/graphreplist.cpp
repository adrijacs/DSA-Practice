#include<iostream>
#include<vector>
using namespace std;

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
}