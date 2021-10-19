// #include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
// #define int int64_t
// tags: dynamic programming, ga kebayang, susah, dp


signed main(){
  ios_base::sync_with_stdio(false); cin.tie(0);
  string st; cin >> st;
  while (st[st.length()-1] == 'o') st.pop_back();
  // cout << st << '\n';
  int ln = st.length();
  int os = 0;
  int vs = 0;
  vector<int> v;
  for (int i = 0; i < ln; i++)
  {
    if(st[i] == 'v'){
      if(os){
        if(!v.empty()){
          if(vs && v.size() % 2 == 1){
            v.push_back(os);
            os = 0;
          } 
        }
      }
      vs++;
    } else{
      if(vs){
        if(vs > 1){
          v.push_back(vs);
        }
        vs = 0;
      }
      if(!v.empty()) os++;
    }
  }
  if(vs > 1){
    v.push_back(vs);
    vs = 0;
  }
  // for(auto &e: v){
  //   cout << e <<' ';
  // }
  long long res = 0;
  long long ws = 0;
  long long zs = 0;
  for (int i = 0; i < v.size(); i++)
  {
    if(i % 2 == 0){
      ws += v[i]-1;
      res += zs*(v[i]-1);
    } else {
      zs += ws*v[i];
    }
  }
  cout << res << '\n';
  

  return 0;
}