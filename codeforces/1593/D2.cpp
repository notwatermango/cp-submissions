// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <map>
#include <numeric>
#include <cmath>
#include <algorithm>
using namespace std;
// #define int int64_t


void solve(){
  int n;
  cin >> n;
  int arr[n];
  map<int,int> minictr;
  int lm = 0;
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
    minictr[arr[i]]++;
    lm = max(lm, minictr[arr[i]]); 
  }
  if(lm >= n/2){
    cout << "-1\n";
    return;
  }
  int res = 1;
  for (int i = 0; i < n; i++)
  {
    int minn = arr[i];
    vector<int> difs;
    for (int j = 0; j < n; j++)
    {
      for (int k = 0; k < n; k++)
      {
        difs.push_back(gcd(arr[j]-minn, arr[k]-minn));
      }
    }
    
    for (auto &k:difs)
    {
      if(!k) continue;
      int c = 0;
      for (int j = 0; j < n; j++)
      {
        if((arr[j] - minn) > -1 && (arr[j] - minn) % k == 0){
          c++;
        }
      }
      if(c >= n/2){
        res = max(res, k);
      }
    }
  }
  cout << res << '\n';
  
  
}


signed main(){
  ios_base::sync_with_stdio(false); cin.tie(0);
  int tc; cin >> tc;
  while(tc--) {
    solve();
  }
  
  return 0;
}