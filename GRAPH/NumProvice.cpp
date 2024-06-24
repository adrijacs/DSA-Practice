#include<iostream>
#include<vector>
using namespace std;

void dfs(int node, vector<int>adjL[],int visited[]){
    visited[node]=1;
    for(auto item:adjL[node]){
       if(!visited[item]){
        visited[item]=1;
        dfs(item,adjL,visited);
       }
    }
    
}
int numOfProvinces(vector<vector<int>>&input,int V){
   vector<int>adjL[V];
   for(int i=0;i<V;i++){
    for(int j=0;j<V;j++){
      if(input[i][j]==1 && i!=j){
        adjL[i].push_back(j);
        adjL[j].push_back(i);
      }
    }
   }
   int visited[V]={0};
   int cnt=0;
   for(int i=0;i<V;i++){
      if(!visited[i]){
        cnt++;
        dfs(i,adjL,visited);
      }
   }
   cout<<"The number of provinces are : "<<cnt;
}
int main(){
  int n;
  cout<<"Enter the number of nodes";
  cin>>n;
  vector<vector<int>>input(n,vector<int>(n));
  cout<<"Enter the matrix"<<endl;
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      cout<<"Enter the element";
      cin>>input[i][j];
    }
  }
  cout<<"The matrix is:"<<endl;
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      cout<<input[i][j]<<" ";
      
    }
    cout<<endl;
  }
   numOfProvinces(input,n);
}