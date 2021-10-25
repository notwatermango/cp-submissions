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
  int n;
  cin >> n;
  int arr[n];
  int ct[6] = {0};
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
    if(arr[i] == 4) ct[0]++;
    else
    if(arr[i] == 8 && ct[1] < ct[0]) ct[1]++;
    else
    if(arr[i] == 15 && ct[2] < ct[1]) ct[2]++;
    else
    if(arr[i] == 16 && ct[3] < ct[2]) ct[3]++;
    else
    if(arr[i] == 23 && ct[4] < ct[3]) ct[4]++;
    else
    if(arr[i] == 42 && ct[5] < ct[4]) ct[5]++;
  }
  int res = min(n/6,ct[5]);
  cout << n - (res*6) << '\n';

  
}