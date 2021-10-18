#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
using namespace std;
// #define int int64_t


signed main(){
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n,m,k;
  cin >> n >> m >> k;
  vector<pair<int, pair<int,int>>> ed;
  int from, to, weight;
  while (m--)
  {
    cin >> from >> to >> weight;
    ed.push_back({weight, {from, to}});
  }
  sort(ed.begin(),ed.end());
  set<int> sz;
  while (k--)
  {
    cin >> from;
    sz.insert(from);
  }
  int res = -1;
  for(auto &e: ed){
    bool a = sz.count(e.second.first);
    bool b = sz.count(e.second.second);
    if((a && b) || (!a && !b)) continue;
    res = e.first;
    break;
  }
  cout << res << '\n';
  
  
  return 0;
}