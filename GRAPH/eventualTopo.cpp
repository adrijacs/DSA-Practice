#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;


class Solution{
  public:
  vector<int> eventualSafeNode(int V,vector<int>adj[]){
    vector<int>adjRev[V];
    int indegree[V]={0};
    vector<int>sortSafe;
    for(int i=0;i<V;i++){
      for(auto it:adj[i]){
         adjRev[it].push_back(i);
         indegree[i]++;
      }
    }
    queue<int>q;
    for(int i=0;i<V;i++){
      if(indegree[i]==0){
        q.push(i);
      }
    }

    while(!q.empty()){
      int node=q.front();
      q.pop();
      sortSafe.push_back(node);
      for(auto it:adjRev[node]){
        indegree[it]--;
        if(indegree[it]==0){
          q.push(it);
        }
      }
    }
    sort(sortSafe.begin(),sortSafe.end());
    return sortSafe;
   }
};

int main(){
  int n,m;
  cin>>n>>m;
  vector<int>adj[n];

  
  for(int i=0;i<m;i++){
    int u,v;             
    cout<<"Enter first node";
    cin>>u;
    cout<<"Enter second node";
    cin>>v;
    adj[u].push_back(v);
  }
  Solution object;
  vector<int>safeStates=object.eventualSafeNode(n,adj);
  cout<<"The safe states are :"<<endl;
  for(int item:safeStates){
    cout<<item<<" ";
  }

}