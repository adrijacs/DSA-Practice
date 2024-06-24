#include<iostream>
#include<vector>
#include<queue>
using namespace std;
void bfs(int row,int col, vector<vector<int>>&vis,vector<vector<char>>&grid){
 vis[row][col]=1;
 queue <pair<int,int>> q;
 q.push({row,col});
 int n=grid.size();
 int m=grid[0].size();
 while(!q.empty()){
  int row=q.front().first;
  int col=q.front().second;
  q.pop();
  for(int delrow=-1;delrow<=1;delrow++){
    for(int delcol=-1;delcol<=1;delcol++){
      int nrow=row+delrow;
      int ncol=col+delcol;
      if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]=='1' && !vis[nrow][ncol]){
        vis[nrow][ncol]=1;
        q.push({nrow,ncol});
      }
    }
  }
 }

}
int numOfInslands(vector<vector<char>>&grid){
  int cnt=0;
  int n=grid.size();
  int m=grid[0].size();
  vector<vector<int>>visited(n,vector<int>(m));
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      if(!visited[i][j] && grid[i][j]=='1'){
        cnt++;
        bfs(i,j,visited,grid);
      }
    }
  }
  return cnt;
}
int main(){
  int n,m;
  cout<<"Enter the number of rows:";
  cin>>n;
  cout<<"Enter the number of columns:";
  cin>>m;

  vector<vector<char>>grid(n,vector<char>(m));
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      cin>>grid[i][j];
    }
  }

    for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      cout<<grid[i][j]<<" ";
    }
    cout<<endl;
  }
   cout<<endl<<"Number of Islands are "<<numOfInslands(grid);
}
