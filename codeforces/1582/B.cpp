// #include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <cmath>
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
  int n;
  cin >> n ;
  int arr[n];
  int ones = 0;
  int zes = 0;
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
    if(arr[i] == 1){
      ones++;
    } else if(arr[i] == 0){
      zes++;
    }
  }
  int zes2 = pow(2, zes);
  cout << ones*zes2 << '\n';
  
}