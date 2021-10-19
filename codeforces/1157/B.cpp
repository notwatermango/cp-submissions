// #include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
using namespace std;
// #define int int64_t


signed main(){
  ios_base::sync_with_stdio(false); cin.tie(0);
  int ln; cin >> ln;
  string st; cin >>st;
  int f[9];
  for (int i = 0; i < 9; i++)
  {
    cin >> f[i];
  }
  int start = 0;
  for (int i = 0; i < ln; i++)
  {
    if(st[i]-'0' < f[st[i]-'1']){
      // cout << st[i]-'0' << ' '<< f[st[i]-'1']<<'\n';
      start = i;
      break;
    }
  }
  while(st[start]-'0' <= f[st[start]-'1']){
    st[start] = char(f[st[start] - '1'] + '0');
    start++;
  }
  cout << st << '\n';
  
  
  return 0;
}