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

// /* lprime */
// const int pN = 1e5 + 10;           // 0.2 s
// vector<int> lprime(pN+1);         /* ! lprime[0] == 0; ! */
// vector<int> przs;
// void init_lprime() {
//   for (int i = 2; i <= pN; ++i) {
//     if (lprime[i] == 0) {
//       lprime[i] = i;
//       przs.push_back(i);
//     }
//     for (int j = 0; j < sz(przs) and przs[j] <= lprime[i] && i * przs[j] <= pN; ++j) lprime[i * przs[j]] = przs[j];
//   }
// }
// /* ~lprime */

/* divisor */
// const int dN2 = 4e6 + 10;
// const int dN = sqrtl(dN2) + 10;
// vector<set<int>> divzs(dN2+1);
// void init_divisor() {
//   for (int i = 2; i <= dN; ++i) {
//     for (int j = i; j*i <= dN2; ++j) {
//       divzs[j*i].insert(i);
//       divzs[j*i].insert(j);
//     }
//   }
// }
/* ~divisor */
#define int i64

void solv() {
  #if _if
  // init_divisor();
  for (i32 i = 0; i < sz(divzs); ++i) {
    mango(i);
    mango(divzs[i]);

  }
  return;
  #endif
  int n, m; cin >> n >> m;
  int sw = 0;
  vector<int> fml(n+1);
  vector<i32> dp(n+1);
  dp[1] = 1;
  // fml[2] = 1;
  for (int i = 2; i <= n; ++i) {
    // add f(x) to fml when x divides i
    // sub f(x-1) fr fml when x divides i
    fml[i] += fml[i-1] + 1;

    sw += dp[i-1];
    sw %= m;
    dp[i] = (i32)((sw + fml[i]) % m);
    for (int j = 2; j*i <= n; ++j) {
      fml[i*j] += dp[i];
      fml[i*j] -= dp[i-1];
    }
  }
  // mango(dp);
  cout << dp[n] << '\n';

  
}