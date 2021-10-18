#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
using namespace std;
// #define int int64_t


signed main(){
  ios_base::sync_with_stdio(false); cin.tie(0);
  string s;
  cin >> s;
  string res = "-1\n";
  if(s.length() < 26){
    cout << res;
    return 0;
  }
  bool ok = false;
  for (int i = 0; i < s.length()-25; i++)
  {
    set<char> sett;
    int ques = 0;
    for (int j = i; j < i+26; j++)
    {
      if(s[j] == '?') {
        ques++; 
        continue;
      }
      sett.insert(s[j]);
    }
    // cout << ques << ' ' << sett.size();
    if(26-(int)sett.size() > ques){
      continue;
    }
    vector<char> qq;
    for(int j = 0; j < 26; ++j){
      if(!sett.count(j+'A')){
        qq.push_back(j+'A');
      }
    }
    for(auto &e: qq){
      for (int j = i; j < i+26; j++)
      {
        if(s[j] == '?'){
          s[j] = e;
          break;
        }
      }
    }
    ok = true;
    break;
  }
  
  if(ok){
    for (int i = 0; i < int(s.length()); i++)
    {
      if(s[i] == '?') s[i] = 'M';
    }
    cout << s << '\n';
  } else{
    
    cout << res;
  }
  


  
  
  return 0;
}