// #include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
using namespace std;
#define int int64_t


signed main(){
  ios_base::sync_with_stdio(false); cin.tie(0);
  int ln; cin >> ln;
  string st; cin >> st;
  char fs = st[0];
  char ls = st[ln-1];
  int ctf = 0;
  int ctl = 0;
  for (int i = 0; st[i] == fs ; i++)
  {
    ctf++;
  }
  for (int i = ln-1; st[i] == ls; i--)
  {
    ctl++;
  }
  if(fs != ls){
    cout << 1 + ctf + ctl << '\n';
    return 0;
  }
  int res = 1+ctf+ctl;
  res += ctf*ctl;
  res %= 998244353;
  cout << res << '\n';
  
  
  return 0;
}