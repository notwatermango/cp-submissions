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

int h,l,r;

bool ok(int a) {
  a += h;
  a %= h;
  return (a >= l && a <= r);
}

void solv(){
  int n; cin >> n;
  cin >> h >> l >> r;
  vector<int> arr(n), sum(n);
  int al = 0;
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
    al += arr[i];
    // al %= h;
    sum[i] = al;
  }
  vector<vector<int>> dp(n+1, vector<int>(n+1));
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j <= i; j++)
    {
      int ggf = ok(sum[i] - j);
      int ggh = ok(sum[i] - j - 1);
      dp[i+1][j] = max(dp[i+1][j], dp[i][j] + ggf);
      dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][j] + ggh);
    }
  }
  int mx = 0;
  for (int i = 0; i < n+1; i++)
  {
    mx = max(mx, dp[n][i]);
  }
  cout << mx << '\n';
  mango(dp);
  
  
}