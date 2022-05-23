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

using P = pair<int,int>;
vector<vector<P>> adj;
vector<int> vis;
bool sad;
vector<vector<int>> nk;
void dfs(int x) {
  nk.back().push_back(vis[x]);
  for (auto e: adj[x]) {
    if (not vis[e.first]) {
      vis[e.first] = vis[x]*e.second;
      dfs(e.first);
    } else if (vis[e.first] and vis[e.first] != vis[x]*e.second) sad = 1;
  }
  if (sad) return;
}
void solv() {
  int n; cin >> n; int m; cin >> m;
  sad = false;
  adj.assign(n, vector<P>());
  vis.assign(n, 0);
  for (int i = 0; i < m; ++i) {
    int fr, to; string cmd;
    cin >> fr >> to >> cmd;
    fr--, to--;
    char cj = cmd[0];
    int kankei = 1;
    if (cj == 'i') {
      kankei = -1;
    }
    adj[fr].push_back(mp(to, kankei));
    adj[to].push_back(mp(fr, kankei));
  }
  int res = 0;
  for (int i = 0; i < n; ++i) {
    if (not vis[i]) {
      vis[i] = 1;
      nk.push_back(vector<int>());
      dfs(i);
      int c1,c2;
      c1 = c2 = 0;
      for (auto e: nk.back()) {
        if (e == -1) c1++;
        else c2++;
      }
      res += max(c1, c2);
    }
    if (sad) break;
  }

  if (sad) cout <<"-1\n";
  else cout << res << '\n';
}