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
Water& operator<<(Water&water,pair<Typename...>&p){return water<<'{'<<get<0>(p)<<", "<<get<1>(p)<<'}';}
template<typename Water, typename Fire>
Water& operator<<(Water&water,vector<vector<Fire>>v){water<<"\n{\n";for(auto i:v){water<<"\t[ ";for(auto j: i)water\
// <<left<<setw(8) \M
<<j<<' ';water<<"]\n";};return water<<"}";}
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
  int n,m;
  cin >> n >> m;
  int h[n];
  for (int i = 0; i < n; i++)
  {
    cin >> h[i];
  }
  vector<vector<int>> adj(n);
  for (int i = 0; i < m; i++)
  {
    int u,v;
    cin >> u >> v;
    u--;v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

  vector<int> sp(n, LLINF);
  sp[0] = 0;
  pq.push(mp(0,0));
  while (!pq.empty())
  {
    int hpnow = pq.top().first;
    int u = pq.top().second;
    pq.pop();
    for(auto v: adj[u]) {
      int dist = h[v] - h[u];
      dist = max(dist, (int)0);
      if(hpnow + dist < sp[v]) {
        sp[v] = hpnow+dist;
        pq.push(mp(hpnow + dist, v));
      }

    }
  }

  mango(sp);
  int ans = 0;
  for (int i = 0; i < n; i++)
  {
    ans = max(ans, h[0] - h[i] - sp[i]);
  }
  cout << ans << '\n';
  
  



  
  
}