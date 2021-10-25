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
  string S;
  cin >> n >> S;
  int i = 0;
  int ct = 0;
  vector<char> v;
  
  while (true)
  {
    int k = i + 1;
    if(k >= n) {
      ct++;
      break;
    }

    while (S[i] == S[k])
    {
      k++;
      ct++;
      if(k >= n){
        ct++;
        cout << ct << '\n';
        for(auto e: v){
          cout << e;
        }
        cout << '\n';
        return;
      }
    }
    v.push_back(S[i]);
    v.push_back(S[k]);
    i = k+1;
    if(i >= n){
      break;
    }
    
  }
  cout << ct << '\n';
  for(auto e:v){
    cout << e;
  }
  cout <<'\n';
  
  
  
}