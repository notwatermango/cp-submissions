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
  string s;
  cin >> s;
  int b[3] = {0},r[3] = {0},g[3] = {0},tt[3];
  int arr[3] = {0,1,2};
  for (int i = 0; i < n; i++)
  {
    if(s[i] == 'R'){
      r[i%3]++;
      // cout << i%3 << "R\n";
    } else if(s[i] == 'G'){
      g[i%3]++;
    } else {
      b[i%3]++;
    }
    tt[i%3]++;
  }
  int mn = INF;
  do
  {
    // cout << arr[0] << arr[1] << arr[2] << '\n';
    mn = min(mn, 
      n - b[arr[0]] - g[arr[1]] - r[arr[2]]
    );
  } while (next_permutation(arr, arr+3));
  cout << mn << '\n';
  sort(arr, arr+3);
  do
  {
    if(mn == n-b[arr[0]] - g[arr[1]] - r[arr[2]]){
      // cout << r[0] << ' ' << r[1] << ' ' << r[2];
      for (int i = 0; i < n; i++)
      {
        if(i%3 == arr[0]){
          cout << 'B';
        } else if(i%3 == arr[1]){
          cout << 'G';
        } else {
          cout << 'R';
        }
      }
      cout << '\n';
      
      break;
    }
  } while (next_permutation(arr, arr+3));
  
}