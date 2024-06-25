#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numOftime(vector<vector<int>>& grid) {
      int n=grid.size();
      int m=grid[0].size();
      int cntFresh=0;
      vector<vector<int>>visited(n,vector<int>(m,0));
      queue<pair<pair<int,int>,int>> q;
      for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
          if(grid[i][j]==2){
            q.push({{i,j},0});
            visited[i][j]=2;
          }
          else if(grid[i][j]==1){
            cntFresh++;
          }
        }
      }
      int tm=0;
      int drow[]={-1,0,1,0};
      int dcol[]={0,1,0,-1};
      int cntRot=0;
      while(!q.empty()){
        int r=q.front().first.first;
        int c=q.front().first.second;
        int t=q.front().second;
        tm=max(tm,t);
        q.pop();
        for(int i=0;i<4;i++){
          int nrow=r+drow[i];
          int ncol=c+dcol[i];
          if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && visited[nrow][ncol] ==0 && grid[nrow][ncol]==1){
            q.push({{nrow,ncol},t+1});
            visited[nrow][ncol]=2;
            cntRot++;
          }
        }
      }
      
      if (cntRot!=cntFresh) return -1;
      return tm;

    }

        
    

    void rottenOranges(vector<vector<int>>& grid) {
        cout<<"Time required to rot all fresh oranges :"<<numOftime(grid);
        
    }
};

int main() {
   
   
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
                cin >> grid[i][j];
        }
      
        Solution obj;
        obj.rottenOranges(grid);
        cout<<endl;
        
    
    return 0;
}
