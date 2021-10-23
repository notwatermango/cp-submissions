// #include <bits/stdc++.h>
#include <iostream>
#include <bitset>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

#define int int64_t
#define MOD 1000000007
#define LLINF 4202000013666420666
#define INF 1000177013

void solve();

signed main(){
  ios_base::sync_with_stdio(false); cin.tie(0);
  int tc = 1;
  cin >> tc;
  for(int i = 0; i < tc; ++i) {
    // cout << "Case #" << i+1 << ": ";
    solve();
  }
  
  return 0;
}

void solve(){
  int n, k;
  cin >> n >> k;
  vector<char> v(n, 'a');
  
  int res = -1;

  for(int i = 100000000; i > 0; i /= 2){
    // cout << i <<' ';
    while(
      (res + i) * (res + i - 1) / 2 < k
    ) res += i;
  }
  int res2 = res*(res-1)/2;
  // cout << res +1<<' ' << k-res2<< '\n';
  v[n-(res+1)] = 'b';
  v[n-(k-res2)] = 'b';
  for (int i = 0; i < n; i++)
  {
    cout << v[i];
  }
  cout << '\n';
  
}