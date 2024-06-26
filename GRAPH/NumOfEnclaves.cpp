#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution{
  public:
  int numOfEnclaves(vector<vector<int>>&matrix, int n, int m){
    vector<vector<int>>visited(n,vector<int>(m,0));
    queue<pair<int,int>>q;
    for(int j=0;j<m;j++){
      if(matrix[0][j]==1){
        visited[0][j]=1;
        q.push({0,j});
      }
      if(matrix[n-1][j]==1){
        visited[n-1][j]=1;
        q.push({n-1,j});
      }
    }

    for(int i=0;i<n;i++){
      if(matrix[i][0]==1){
        visited[i][0]=1;
        q.push({i,0});
      }
      if(matrix[i][m-1]==1){
        visited[i][m-1]=1;
        q.push({i,m-1});
      }
    }
    int delrow[4]={-1,0,1,0};
    int delcol[4]={0,1,0,-1};

    while(!q.empty()){
      int row=q.front().first;
      int col=q.front().second;
      q.pop();
      for(int i=0;i<4;i++){
        int nrow=row+delrow[i];
        int ncol=col+delcol[i];
        if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !visited[nrow][ncol] && matrix[nrow][ncol]==1){
          q.push({nrow,ncol});
          visited[nrow][ncol]=1;
        }
      }
    }
    int cnt=0;
    for(int i=0;i<n;i++){
      for(int j=0;j<m;j++){
        if(!visited[i][j] && matrix[i][j]==1){
          cnt++;
        }
      }
    } 
    return cnt;

  }

};

int main(){
  int n, m;
  cin>>n>>m;

  vector<vector<int>>origin_matrix(n,vector<int>(m));
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      cin>>origin_matrix[i][j];
    }
  }

  Solution obj;
  cout<<"The number of enclaves are :"<<obj.numOfEnclaves(origin_matrix,n,m);
  return 0;
}