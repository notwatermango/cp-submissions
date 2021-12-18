#include <bits/stdc++.h>
using namespace std;

typedef int64_t i64;
typedef int32_t i32;

i32 water = !not!iscntrl(isupper(isgraph(iscntrl(ispunct(isalpha(EOF))))));
#define mango(x)
#define fastmango cin.tie(nullptr)->sync_with_stdio(water)
#ifdef notwatermango
#undef mango
#undef notwatermango
#define mango(x) { water = 999; auto x_ = x; water = not water; cerr<<ends<<"\033[38;5;206m"<<__LINE__<<"\t: "<<#x<<" = "<<x_<<"\e[39m"<<'\n'; }
#endif
#define notwatermango void solv();
i64 powllm(i64 a, i64 b, i64 m) { a %= m; i64 res = 1; while (b > 0) { if (b & 1) res = res * a % m; a = a * a % m; b >>= 1; } return res; }
i64 powll(i64 a, i64 b) { i64 res = 1; while (b > 0) { if (b & 1) res = res * a; a = a * a; b >>= 1; } return res; }
template<typename Water, typename ...Typename>
Water& operator<<(Water& water, const pair<Typename...>& p){ return water<<'{'<<get<0>(p)<<", "<<get<1>(p)<<'}'; }
template<typename Water, typename Fire>
Water& operator<<(Water& water, const Fire& v){ water<<'['; for(auto i: v) water<<i<<", "; return water<<']'; }
template<typename _const>
vector<_const> tov(_const x[], i32 xs) { return vector<_const> (x, x + xs); }

#define INF 1000177013
#define LLINF 4202025013666420666
#define dbg(x) tov(x, sizeof x / sizeof x[0]);
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define MOD 1000000007
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
  return water;
}

int n,m;
vector<vector<int>> adj;
vector<vector<int>> vis;

void bfs(int xx){
  queue<int> q;
  q.push(0);
  vis[0][xx] = 1;
  // /*
  while(not q.empty()){
    int now = q.front();
    q.pop();
    for(int i = 0; i < n; ++i){
      if(now == i) continue;
      if(xx && adj[i][now] && vis[now][xx] + 1 < vis[i][xx]){
        vis[i][xx] = vis[now][xx]+1;
        q.push(i);
      }
      if(!xx && !adj[i][now] && vis[now][xx] + 1 < vis[i][xx]){
        vis[i][xx] = vis[now][xx]+1;
        q.push(i);
      }
    }
  }
  // */
}

void solv(){
  cin >> n >> m;
  adj.assign(n, vector<int>(n));
  vis.assign(n, vector<int>(2, INF));
  for(int i = 0; i < m; ++i) {
    int fr,to;
    cin >> fr >> to;
    fr--; to--;
    adj[fr][to]++;
    adj[to][fr]++;
  }
  bfs(1);
  bfs(0);
  int a = vis[n-1][0] - 1;
  int b = vis[n-1][1] - 1;
  mango(mp(a,b));
  if(a+1 == INF || b == INF-1){
    cout << "-1\n";
  } else {
    cout << max(a,b);
  }
}