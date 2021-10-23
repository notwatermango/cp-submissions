// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
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
  vector<int> v;
  int sum = 0;
  for (int i = 0; i < n; i++)
  {
    if(s[i] == '0') continue;
    sum += s[i] - '0';
    v.push_back(sum);
  }
  if(v.empty()){
    cout << "YES\n";
    return;
  } else if((int)v.size() < 2){
    cout << "NO\n";
    return;
  }

  n = v.size();

  for (int i = 0; i < n-1; i++)
  {
    int kk = 2;
    int jj = 0;
    for (int j = i+1; j < n; j++)
    {
      if(v[j] == v[i] * kk){
        kk++;
        jj = j;
      }
    }
    if(kk > 2 && jj == n-1){
      cout << "YES\n";
      return;
    }
  }
  cout << "NO\n";
  

  

}