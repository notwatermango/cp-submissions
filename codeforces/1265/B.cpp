// #include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
// #define int int64_t


void solve(){
  int n;
  cin >>n;
  int arr[n];
  int ii;
  for(int i = 0; i < n; i++){
    cin >> arr[i];
    if(arr[i] == 1){
      ii = i;
    }
  }
  vector<bool> ok(n+1);
  vector<bool> vis(n+1);
  vector<bool> gg(n+1);
  ok[0] = true;
  vis[0] = true;
  int a = 1;
  int l = ii;
  int r = ii;
  int pnow = ii;
  int fhere = 0;
  while(a <= n){
    // cout << pnow << ' ';
    vis[arr[pnow]] = true;
    if(ok[a-1] && arr[pnow] == a){
      ok[a] = true;
      fhere = a;
    } else if(arr[pnow] > a){
      // ignore
      // cout << "big " << arr[pnow] << '\n';
    } else if(arr[pnow] < a){
      // check
      for (int i = fhere+1; i < n+1; i++)
      {
        if(vis[i]) {
          ok[i] = true;
          fhere = i;
        }
        else break;
      }
    }
    if(ok[a]){
      gg[a] = true;
    }
    if(l > 0 && r < n-1){
      if(arr[l-1] < arr[r+1]){
        // go left
        l--;
        a++;
        pnow=l;
      } else{
        r++;
        a++;
        pnow=r;
      }
    } else{
      if(l > 0){
        l--;
        a++;
        pnow=l;
      } else {
        r++;
        a++;
        pnow=r;
      }
    }

  }
  for (int i = 1; i < n+1; i++)
  {
    cout << gg[i];
  }
  cout << '\n';
  

}


signed main(){
  ios_base::sync_with_stdio(false); cin.tie(0);
  int tc; cin >> tc;
  while(tc--) {
    solve();
  }
  
  return 0;
}