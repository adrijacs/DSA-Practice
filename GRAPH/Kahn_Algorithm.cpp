#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class Solution{
public:
vector<int>kahnSort(vector<int>adj[],int V){
  queue<int>q;
  vector<int>ans;
  int indegree[V]={0};
for(int i=0;i<V;i++){
    for(auto it:adj[i]){
      indegree[it]++;
    }
  }
for(int i=0;i<V;i++){
    if(indegree[i]==0){
      q.push(i);
    }
}
  while(!q.empty()){
    int node=q.front();
    q.pop();
    for(auto it:adj[node]){
      indegree[it]--;
      if(indegree[it]==0){
        q.push(it);
      }
    }
    ans.push_back(node);
}
  return ans;
}
};


int main(){
  int n,m;
  cin>>m>>n;
  vector<int>adj[n];

  vector<int>list;
  //storing the graph
  for(int i=0;i<m;i++){
    int u,v;             
    cout<<"Enter first node";
    cin>>u;
    cout<<"Enter second node";
    cin>>v;
    adj[u].push_back(v);
  }
  Solution object;
  list=object.kahnSort(adj,n);
  cout<<"Topological Sort : "<<endl;
  for(auto item:list){
    cout<<item<<" ";
  }

}