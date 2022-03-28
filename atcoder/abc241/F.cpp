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
// #define int i64
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

map<int,set<int>> vsx, vsy;
map<pair<int,int>,int> vis;
int h,w,n;

void bfs(int x, int y) {
  vis[mp(x,y)]=1;
  queue<int> qx,qy;qx.push(x), qy.push(y);
  while (not qx.empty())
  {
    int xn = qx.front(); qx.pop();
    int yn = qy.front(); qy.pop();
    // mango(mp(xn,yn));
    if(vsy.size()) {
      // go up
      auto up = vsy[yn].lower_bound(xn);
      if(up!= vsy[yn].begin() and *(prev(up)) < xn and not vis[mp(*(prev(up))+1,yn)]) {
        vis[mp(*(prev(up))+1,yn)] = vis[mp(xn,yn)]+1;
        qx.push(*(prev(up))+1);
        qy.push(yn);
      }
      // go down
      auto down = vsy[yn].upper_bound(xn);
      if(down != vsy[yn].end() and not vis[mp(*down-1,yn)]) {
        vis[mp(*down-1,yn)] = vis[mp(xn,yn)] + 1;
        qx.push(*down-1);
        qy.push(yn);
      }
    }
    if(vsx.size()){
      // go left
      auto left = vsx[xn].lower_bound(yn);
      if(left != vsx[xn].begin() and *(prev(left)) < yn and not vis[mp(xn,*(prev(left))+1)]) {
        vis[mp(xn,*(prev(left))+1)] = vis[mp(xn,yn)]+1;
        qx.push(xn);
        qy.push(*(prev(left))+1);
      }
      // go right
      auto right = vsx[xn].upper_bound(yn);
      if(right != vsx[xn].end() and not vis[mp(xn,*right-1)]) {
        vis[mp(xn,*right-1)] = vis[mp(xn,yn)]+1;
        qx.push(xn);
        qy.push(*right-1);
      }
    }
  }
  
}

void solv() {
  cin >> h >> w >> n;
  int sx,sy,gx,gy;
  cin >> sx >> sy >> gx >> gy;
  sx--;sy--;gx--;gy--;
  vector<pair<int,int>> obstacles;

  // compress
  set<int> vx,vy;
  vx.insert(sx);vx.insert(gx);
  vy.insert(sy);vy.insert(gy);
  for (int i = 0; i < n; i++)
  {
    int x,y;
    cin >> x >> y; x--;y--;
    obstacles.push_back(mp(x,y));
    vx.insert(x);
    vy.insert(y);
  }

  // int dd = 0;
  // map<int,int> px,py;
  // h = w = 0;
  // for(auto e: vx) {
  //   px[e] = dd;
  //   dd++;
  // }
  // h = dd;
  // dd = 0;
  // for(auto e: vy) {
  //   py[e] = dd;
  //   dd++;
  // }
  // w = dd;
  // // NG -> h || w  || -1 
  // sx = px[sx]; sy = py[sy]; gx = px[gx]; gy = py[gy];
  // for (int i = 0; i < n; i++)
  // {
  //   obstacles[i] = mp(px[obstacles[i].first], py[obstacles[i].second]);
  // }
  /*
  cout << "sx: " << sx << " sy: " << sy;
  cout << "\ngx: " << gx << " gy: " << gy << '\n';
  cout << "h: " << h << " w: " << w << '\n';
  mango(obstacles);
  */
  // lesgo
  for (int i = 0; i < n; i++)
  {
    vsx[obstacles[i].first].insert(obstacles[i].second);
    vsy[obstacles[i].second].insert(obstacles[i].first);
  }
  // mango(vsx);
  // mango(vsy);
  // mango(sx);
  // mango(sy);

  mango(gx);
  mango(gy);

  bfs(sx,sy);
  // mango(vis);
  cout << vis[mp(gx,gy)]-1<<'\n';
  

}