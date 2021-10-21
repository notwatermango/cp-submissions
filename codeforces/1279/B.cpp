// #include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
using namespace std;
#define int int64_t


void solve(){
  int n,k;
  cin >> n >> k;
  int arr[n];
  int sum = 0;
  int mx = 0;
  int ii = -1;
  bool ct = false;
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
    sum+=arr[i];
    if(sum - mx > k && !ct) {
      if(sum - arr[i] <= k){
        cout << i+1 << '\n';
      } else {
        cout << ii + 1 << '\n';
      }
      ct = true;
    }
    if(mx < arr[i]){
      mx = arr[i];
      ii = i;
    }
  }
  if(ct) return;
  if(sum <= k){
    cout << "0\n";
    return;
  }
  cout << ii + 1 << '\n'; 
  
}


signed main(){
  ios_base::sync_with_stdio(false); cin.tie(0);
  int tc; cin >> tc;
  while(tc--) {
    solve();
  }
  
  return 0;
}