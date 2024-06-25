#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution{
  public:
  vector<vector<int>>nearest(vector<vector<int>>grid){
    int n=grid.size();
    int m=grid[0].size();
    vector<vector<int>>visited(n,vector<int>(m,0));
    vector<vector<int>>distance(n,vector<int>(m,0));
    queue<pair<pair<int,int>,int>> q;
    for(int i=0; i<n;i++){
      for(int j=0;j<m;j++){
          if(grid[i][j]==1){
            q.push({{i,j},0});
            visited[i][j]=1;
          }
      }
    }

    int delrow[]={-1,0,1,0};
    int delcol[]={0,1,0,-1};
    while(!q.empty()){
      int row=q.front().first.first;
      int col=q.front().first.second;
      int stepsize=q.front().second;
      distance[row][col]=stepsize;
      q.pop();
      for(int i=0;i<4;i++){
        int nrow=row+delrow[i];
        int ncol=col+delcol[i];
        if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !visited[nrow][ncol]){
          visited[nrow][ncol]=1;
          
          q.push({{nrow,ncol},stepsize+1});
        }
      }

    }
    return distance;
}
};

int main(){
  int n,m;
  cin>>n>>m;
  vector<vector<int>>adj(n,vector<int>(m));

  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      cin>>adj[i][j];
    }
  }
  Solution object;
  vector<vector<int>>distance=object.nearest(adj);
  
  cout<<endl;
   for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      cout<<distance[i][j]<<" ";
    }
    cout<<endl;
  }
  

}