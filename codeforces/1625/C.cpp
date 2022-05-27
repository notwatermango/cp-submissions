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
#define chmin(a, b) a = min(a,b)
using P = pair<int,int>;


void solv() {
  int n, l, K;
  cin >> n >> l >> K;
  vector dp(n+1, vector(n+1, (int)LLINF));
  vector<int> pos(n+1), spd(n+1);
  for (int i = 0; i < n; ++i) cin >> pos[i];
  for (int i = 0; i < n; ++i) cin >> spd[i];
  pos[n] = l;
  dp[0][0] = 0;
  // take i-th sign, removed j sign
  for (int i = 1; i <= n; ++i) {
    dp[i][0] = dp[i-1][0] + spd[i-1]*(pos[i] - pos[i-1]);
    for (int j = 0; j < i; ++j) {
      chmin(
        dp[i][i-1],
        dp[0][0] + spd[0]*(pos[i]-pos[0])
      );
      chmin(
        dp[i][j],
        dp[i-1][j] + spd[i-1]*(pos[i] - pos[i-1])
      );
      for (int k = 0; k < j; ++k) {
        // use dp[j][k] to minimize dp[i]...
        mango(dp[j][k]);
        mango(mp(j, k));
        mango(k + (i-j));
        chmin(
          dp[i][k + (i-j-1)],
          dp[j][k] + spd[j]*(pos[i]-pos[j])
        );
      }

    }
  }
  mango(dp);
  int mn = LLINF;
  for (int i = 0; i <= K; ++i) {
    mn = min(mn, dp.back()[i]);
  }
  cout << mn << '\n';

}