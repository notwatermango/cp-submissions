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

int h,w;
int res = 0;
vector<vector<char>> arr;
vector<vector<i32>> vis;


void bfs() {
  queue<pair<i32,i32>> q;
  q.push(mp(0,0));
  vis[0][0] = 0;
  while (not q.empty())
  {
    int xnow = q.front().first;
    int ynow = q.front().second;
    q.pop();
    int znow = vis[xnow][ynow];
    
    if(xnow < h-1 && vis[xnow+1][ynow] == -1 && arr[xnow+1][ynow] != '#'){
      vis[xnow+1][ynow] = znow+1;
      q.push(mp(xnow+1, ynow));
    }
    if(ynow < w-1 && vis[xnow][ynow+1] == -1 && arr[xnow][ynow+1] != '#'){
      vis[xnow][ynow+1] = znow+1;
      q.push(mp(xnow, ynow+1));
    }

  }
  
}

void solv(){
  cin >> h >> w;
  arr.assign(h, vector<char>(w, 0));
  vis.assign(h, vector<i32>(w, -1));
  for (int i = 0; i < h; i++)
  {
    for (int j = 0; j < w; j++)
    {
      cin >> arr[i][j];
    }
  }
  bfs();
  for (int i = 0; i < h; i++)
  {
    for (int j = 0; j < w; j++)
    {
      res = max(res, (int)vis[i][j]);
    }
  }
  cout << res + 1<< '\n';
  
}