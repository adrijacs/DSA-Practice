#include<bits/stdc++.h>
using namespace std;

class Solution{
  public:
   void floydwarshall(vector<vector<int>>&adj){
    int n=adj[0].size();
    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
        if(adj[i][j]==-1){
          adj[i][j]=1e8;
        }
        if(i==j)adj[i][j]=0;
      }
    }

    for(int k=0;k<n;k++){
      for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
          adj[i][j]=min(adj[i][k]+adj[k][j],adj[i][j]);
        }
      }
    }
     for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
        if(adj[i][j]==1e8){
          adj[i][j]=-1;
        }
      }
    }


   }
   
};





int main() {
    int N;
    cout << "Enter the number of vertices and edges: ";
    cin >>N;
    
    vector<vector<int>> adj;
    
    cout << "Enter the edges (source, destination, weight) one by one:\n";
    for (int i = 0; i < N; i++) {
       vector<int>item;
       for(int j=0;j<N;j++){
        int it;
        cin>>it;
        item.push_back(it);
       }
       adj.push_back(item);
    }
    
 
    Solution object;
     object.floydwarshall( adj);
    
    cout<<endl<<"After calculating the floyd warshall distance"<<endl;
    
       for (int i = 0; i < N; i++) {
     
       for(int j=0;j<N;j++){
         cout<<adj[i][j]<<" ";
       }
     cout<<endl;
    }

  
    
    return 0;
}