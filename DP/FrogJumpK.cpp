#include<bits/stdc++.h>
using namespace std;
class Solution{
public:
static int frogjump(int index, vector<int>&height,vector<int>&dp,int k){
  if(index==0) return 0;
  if(dp[index]!=-1)return dp[index];
  int minsteps=INT_MAX;
  for(int j=1;j<=k;j++){
    if(index-j>=0){
    int jump=frogjump(index-j,height,dp,k) + abs(height[index-j]-height[index]);
    minsteps=min(minsteps,jump);
    }
  }
   return dp[index]=minsteps;
}

};

int main(){
int n;
cin>>n;
int k;
cin>>k;
vector<int>dp(n,-1);
vector<int>height(n);
for(int i=0;i<n;i++){
  cin>>height[i];
}

cout<<"The minimum amount of energy required is "<<Solution::frogjump(n-1,height,dp,k);



}