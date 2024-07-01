#include<iostream>
#include<vector>
#include<stack>
#include <climits>
using namespace std;
class Solution {
  private:
      void dfs(int node, vector<int>& visited, vector<pair<int,int>> adj[], stack<int>& st) {
        visited[node] = 1;
        for (auto it : adj[node]) {
            if (!visited[it.first]) {
                dfs(it.first, visited, adj, st);
            }
        }
        st.push(node);
    }

  public:
     vector<int> shortestPath(int N, int M, vector<vector<int>>& edges) {
        vector<pair<int, int>> adj[N];
        
        for (int i = 0; i < M; i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            adj[u].push_back({v, wt});
        }
        
        stack<int> st;
        vector<int> visited(N, 0);
        
        for (int i = 0; i < N; i++) {
            if (!visited[i]) {
                dfs(i, visited, adj, st);
            }
        }
        
        vector<int> dist(N, INT_MAX);
        dist[0] = 0;
        
        while (!st.empty()) {
            int node = st.top();
            st.pop();
            
            if (dist[node] != INT_MAX) { 
                for (auto it : adj[node]) {
                    int nextNode = it.first;
                    int weight = it.second;
                    if (dist[node] + weight < dist[nextNode]) {
                        dist[nextNode] = dist[node] + weight;
                    }
                }
            }
        }
        
        for (int i = 0; i < N; i++) {
            if (dist[i] == INT_MAX) {
                dist[i] = -1;
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
            vector<int> temp(3);
            for (int j = 0; j < 3; ++j) {
                cin >> temp[j];
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    
    return 0;
}