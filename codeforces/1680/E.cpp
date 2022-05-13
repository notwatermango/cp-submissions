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

void solv() {
  int n; cin >> n;
  vector<vector<char>> arr(n, vector<char>(2));
  int mnr = LLINF;
  for (int i = 0; i < n; ++i) {
    cin >> arr[i][0];
  }
  for (int i = 0; i < n; ++i) {
    cin >> arr[i][1];
  }
  if (n == 1) {
    int wow = (arr[0][0] == '*') + (arr[0][1] == '*');
    cout << max((int) 0, wow-1) << '\n';
    return;
  }
  for (int i = 0; i < n; ++i) {
    if (arr[i][0] == '*' or arr[i][1] == '*') {
      mnr = i;
      break;
    }
  }
  int sadge = LLINF;
  for (int i = n-1; i > -1 ; --i) {
    if (not (arr[i][0] == '.' and arr[i][1] == '.')) {
      sadge = i;
      break;
    }
  }
  if (sadge == 0) {
    int wow = (arr[0][0] == '*') + (arr[0][1] == '*');
    cout << max((int) 0, wow-1) << '\n';
    return;
  }
  mango(sadge);
  vector<vector<int>> dp(n, vector<int>(2, LLINF));
  // let dp_(ij) = moves needed to clean up ith col ending in jth row
  dp[mnr][0] = (arr[mnr][1] == '*' ? 1 : arr[mnr][0] == '*' ? 0 : LLINF);
  dp[mnr][1] = (arr[mnr][0] == '*' ? 1 : arr[mnr][1] == '*' ? 0 : LLINF);
  #define chmin(a, b) a = min(a, b)
  int res = -1;
  for (int i = 0; i < n-1; ++i) {
    if (dp[i][0] != LLINF) {
      chmin(dp[i+1][0], dp[i][0] + 1 + (arr[i+1][1] == '*' ? 1: 0));
      chmin(dp[i+1][1], dp[i][0] + 2);
    } 

    if (dp[i][1] != LLINF) {
      chmin(dp[i+1][0], dp[i][1] + 2);
      chmin(dp[i+1][1], dp[i][1] + 1 + (arr[i+1][0] == '*' ? 1: 0));
    }
    if (dp[i+1][0] != LLINF and i+1 <= sadge) {
      res = max(res, min(dp[i+1][0], dp[i+1][1]));
    }
  }
  mango(dp);
  cout << res << '\n';

}