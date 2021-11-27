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

vector<int> dis,par,rdis;
vector<bool> vis;
int mn = 0;
int anc;
int n;
bool bad ;

void repar( int *ds, int x){
  if(!vis[par[x]]) {
    bad = 1;
    return;
  } else{
    *ds += rdis[par[x]];
    return;
  }

}

int gopar(int x){
  int dz = 0;
  // while (x != par[x])
  // {
  //   if(!vis[par[x]]) {
  //     bad = true;
  //     return 1;
  //   }
  //   dz += dis[x];
  //   x = par[x];
  // }
  repar(&dz,x);
  return dz;
}

void solv(){
  cin >> n;
  bad= 0;
  anc = INF;
  par.assign(n,0);
  dis.assign(n,1);
  rdis.assign(n,INF);
  vis.assign(n,0);
  mn = 0;
  for (int i = 0; i < n; i++)
  {
    cin >> par[i];
    par[i]--;
    if(i == par[i]){
      anc = i;
    }
  }
  if(anc == INF) bad = 1;
  rdis[anc] = 0;
  dis[anc] = 0;
  vis[anc] = 1;
  for (int i = 0; i < n; i++)
  {
    int x; cin >> x; x--;
    if(bad) continue;
    if(not i && x != anc) bad = 1;
    if(x == anc) continue;
    vis[x] = 1;
    int res = gopar(x);
    if(res <= mn){
      dis[x] += mn - res + 1;
      res += mn - res + 1;
    }

    mn = res;
    rdis[x] = mn;
    mango(mn);
  }
  mango(bad);
  if(bad){
    cout << "-1\n";
    return;
  }
  for(auto e:dis){
    if(e == 0) cout << "0 ";
    else cout << e-1 << ' ';
  }
  cout << '\n';
  
  
}