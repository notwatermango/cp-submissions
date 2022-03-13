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
  for(i32 i = 0; i < tc; ++i) {
    // cout << "Case #" << i+1 << ": ";
    solv();
  }
  return water;
}

// vector<vector<pair<int,int>>> adj;
priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> edg;

/* dsu */
vector<int> par,sc;

int get_par_d(int x){
  if(x == par[x]) return x;
  return par[x] = get_par_d(par[x]);
}
bool connect_d(int x, int y){
  x = get_par_d(x);
  y = get_par_d(y);
  if(x!=y){
    if(sc[x] < sc[y]) swap(x,y);
    par[y] = x;
    sc[x] += sc[y];
    return true;
  }
  return false;
}
void make_set_d(int x){
  par[x] = x;
  sc[x] = 1;
}
/* ~dsu */

void solv() {
  int n,m;
  cin >> n >> m;
  par.assign(n, 0);
  sc.assign(n, 0);
  for (int i = 0; i < n; i++) {
    make_set_d(i);
  }
  vector<vector<int>> adj(n, vector<int>(n, LLINF));
  vector<vector<bool>> cad(n, vector<bool>(n, false));
  // vector<pair<int,int>> used;
  for (int i = 0; i < m; i++)
  {
    int fr, to, len;
    cin >> fr >> to >> len;
    fr--; to--;
    adj[fr][to] = len;
    adj[to][fr] = len;
    edg.push(mp(len, mp(fr, to)));
  }

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      for (int k = 0; k < n; k++)
      {
        int wow = 0;
        adj[j][k] = min(adj[j][k], adj[j][i] + adj[i][k]);
        if(wow != adj[j][k]) {
          cad[j][i] = cad[i][k] = cad[i][j] = cad[k][i] = 1;
        }
      }
      
    }
    
  }
  


  mango(adj);
  int ct = 0;
  while (not edg.empty())
  {
    int notcad = 0;
    for (int i = 0; i < n; i++)
    {
      if(i == edg.top().second.second || i == edg.top().second.first) continue;
      if(adj[edg.top().second.first][i] + adj[i][edg.top().second.second] <= edg.top().first) notcad = 1;
    }
    
    if(
      notcad
      // not connect_d(edg.top().second.first, edg.top().second.second)
      // && 
      // edg.top().first != adj[edg.top().second.first][edg.top().second.second]
    ) {
      ct++;
    }
    edg.pop();

  }
  cout << ct << '\n';
  
  

}