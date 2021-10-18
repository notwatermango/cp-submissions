// #include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
using namespace std;
// #define int int64_t


signed main(){
  ios_base::sync_with_stdio(false); cin.tie(0);
  int q;
  cin >> q;
  int a;
  string dir;
  int pos = 0;
  bool bad = false;
  while(q--){
    cin >> a >> dir;
    if(dir == "South"){
      if(pos == 20000) bad = true;
      pos+=a;
    } else if(dir == "North"){
      if(pos == 0) bad = true;
      pos-=a;
    } else {
      if(pos == 0 || pos == 20000){
        bad = true;
      }
    }
    if(pos < 0 || pos > 20000){
      bad = true;
    }
  }
  if(pos != 0) bad = true;
  if(bad){
    cout << "NO\n";
  } else cout << "YES\n";
  return 0;
}