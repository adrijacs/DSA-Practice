#include<bits/stdc++.h>
using namespace std;
class Solution{
public:
static int frogjump(int index, vector<int>&height,vector<int>&dp){
  if(index==0) return 0;
  if(dp[index]!=-1)return dp[index];
  int left=frogjump(index-1,height,dp) + abs(height[index-1]-height[index]);
  int right=INT_MAX;
  if(index>1){
     right=frogjump(index-2,height,dp) + abs(height[index-2]-height[index]);
  }
  return dp[index]=min(left,right);

}

};

int main(){
int n;
cin>>n;
vector<int>dp(n+1,-1);
vector<int>height(n);
for(int i=0;i<n;i++){
  cin>>height[i];
}

cout<<"The minimum amount of energy required is "<<Solution::frogjump(n-1,height,dp);



}