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

void solv() {
  #if bruhmoment
  for (int i = 1; i <= 20; ++i) {
    int ml = 0;
    for (int j = 2; j <= i; ++j) {
      ml += i/j;
    }
    #define ww to_string(i) + " " + to_string(ml)
    mango(ww);
  }
  #endif

  int n, m; cin >> n >> m;
  // int n = 5, m = 100000;
  int sw;
  // 1
  sw = 1;
  vector<int> dp(n+1);
  dp[1] = 1;
  for (int i = 2; i < n + 1; ++i) {
    // what to do with ml
    int ml = 0;
    for (int j = 1; j * j <= i; ++j) {
      int l = j;
      int r = i/j;
       if(i==15) mango(mp(l,r));
      int next_l = l+1;
      int next_r = i/next_l;
      ml += dp[l]*(r-next_r);
      if (r != l) ml += dp[r];
      if (next_r < next_l) {
        if (i==15)mango(mp(next_l, next_r));
        break;
      }
      if(i==15) {
        mango(mp(r, next_r));
        mango(ml);
      }
      ml %= m;
    }
    ml %= m;
    dp[i] = sw + ml; dp[i] %= m;
    if (i==15) mango(mp(sw, ml));
    sw += dp[i]; sw %= m;
  }
  mango(dp);
  cout << dp[n] % m << '\n';
}