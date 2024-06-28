#include<iostream>
#include<stack>
#include<vector>
using namespace std;

class Solution{
private:
void dfs(int node,int visited[],vector<int>adj[],stack<int>&st){
visited[node]=1;
for(auto it:adj[node]){
  if(!visited[it]){
    dfs(it,visited,adj,st);
  }

}
 st.push(node);
}
public:
vector<int>topoSort(int V,vector<int>adj[]){
int visited[V]={0};
stack<int>st;
vector<int>ans;
for(int i=0;i<V;i++){
  if(!visited[i]){
    dfs(i,visited,adj,st);
  }
  
}

while(!st.empty()){
   ans.push_back(st.top());
   st.pop();
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
  list=object.topoSort(n,adj);
  cout<<"Topological Sort : "<<endl;
  for(auto item:list){
    cout<<item<<" ";
  }

}