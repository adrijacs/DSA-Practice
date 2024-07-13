#include<bits/stdc++.h>
using namespace std;
class Solution{
public:
static int maxSumAlt(int index, vector<int>&arr,vector<int>&dp ){
  if(index==0)return arr[index];
  if(index<0)return 0;
  if(dp[index]!=-1)return dp[index];
  int pick=arr[index]+maxSumAlt(index-2,arr,dp);
  int nonpick=0 + maxSumAlt(index-1,arr,dp);
  return dp[index]=max(pick,nonpick);
}

};

int main(){
int n;
cin>>n;

vector<int>dp(n,-1);
vector<int>arr(n);
for(int i=0;i<n;i++){
  cin>>arr[i];
}

cout<<"Tha maximum sum of alternate subsequence is: "<<Solution::maxSumAlt(n-1,arr,dp);



}
//Tabulation and space optimisation T(C)=O(n) S(C)=O(1)
// int maximumNonAdjacentSum(vector<int> &nums){
//     // Write your code here.
//     // int n=nums.size();
//     // vector<int>dp(n,-1);
//     // return maxSum(n-1,nums,dp);
//     int prev=nums[0];
//     int prev2=0;
//     for(int i=1;i<nums.size();i++){
//         int pick=nums[i];
//         if(i>1)pick+=prev2;
//         int nonpick=0 + prev;
//         int curr=max(pick,nonpick);
//          prev2=prev;
//          prev=curr;
//     }
//     return prev;
// }