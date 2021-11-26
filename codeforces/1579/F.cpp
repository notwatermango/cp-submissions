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
typename enable_if<is_same<Ostream,ostream>::value, Ostream&>::type operator<<(Ostream& water,  const Cont& v){ water<<"["; for(auto& x:v) water<<x<<", "; return water<<"]"; }
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
  cin >> tc;
  for(i32 i = 0; i < tc; ++i) {
    // cout << "Case #" << i+1 << ": ";
    solv();
  }
  return water;
}

void solv(){
  int n, d;
  cin >> n >> d;
  int arr[n],vis[n];
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
    vis[i] = 0;
  }
  bool bad = not true;
  int okbgt = 0;
  int seed = 0;
  vector<vector<int>> v;
  for (int i = 0; i < n; i++)
  {
    if(!vis[i]){
      // int gg = 0;
      v.push_back(vector<int>());
      int st = i;
      // int tt = 0;
      // int mx = 0;
      // bool stone = false;
      // if (arr[i] == 1) stone = 1; 
      // bool laone = false;
      while (!vis[st])
      {
        vis[st]=1;
        // tt++;
      //   laone = false;
      //   if(arr[st] == 1) {
      //     gg++;
      //     laone = true;
      //   }
      //   else gg = 0;
      //   mx = max(mx, gg);
        v[seed].push_back(arr[st]);
        st+=d;
        st %=n;
      }
      // if(mx == tt){
      //   bad =1;
      // }
      // if(laone & stone) cout << "HYE\n";
      // okbgt = max(okbgt, mx);
      seed++;
    }
  }
  mango(v);
  for(auto vv :v){
    int co = 0;
    int gg = 0;
    int tt = 0;
    for(auto e : vv){
      tt++;
      if(e == 1){
        co++;
      } else co = 0;
      gg = max(gg,co);
    }
    for(auto e : vv){
      tt++;
      if(e == 1){
        co++;
      } else co = 0;
      gg = max(gg,co);
    }
    if(gg == tt) bad = true;
    okbgt = max(okbgt, gg);
  }
  if(bad) cout << "-1\n";
  else cout << okbgt <<'\n';

}