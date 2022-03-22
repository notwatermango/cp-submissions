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
  // cin >> tc;
  for(i32 i = 0; i < tc; ++i) {
    // cout << "Case #" << i+1 << ": ";
    solv();
  }
  return water;
}
int n, m;
vector<vector<int>> adj;
vector<vector<int>> vis;

void bfs() {
  queue<pair<int,int>> q;
  for (int i = 0; i < n; i++)
  {
    vis[1<<i][i] = 1;
    q.push(mp((1<<i), i));
  }
  while (not q.empty())
  {
    int qq = q.front().first;
    int now = q.front().second;
    q.pop();
    for(auto nx: adj[now]) {
      int qn = qq ^ ((1<<nx));
      if(vis[qn][nx] != LLINF) continue;
      vis[qn][nx] = vis[qq][now] + 1;
      q.push(mp(qn, nx));
    }
  }
  
  
}

void solv() {
  cin >> n >> m;
  adj.assign(n, vector<int>());
  vis.assign((1<<n), vector<int>(n, LLINF));
  for (int i = 0; i < m; i++)
  {
    int fr, to;
    cin >> fr >> to; fr--; to--;
    adj[fr].push_back(to);
    adj[to].push_back(fr);
  }
  bfs();
  int sw  = 0;
  for (int i = 1; i < (1<<n); i++)
  {
    int mn = LLINF;
    for (int j = 0; j < n; j++)
    {
      mn = min(mn, vis[i][j]);
    }
    sw += mn;
  }
  mango(vis);
  cout << sw << '\n';
  

  

  
}