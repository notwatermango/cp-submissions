// #include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

// #define int int64_t
#define MOD 1000000007
#define LLINF 4202000013666420666
#define INF 1000177013

void solve();

signed main(){
  ios_base::sync_with_stdio(false); cin.tie(0);
  int tc = 1;
  // cin >> tc;
  for(int i = 0; i < tc; ++i) {
    // cout << "Case #" << i+1 << ": ";
    solve();
  }
  
  return 0;
}

void solve(){
  int x,y;
  cin >> x >> y;
  int arr[x][y];
  for (int i = 0; i < x; i++)
  {
    for (int j = 0; j < y; j++)
    {
      cin >> arr[i][j];
    }
  }
  bool bad = false;
  for (int i = 1; i < x; i++)
  {
    for (int j = 1; j < y; j++)
    {
      if(arr[i][j] + arr[i-1][j-1] > arr[i-1][j] + arr[i][j-1]){
        bad = true;
      }
    }
    
  }
  if(bad) cout << "No\n";
  else cout <<"Yes\n";
  
  
}