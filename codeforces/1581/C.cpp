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
int n,m;
vector<vector<int>> arr;
void solv() {
  cin >> n >> m;
  arr.assign(n, vector<int>(m, 0));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      char cjar; cin >> cjar;
      arr[i][j] = cjar-'0';
    }
  }
  vector<vector<int>> pren, prem;
  pren.assign(n, vector<int>(m));
  prem.assign(n, vector<int>(m));
  for (int i = 0; i < n; ++i) {
    int sw = 0;
    for (int j = 0; j < m; ++j) {
      sw += arr[i][j];
      pren[i][j] = sw;
    }
    mango(sw);
  }
  for (int i = 0; i < m; ++i) {
    int sw = 0;
    for (int j = 0; j < n; ++j) {
      sw += arr[j][i];
      prem[j][i] = sw;
    }
  }
  mango(arr);
  mango(pren);
  mango(prem);
  int mn = LLINF;
  for (int sx = 0; sx+4 < n; ++sx) {
    for (int ex = sx+4; ex < n; ++ex) {
      // incl [sx, ex];
      // q)ex-1 - q)sx
      int ly = 0; // starting
      vector<int> prefix_inner(m);
      int sw = 0;
      for (int i = 0; i < 3; ++i) {
        sw += prem[ex-1][i] - prem[sx][i];
        prefix_inner[i] = sw;
      }
      for (int ry = 3; ry < m; ++ry) {
        int cost1 = 0;
        cost1 += (ry - ly - 1) - (pren[sx][ry-1] - pren[sx][ly]); // top
        cost1 += (ry - ly - 1) - (pren[ex][ry-1] - pren[ex][ly]); // bot
        cost1 += (ex - sx - 1) - (prem[ex-1][ly] - prem[sx][ly]); // left
        cost1 += (ex - sx - 1) - (prem[ex-1][ry] - prem[sx][ry]); // right
        cost1 += prefix_inner[ry-1] - prefix_inner[ly];
        int qq = mn;
        mn = min(mn, cost1);
        if (qq^mn and mn == 3) {
          mango(mp(sx, ex)); 
          mango(mp(ly, ry)); 
        }
        int newly = ry-3;
        if (newly) {
          int cost2 = 0;
          cost2 += (ry - newly - 1) - (pren[sx][ry-1] - pren[sx][newly]); // top
          cost2 += (ry - newly - 1) - (pren[ex][ry-1] - pren[ex][newly]); // bot
          cost2 += (ex - sx - 1) - (prem[ex-1][newly] - prem[sx][newly]); // left
          cost2 += (ex - sx - 1) - (prem[ex-1][ry] - prem[sx][ry]); // right
          cost2 += prefix_inner[ry-1] - prefix_inner[newly];
          if (cost2 < cost1) {
            ly = newly;
            cost1 = cost2;
          }
          qq = mn;
          mn = min(mn, cost1);
          if (qq^mn and mn == 3) {
            mango(mp(sx, ex)); 
            mango(mp(ly, ry)); 
          }
        }
        prefix_inner[ry] = prefix_inner[ry-1] + prem[ex-1][ry] - prem[sx][ry];
      }


      
    }
  }
  cout << mn << '\n';


}