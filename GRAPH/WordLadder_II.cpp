#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
vector<vector<string>> wordLadder(string beginWord, string targetWord,vector<string>&wordList){
unordered_set<string>st(wordList.begin(),wordList.end());
queue<vector<string>> q;
q.push({beginWord});
vector<string>usedWord;
usedWord.push_back(beginWord);
vector<vector<string>>ans;
int level=0;

while(!q.empty()){
vector<string> vec=q.front();
q.pop();
if(vec.size()>level){
   level++;
   for(auto item:usedWord){
    st.erase(item);
   }
   usedWord.clear();
}
string word=vec.back();
if(word==targetWord){
  if(ans.size()==0){
    ans.push_back(vec);
  }
  else if(ans[0].size()==vec.size()){
    ans.push_back(vec);
  }
}

for(int i=0;i<word.length();i++){
  char original=word[i];
  for(char ch='a';ch<='z';ch++){
     word[i]=ch;
     if(st.count(word)>0){
        vec.push_back(word);
        q.push(vec);
        usedWord.push_back(word);
        vec.pop_back();
     }
 
  }
  word[i]=original;
}

}
return ans;
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
vector<vector<string>> output=object.wordLadder(startWord,targetWord,words);
for(auto item:output){
  cout<<"\n";
  for(auto it:item){
    cout<<it<<" ";
  }
  cout<<endl;
}


}