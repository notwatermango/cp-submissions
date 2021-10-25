// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <numeric>
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
  int n;
  cin >> n;
  vector<int> v(n+1);
  int sq = 1;
  for (int i = 2; i <= n; i++)
  {
    if(v[i]) continue;
    else v[i] = sq;
    for (int j = i+i; j <= n; j+=i)
    {
      if(v[j]) continue;
      v[j] = sq;
    }
    sq++;
  }
  for (int i = 2; i <= n; i++)
  {
    cout << v[i] << ' ';
  }
  cout <<'\n';
  
  

}