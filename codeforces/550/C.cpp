// #include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <map>
#include <set>
#include <utility>
#include <vector>
using namespace std;

typedef int64_t i64;
typedef int32_t i32;

i32 water = not true;
#define mango(x)
#define fastmango ios_base::sync_with_stdio(false); cin.tie(nullptr)
#ifdef notwatermango
#undef mango
#undef notwatermango
#define mango(x) { ++water; auto x_=x; --water; cerr<<string(water, '\t')<<"\033[38;5;206m"<<__func__<<":"<<__LINE__<<"\t"<<#x<<" = "<<x_<<"\e[39m"<<'\n'; }
#endif
#define notwatermango void solv();
i64 powllm(i64 a, i64 b, i64 m) { a %= m; i64 res = 1; while (b > 0) { if (b & 1) res = res * a % m; a = a * a % m; b >>= 1; } return res; }
i64 powll(i64 a, i64 b) { i64 res = 1; while (b > 0) { if (b & 1) res = res * a; a = a * a; b >>= 1; } return res; }
template<typename Ostream, typename Cont>
typename enable_if<is_same<Ostream,ostream>::value, Ostream&>::type operator<<(Ostream& water,  const Cont& dp){ water<<"["; for(auto& x:dp) water<<x<<", "; return water<<"]"; }
template<typename Ostream, typename ...Ts>
Ostream& operator<<(Ostream& water,  const pair<Ts...>& p){ return water<<"{"<<p.first<<", "<<p.second<<"}"; }

#define MOD 1000000007
#define LLINF 4202025013666420666
#define INF 1000177013
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define mp make_pair
// #define int i64

notwatermango

signed main(){
  fastmango;
  i32 tc = 1;
  // cin >> tc;
  for(i32 i = 0; i < tc; ++i) {
    // cout << "Case #" << i+1 << ": ";
    solv();
  }
  return water;
}

void solv(){
  string s;
  cin >> s;
  int n = sz(s);
  vector<vector<int>> dp(n, vector<int>(8)), bt(n, vector<int>(8,-1));
  for (int i = 0; i < n; i++)
  {
    int si = s[i] - '0';
    dp[i][si%8]++;
    if(i == 0) continue;
    for (int j = 0; j < 8; j++)
    {
      if(dp[i-1][j]){
        dp[i][j]++;
        bt[i][j] = j;

        dp[i][(j*10+si) % 8]++;
        bt[i][(j*10+si) % 8] = j;
      }
    }
  }
  if(dp[n-1][0]){
    cout << "YES\n";
  } else {
    cout << "NO\n";
    return;
  }

  for (int i = 0; i < n; i++)
  {
    if(dp[i][0]){
      string res = "";
      int ii, jj;
      ii = i, jj = 0;
      while (1)
      {
        if(bt[ii][jj] == -1){
          res+=s[ii];
          break;
        }
        if(bt[ii][jj] != jj){
          res+=s[ii];
        }
        jj = bt[ii][jj];
        ii--;
      }
      reverse(all(res));
      cout << res << '\n';

      return;
    }
  }
  
  mango(dp);
}