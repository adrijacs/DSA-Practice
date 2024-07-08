#include<bits/stdc++.h>
using namespace std;
class Solution{
  public:
  static int fib(int n,vector<int>&dp){
    if(n<=1){
      return n;
    }
    if(dp[n]!=-1)return dp[n];
    return dp[n]=fib(n-1,dp)+fib(n-2,dp);
  }
};

int main(){
  int n;
  cin>>n;
  vector<int>dp(n+1,-1);
  cout<<"N'th fibonacci number (0-indexed) is "<<Solution::fib(n,dp);
}