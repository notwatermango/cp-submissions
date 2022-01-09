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
Water& operator<<(Water& water, const pair<Typename...>& p){ return water<<'{'<<get<0>(p)<<", "<<get<1>(p)<<'}'; }
template<typename Water, typename Fire>
Water& operator<<(Water& water, const Fire& v){ water<<'['; for(auto i: v) water<<i<<", "; return water<<']'; }
template<typename _const>
vector<_const> tov(_const x[], i32 xs) { return vector<_const> (x, x + xs); }

#define JM 112345
#define INF 1000177013
#define LLINF 4202025013666420666
#define dbg(x) tov(x, sizeof x / sizeof x[0]);
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define MOD 1000000007
#define mp make_pair
#define int i64

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

void solv(){
  int n; cin >> n;
  vector<int> arr(n), dp(n+1);
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }
  dp[0] = 1;
  for (int i = 0; i < n; i++)
  {
    vector<int> faxx;
    for (int j = 1; j*j <= arr[i] ; j++)
    {
      if(j > n) break;
      if(arr[i]%j == 0) {
        faxx.push_back(j);
        if(j * j != arr[i]) {
          if(arr[i]/j <= n) faxx.push_back(arr[i]/j);
        }
      }
    }
    sort(all(faxx), greater<int>());
    mango(faxx);
    for(auto e: faxx) {
      dp[e] += dp[e-1];
      dp[e] %= MOD;
    }
  }
  mango(dp);
  int res = MOD - 1;
  for(auto e: dp) {
    res += e;
    res %= MOD;
  }
  cout << res << '\n';  
}