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
  int n ;
  cin >> n;
  int arr[n];
  int yas = 0;
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
    yas+=arr[i];
  }
  int mx = 0;
  int sum = 0;
  int c = 0;
  int l = 0;
  int r = 0;
  for (int i = 0; i < n; i++)
  {
    if(sum + arr[i] > 0){
      sum += arr[i];
      c++;
    } else{
      sum = 0;
      c = 0;
      l = i;
    }
    if(sum > mx){
      r = i;
    }
    mx = max(mx, sum);
  }
  if(l == 0 && r == n-1){
    if(arr[0] < arr[n-1]){
      mx-=arr[0];
    } else{
      mx-=arr[n-1];
    }
  }
  // cout << l << ' ' << r << '\n';
  string res = yas > mx ?"YES\n"  : "NO\n";
  cout << res;
  

  
}