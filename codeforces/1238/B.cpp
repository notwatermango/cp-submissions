// #include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
// #define int int64_t

int n,r;
vector<int> arr;
bool ok(int a){
  for (int i = 0; i < (int)arr.size()-a; i++)
  {
    if(arr[i] - r*a > 0) return false;
  }
  // cout << a << ' ' << (int)arr.size()-a << " hi\n";
  return true;
}

void solve(){
  cin >> n >> r ;
  arr.assign(n, 0);
  map<int,int> mp;
  for (int i = 0; i < n; i++){
    cin >> arr[i];
    mp[arr[i]]++;
    if(mp[arr[i]] > 1){
      arr[i] = 0;
    }
  }
  sort(arr.begin(), arr.end());
  int res = 0;
  for(int i = 100005; i > 0; i/=2){
    while(!ok(res+i)) {
      res+=i;
      // cout << res << ' ';
    }
  }
  cout << res + 1<< '\n';


  
}


signed main(){
  ios_base::sync_with_stdio(false); cin.tie(0);
  int tc; cin >> tc;
  while(tc--) {
    solve();
  }
  
  return 0;
}