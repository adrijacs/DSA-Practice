#include<bits/stdc++.h>
using namespace std;
class Solution{
   public:
   int wordLadder(string startWord,string targetWord,vector<string>& words){
    queue<pair<string,int>> q;
    q.push({startWord,1});
    unordered_set<string>st(words.begin(),words.end());
    while(!q.empty()){
      string word=q.front().first;
      int steps=q.front().second;
      q.pop();
      if(word==targetWord) return steps;
      for(int i=0;i<word.length();i++){
        char original=word[i];
        for(char ch='a';ch<='z';ch++){
          word[i]=ch;
          if(st.find(word)!=st.end()){
            st.erase(word);
            q.push({word,steps+1});
          }
        }
        word[i]=original;
      }
    }
    return 0;

   }
};

int main(){
int n;
cin>>n;
vector<string> words(n);
for(int i=0;i<n;i++){
  cin>>words[i];
}
string startWord;
cin>>startWord;
string targetWord;
cin>>targetWord;
Solution object;
int output=object.wordLadder(startWord,targetWord,words);
cout<<"\n The  number of rearrangements to achieve the target word is : "<<output;


}