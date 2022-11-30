#include <bits/stdc++.h>
using namespace std;

typedef int64_t i64;
typedef int32_t i32;

i32 water = !not!iscntrl(isupper(isgraph(iscntrl(ispunct(isalpha(EOF))))));
#define mango(x)
#define fastmango cin.tie(nullptr)->sync_with_stdio(water)
#define precisemango(x) cout << fixed << setprecision(x)
#ifdef notwatermango
#undef mango
#undef notwatermango
#define mango(x) { water = 999; auto x_ = x; water = not water; cerr<<ends<<"\033[38;5;206m"<<__LINE__<<"\t: "<<#x<<" = "<<x_<<"\e[39m"<<'\n'; }
#endif
#define notwatermango void solv()
i64 powllm(i64 a, i64 b, i64 m) { a %= m; i64 res = 1; while (b > 0) { if (b & 1) res = res * a % m; a = a * a % m; b >>= 1; } return res; }
i64 powll(i64 a, i64 b) { i64 res = 1; while (b > 0) { if (b & 1) res = res * a; a = a * a; b >>= 1; } return res; }
template<typename Water, typename ...Typename>
Water& operator<<(Water&water,pair<Typename...>&p){return water<<'{'<<get<0>(p)<<", "<<get<1>(p)<<'}';}
template<typename Water, typename Fire>
Water& operator<<(Water&water,vector<vector<Fire>>v){water<<"\n{\n";for(auto i:v){water<<"\t[ ";for(auto j: i)water\
// <<left<<setw(8) \M
<<j<<' ';water<<"]\n";};return water<<"}";}
template<typename Water>
Water& operator<<(Water&water,string&v){for(auto i: v)water<<i;return water;}
template<typename Water, typename Fire>
Water& operator<<(Water&water,Fire&v){water<<'[';for(auto i: v)water<<i<<", ";return water<<']';}
template<typename Mango>
vector<Mango> tov(Mango x[], i32 xs) { return vector<Mango> (x, x + xs); }

#define INF 1000177013
#define LLINF 4202025013666420666
#define dbg(x) tov(x, sizeof x / sizeof x[0]);
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define mp make_pair
#define int i64
#define MOD                                          1000000007
#define YSS                                          112345

notwatermango;

signed main() {
  fastmango;
  i32 tc = 1;
  // cin >> tc;
  for (i32 i = 0; i < tc; ++i) {
    // cout << "Case #" << i+1 << ": ";
    solv();
  }
  return water;
}
vector<vector<int>> adj;
int dist(int a, int b, int c, int d) {
  return (a - c) * (a - c) + (b - d) * (b - d);
}
vector<int> vis;
void dfs(int i) {
  vis[i] = 1;
  for (auto e: adj[i]) {
    if (not vis[e]) dfs(e);
  }
}
void solv() {
  int n; cin >> n;
  mango(n);
  vis.assign(n, 0);
  int sx, sy, gx, gy; cin >> sx >> sy >> gx >> gy;
  mango(mp(sx, sy));
  adj = vector<vector<int>>(n);
  vector<pair<int,pair<int,int>>> ccs(n);
  int start,goal;
  for (int i = 0; i < n; ++i) {
    cin >> ccs[i].second.first >> ccs[i].second.second >> ccs[i].first;
    if (dist(sx, sy, ccs[i].second.first, ccs[i].second.second) == ccs[i].first * ccs[i].first) {
      start = i;
    }
    if (dist(gx, gy, ccs[i].second.first, ccs[i].second.second) == ccs[i].first * ccs[i].first) {
      goal = i;
    }
    mango(i);
  }
  // return;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (i == j) continue;
      int r1 = ccs[i].first, r2 = ccs[j].first;
      int x1 = ccs[i].second.first, x2 = ccs[j].second.first;
      int y1 = ccs[i].second.second, y2 = ccs[j].second.second;
      if (x1 == x2 and y1 == y2 and r1 != r2) continue;
      if ((r1 + r2) * (r1 + r2) >= (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)) {
        // reachable
        adj[i].push_back(j);
      }
    }
  }
  dfs(start);
  mango(adj);
  mango(start);
  mango(goal);
  if (vis[goal]) cout << "Yes\n"; else cout << "No\n";


}