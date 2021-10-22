// #include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

#define int int64_t
#define MOD 1000000007
#define LLINF 4154118101919364364
#define INF 1072114514

void solve();

signed main(){
  ios_base::sync_with_stdio(false); cin.tie(0);
  int tc = 1;
  cin >> tc;
  for(int i = 0; i < tc; ++i) {
    solve();
  }
  
  return 0;
}

void solve(){
  int n,x;
  cin >> n >> x;
  int a;
  int mx = 0;
  bool ok = false;
  for (int i = 0; i < n; i++)
  {
    cin >> a;
    if(a == x){
      ok = true;
      
    }
    mx = max(a, mx);
  }
  if(ok) {
    cout << "1\n";
    return;
  }
  int res = x/mx;
  if(res*mx < x){
    res++;
  }
  if(res == 1){
    res++;
  }
  cout << res << '\n';

   
}