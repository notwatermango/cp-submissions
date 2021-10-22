// #include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

// #define int int64_t
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
  int n;
  cin >> n;
  int x;
  bool bad = false;
  int a =0;
  for (int i = 0; i < n; i++)
  {
    cin >> x;
    int cl = min(i, n-i-1);
    if(x < cl){
      bad = true;
    } else if(n%2 == 0 && x == cl && (i == n/2 || i == n/2-1)){
      a++;
    }
  }
  if(bad || a>1) cout << "No\n";
  else cout <<"Yes\n";
}