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
// <<left<<setw(8) \笑
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
  cin >> tc;
  for (i32 i = 0; i < tc; ++i) {
    // cout << "Case #" << i+1 << ": ";
    solv();
  }
  return water;
}
vector<int> vis;
vector<vector<int>> killerof;

void dfs(int x) {
  if (vis[x]) return;
  vis[x] = 1;
  for (auto e: killerof[x]) {
    dfs(e);
  }
}

void solv() {
  int n; cin >> n; vis.assign(n, 0); killerof.assign(n, vector<int>());
  vector<pair<pair<int,int>, int>> arr(n);
  int mx1, mx2;
  mx1 = mx2 = 0;
  for (int i = 0; i < n; ++i) {
    cin >> arr[i].first.first;
    arr[i].second = i;
    mx1 = max(mx1, arr[i].first.first);
  }
  for (int i = 0; i < n; ++i) {
    cin >> arr[i].first.second;
    mx2 = max(mx2, arr[i].first.second);
  }
  int gg1, gg2;
  for (int i = 0; i < n; ++i) {
    if (arr[i].first.first == mx1) gg1 = i;
    if (arr[i].first.second == mx2) gg2 = i;
  }

  sort(all(arr));
  for (int i = 0; i +1 < n; ++i) {
    killerof[arr[i].second].push_back(arr[i+1].second);
  }
  sort(all(arr), [](pair<pair<int,int>,int> &a, pair<pair<int,int>,int> &b) {
    return a.first.second < b.first.second;
  });
  for (int i = 0; i + 1< n; ++i) {
    killerof[arr[i].second].push_back(arr[i+1].second);
  }

  // lesgo from gg1 gg2
  // mango(killerof);
  dfs(gg1);
  dfs(gg2);
  
  for (auto e: vis) {
    cout << e;
  } cout << '\n';
}