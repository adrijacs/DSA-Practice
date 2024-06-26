#include<iostream>
#include<vector>
using namespace std;

class Solution{
  public:
  void dfs(int sr, int sc,vector<vector<int>>&visited,vector<vector<char>>&origin,int delrow[],int delcol[]){
    visited[sr][sc]=1;
    int n=origin.size();
    int m=origin[0].size();
    for(int i=0;i<4;i++){
      int nrow=sr + delrow[i];
      int ncol=sc+delcol[i];
      if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !visited[nrow][ncol] && origin[nrow][ncol]=='O'){
        dfs(nrow,ncol,visited,origin,delrow,delcol);
      }
    }
  }
  void replacedMatrix(int n, int m, vector<vector<char>>&origin){
    vector<vector<int>>visited(n,vector<int>(m,0));
    int delrow[]={-1,0,1,0};
    int delcol[]={0,1,0,-1};
    for(int j=0;j<m;j++){
      if(!visited[0][j] && origin[0][j]=='O'){
        dfs(0,j,visited,origin,delrow,delcol);
      }
      if(!visited[n-1][j] && origin[n-1][j]=='O'){
        dfs(n-1,j,visited,origin,delrow,delcol);
      }
    }
    for(int i=0;i<n;i++){
      if(!visited[i][0] && origin[i][0]=='O'){
        dfs(i,0,visited,origin,delrow,delcol);
      }
      if(!visited[i][m-1] && origin[i][m-1]=='O'){
        dfs(i,m-1,visited,origin,delrow,delcol);
      }
    }
    for(int i=0;i<n;i++){
      for(int j=0;j<m;j++){
        if(!visited[i][j] && origin[i][j]=='O'){
          origin[i][j]='X';
        }
      }
    }
   }
};

int main(){
  int n, m;
  cin>>n>>m;

  vector<vector<char>>origin_matrix(n,vector<char>(m));
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      cin>>origin_matrix[i][j];
    }
  }

  Solution obj;
  obj.replacedMatrix(n,m,origin_matrix);

   for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      cout<<origin_matrix[i][j]<<" ";
    }
    cout<<endl;
  }
}