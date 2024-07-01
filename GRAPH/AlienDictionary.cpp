#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class Solution{
  private:
  vector<int>topoSort(vector<int>adj[],int V){
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
  public:
  string alienDictionary(int K,int N,string dict[]){
    vector<int>order[K];
    for(int i=0;i<N-1;i++){
      string s1=dict[i];
      string s2=dict[i+1];
      int len=min(s1.size(),s2.size());
      for(int pt=0;pt<len;pt++){
        if(s1[pt]!=s2[pt]){
          order[s1[pt]-'a'].push_back(s2[pt]-'a');
          break;
        }
      }
    }
    vector<int>topo=topoSort(order,K);
    string ans="";
    for(auto item:topo){
      ans+=item+'a';
    }
    return ans;
  }
   
};

int main(){
int n,k;
cin>>n>>k;
string dict[n];
for(int i=0;i<n;i++){
  cin>>dict[i];
}
string ans="bdac";
Solution object;
string output=object.alienDictionary(k,n,dict);
cout<<"The order of characters in the alien dictionary is: \n"<<object.alienDictionary(k,n,dict);

cout<<"\nis the order correct?\n"<<(((ans==output)?"Yes":"No"));

}