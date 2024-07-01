#include<iostream>
#include<vector>
#include<queue>
#include <climits>
using namespace std;
class Solution {
  private:

  public:
     vector<int> shortestPath(vector<vector<int>>& edges,int N,int M,int src) {
      vector<int>adj[N];
      for(auto it:edges){
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
      }
      vector<int>dist(N,INT_MAX);
      dist[src]=0;
      queue<int> q;
      q.push(src);
      while(!q.empty()){
        int node=q.front();
        q.pop();
        if(dist[node]!=INT_MAX){
          for(auto item:adj[node]){
            if(dist[node]+1<dist[item]){
              dist[item]=dist[node]+1;
              q.push(item);
            }
          }
        }
      }
      for(int i=0;i<N;i++){
        if(dist[i]==INT_MAX){
          dist[i]=-1;
        }
      }
      return dist;
    }
};

int main() {
    
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for (int i = 0; i < m; ++i) {
            vector<int> temp(2);
            for (int j = 0; j < 2; ++j) {
                cin >> temp[j];
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(edges, n, m,0);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    
    return 0;
}