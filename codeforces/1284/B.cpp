// #include <bits/stdc++.h>
#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

typedef int64_t i64;
typedef int32_t i32;

i32 water = not true;
#define mango(x)
#define fastmango ios_base::sync_with_stdio(false); cin.tie(nullptr)
#ifdef notwatermango
#undef notwatermango
#undef mango
#define mango(x) {++water; auto x_=x; --water; cerr<<string(water, '\t')<<"\033[38;5;206m"<<__func__<<":"<<__LINE__<<"\t"<<#x<<" = "<<x_<<"\e[39m"<<'\n';}
#endif
#define notwatermango void solv();
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
#define int i64

notwatermango

signed main(){
  fastmango;
  i32 tc = 1;
  // cin >> tc;
  for(i32 i = 0; i < tc; ++i) {
    // cout << "Case #" << i+1 << ": ";
    solv();
  }
  return 0;
}

void solv(){
  int n; cin >> n;
  vector<pair<int,int>> v;
  bool asc;
  for (int i = 0; i < n; i++)
  {
    asc = false;
    int x; cin >> x;
    int mem = INF;
    int wow, mx, mn;
    for (int j = 0; j < x; j++)
    {
      cin >> wow;
      if(j == 0){
        mx = wow;
        mn = wow;
      } else {
        mx = max(mx, wow);
        mn = min(mn, wow);
      }
      if(wow > mem){
        asc = true;
      }
      mem = wow;
    }
    if(asc) continue;
    v.push_back(mp(mx, mn));
  }
  int qq = sz(v);
  int rres = 0;
  sort(all(v));
  // cout << "===\n";
  // for(auto e:v){
  //   cout << e.first << ' ' << e.second << '\n';
  // }
  // cout << "===\n";
  for (int i = 0; i < qq; i++)
  {
    int res = -1;
    for(int j = qq; j > 0; j/=2){
      while(res+j < qq && v[res + j].first <= v[i].second) res+=j;
    }
    if(res == -1) continue;
    res++;
    // cout << res << '\n';
    rres+=res;
  }
  // cout << "---\n";
  cout << n*n-rres << '\n';
}