// #include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
using namespace std;
// #define int int64_t


signed main(){
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n,q;
  cin >> n >> q;
  int a,b;
  for (int i = 0; i < q; i++)
  {
    cin >> a >> b;
  }
  for (int i = 0; i < n; i++)
  {
    if(i%2 == 0) cout <<'1';
    else cout << '0';
  }
  cout << '\n';
  
  return 0;
}