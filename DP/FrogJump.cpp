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
//Tabulation code
// int f(int n,vector<int>&dp,vector<int>&heights){
//     dp[0]=0;
//     for(int i=1;i<n;i++){
//        int left=dp[i-1] + abs(heights[i-1]-heights[i]);
//        int right=INT_MAX;
//        if(i>1){
//            right=dp[i-2]+abs(heights[i-2]-heights[i]);
//        }
//        dp[i]=min(left,right);
//     }
//     return dp[n-1];
// }


// int frogJump(int n, vector<int> &heights)
// {
//     // Write your code here.
//     if(n==0)return 0;
//     vector<int>dp(n,-1);
//     return f(n,dp,heights);
// }