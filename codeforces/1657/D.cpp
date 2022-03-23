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
#define YSS                                          1123456

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

void solv() {
  int n, C;
  int m;
  cin >> n >> C;
  vector<array<int,2>> vv(YSS);
  vector<bool> known(YSS);
  for (int i = 0; i < n; i++)
  {
    int c,d,h;
    cin >> c >> d >> h;
    known[c] = true;
    if(vv[c][0] < d*h) {
      vv[c][0] = d*h;
      vv[c][1] = i;
    }
  }
  cin >> m;
  vector<int> bm;
  for (int i = 0; i < m; i++)
  {
    int D,H;
    cin >> D >> H;
    bm.push_back(D*H);
  }

  // letsgo sieve
  vector<pair<int,int>> best(YSS);
  for (int i = 0; i < YSS; i++) if(known[i])
  {
    for (int j = 1; j*i < YSS; j++)
    {
      int cost = j*i;
      if(best[cost].first < vv[i][0]*j) {
        best[cost].first = vv[i][0]*j;
        best[cost].second = vv[i][1];
      }
    }
  }
  mango(best);
  // letsgo pre
  vector<pair<int,int>> gg(YSS);
  int bnow = 0;
  int bg = 0;
  for (int i = 0; i < YSS-5; i++)
  {
    if(best[i].first > bnow) {
      bnow = best[i].first;
      bg = best[i].second;
    }
    gg[i].first = bnow;
    gg[i].second = bg;
  }
  mango(gg);

  // letsgo solve
  for (int i = 0; i < sz(bm); i++)
  {
    int res = -1;
    if(gg[C].first <= bm[i]) {cout << "-1\n"; continue;}
    for(int j = YSS-10; j > 0; j/=2) {
      while(j + res <= YSS-20 and gg[j+res].first <= bm[i]) res += j;
    }
    mango(bm[i]);
    mango(gg[res].first);
    cout << res+1 << ' ';

  }
    cout << '\n';
  
  
  
  



  
  
}