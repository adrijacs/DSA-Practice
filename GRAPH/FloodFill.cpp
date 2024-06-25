#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void bfs(vector<vector<int>>& image, int sr, int sc, int newColor) {
       int n=image.size();
       int m=image[0].size();
       vector<vector<int>>visited(n,vector<int>(m,0));
       queue <pair<int,int>> q;
       q.push({sr,sc});
       visited[sr][sc]=1;
       int originalColor=image[sr][sc];
       if(originalColor==newColor) return;
       image[sr][sc]=newColor;
       
       int delrow[4]={-1,1,0,0};
       int delcol[4]={0,0,-1,1};
       while(!q.empty()){
        int row=q.front().first;
        int col=q.front().second;
        q.pop();
        for( int i=0;i<4; i++){
          int nrow=row+delrow[i];
          int ncol=col+delcol[i];
          if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && image[nrow][ncol]==originalColor && !visited[nrow][ncol]){
            image[nrow][ncol]=newColor;
            visited[nrow][ncol]=1;
            q.push({nrow,ncol});
          }
        }

       }

        
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        bfs(image, sr, sc, newColor);
        return image;
    }
};

int main() {
   
   
        int n, m;
        cin >> n >> m;
        vector<vector<int>> image(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
                cin >> image[i][j];
        }
        int sr, sc, newColor;
        cin >> sr >> sc >> newColor;
        Solution obj;
        cout<<endl;
        vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
        for (auto i : ans) {
            for (auto j : i)
                cout << j << " ";
            cout << "\n";
        }
    
    return 0;
}
