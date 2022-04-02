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
  for (i32 i = 0; i < tc; ++i) {
    // cout << "Case #" << i+1 << ": ";
    solv();
  }
  return water;
}
vector<vector<char>> arr;
vector<vector<int>> vis;
vector<vector<int>> visp, vism;
int f1,f2,t1,t2;
int n;
int dx[] = {1,1,-1,-1};
int dy[] = {1,-1,1,-1};
void bfs(int x, int y) {
  queue<int> qx,qy;
  vis[x][y] = 1;
  qx.push(x), qy.push(y);
  while (not qx.empty()) {
    int xn = qx.front(), yn = qy.front();
    qx.pop(); qy.pop();
    for (int i = 0; i < 4; ++i) {
      for (int j = 1; j <= n; ++j) {
        int xx = xn + dx[i]*j, yy = yn + dy[i]*j;
        if(xx < 0 || xx > n-1 || yy < 0 || yy > n-1 || arr[xx][yy] == '#') break;
        if(visp[xx][yy] and dx[i] == dy[i]) break;
        if(vism[xx][yy] and dx[i] != dy[i]) break;
        if(visp[xx][yy] or vism[xx][yy]) {
          
        if(dx[i] == dy[i]) visp[xx][yy] = 1;
        if(dx[i] != dy[i]) vism[xx][yy] = 1;
        continue;
        }
        if(dx[i] == dy[i]) visp[xx][yy] = 1;
        if(dx[i] != dy[i]) vism[xx][yy] = 1;
        qx.push(xx);
        qy.push(yy);
        vis[xx][yy] = vis[xn][yn] + 1;
        
      }
    }
  }
}
void solv() {
  cin >> n;
  arr.assign(n, vector<char>(n));
  vis.assign(n, vector<int>(n, 0));
  vism.assign(n, vector<int>(n, 0));
  visp.assign(n, vector<int>(n, 0));
  cin >> f1 >> f2;
  f1--;f2--;
  cin >> t1 >> t2;
  t1--;t2--;
  for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) cin >> arr[i][j];
  bfs(f1,f2);
  cout << vis[t1][t2]-1<<'\n';

}