// #include <bits/stdc++.h>
#include <iostream>
#include <set>
#include <numeric>
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
  // cin >> tc;
  for(int i = 0; i < tc; ++i) {
    // cout << "Case #" << i+1 << ": ";
    solve();
  }
  
  return 0;
}

void solve(){
  int n,ccd;
  cin >> n;
  cin >> ccd;
  for (int i = 1; i < n; i++)
  {
    int x;
    cin >> x;
    ccd = gcd(x,ccd);
  }
  if(ccd == 1){
    cout << "1\n";
    return;
  } else if(ccd == 2){
    cout << "2\n";
    return;
  }
  set<int> st;
  st.insert(1);
  st.insert(ccd);
  for (int i = 2; i*i <= ccd; i++)
  {
    if(ccd%i == 0){
      st.insert(i);
      st.insert(ccd/i);
    }
  }
  st.insert(ccd);
  cout << st.size() << '\n';
  // for(auto e: st){
  //   cout << e << ' ';
  // }
  
}