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
  cin >> tc;
  for(int i = 0; i < tc; ++i) {
    // cout << "Case #" << i+1 << ": ";
    solve();
  }
  
  return 0;
}

void solve(){
  int n;
  cin >> n;
  string S;
  cin >> S;
  vector<char> v;
  for (int i = 0; i < 26; i++)
  {
    int a,b;
    a = 0;
    b = n-1;
    bool ok = true;
    while (a < b)
    {
      while (a<b && S[a] == 'a' + i)
      {
        a++;
      }
      while(a<b && S[b] == 'a' + i){
        b--;
      }
      if(a>=b) break;
      if(S[a] != S[b]){
        ok = false;
        break;
      }
      a++;b--;
    }
    if(ok) v.push_back('a' + i);
    
    
  }
  // for(auto e:v){
    // cout << e << ' ';
  // }
  // cout << '\n';
  if(v.size() == 0){
    cout << "-1\n";
    return;
  }
  if(v.size() == 26){
    cout << "0\n";
    return;
  }
  int res = INF;
  // cout <<"tar\n";
  for(auto e:v){
    int a = 0;
    int b = n-1;
    int ct = 0;
    while (a < b)
    {
      if(S[a] != S[b]){
        if(S[a] == e){
          a++;
          ct++;
          continue;
        }
        if(S[b] == e){
          b--;
          ct++;
          continue;
        }
      }
      a++;b--;
    }   
    res = min(ct, res); 
  }
  cout << res << '\n';
  
}