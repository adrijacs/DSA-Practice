#include<bits/stdc++.h>
using namespace std;
class Solution{
  public:
  static int fib(int n){
   int prev2=0;
   int prev=1;
   if(n==1){
    return 1;
   }
   else if(n==0){
    return 0;
   }
   for(int i=2;i<=n;i++){
     int curr=prev2+prev;
     prev2=prev;
     prev=curr;
   }
   return prev;
}};

int main(){
  int n;
  cin>>n;
  
  cout<<"N'th fibonacci number (0-indexed) is "<<Solution::fib(n);
}