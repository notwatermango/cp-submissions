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

vector<vector<int>> adj;
vector<int> vis;
vector<int> v;
int ok = 0;

void dfs(int nod, int col, bool star){
  if(col == 0){
    col = -1;
  } else if(col == -1){
    col = v[nod];
  }
  if(col != v[nod] && not star){
    ok = 0;
    mango(mp(col, v[nod]));
    return;
  }
  vis[nod] = 1;
  for(auto e: adj[nod]){
    if(not vis[e]){
      dfs(e, col, 0);
    }
  }

}

void solv(){
  int n; cin >> n;
  vector<pair<int,int>> edg(n);
  vis.assign(n, 0);
  adj.assign(n, vector<int>());
  v.assign(n, 0);
  for (int i = 1; i < n; i++)
  {
    cin >> edg[i].first >> edg[i].second;
    edg[i].first--;
    edg[i].second--;
    adj[edg[i].first].push_back(edg[i].second);
    adj[edg[i].second].push_back(edg[i].first);
  }
  mango(adj);
  for (int i = 0; i < n; i++)
  {
    cin >> v[i];
  }
  mango(v);
  int qq,qqq;
  qq = qqq = INF;
  for (int i = 1; i < n; i++)
  {
    if(v[edg[i].first ] != v[edg[i].second ]){
      qq = edg[i].first;
      qqq = edg[i].second;
    }
  }
  if(qq == INF){
    cout << "YES\n1\n";
    return;
  }
  ok = 1;
  dfs(qq,0,1);
  if(ok){
    cout << "YES\n" << qq+1 << '\n';
    return;
  }
  ok = 1;
  vis.assign(n, 0);
  dfs(qqq,0,1);
  if(ok) {
    cout << "YES\n" << qqq+1 << '\n';
    return;
  }
  cout << "NO\n";
  return;


  
  
}