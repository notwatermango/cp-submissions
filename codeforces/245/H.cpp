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
  string S; cin >> S;
  int n = sz(S);
  vector<vector<bool>> pal(n+5, vector<bool>(n+5));
  vector<vector<int>> dp(n+5, vector<int>(n+5));

  for (int i = 0; i < n+3; i++)
  {
    pal[i][i] = 1;
    pal[i+1][i] = 1; // 2 len pals
    dp[i][i] = 1;
  }

  for (int i = 2; i < n+1; i++) // len
  {
    for (int j = 0; j < n+1; j++)
    {
      if(j + i > n+1) break;
      if(pal[j+1][j+i-2] && S[j] == S[j+i-1]) {
        pal[j][j+i-1] = 1;
      }
      // len up
      // dp[j][j+i-1] = dp[j+1][j+i-1] + 1 + pal[j][j+i-1]; !! connected pals : am i a joke
      dp[j][j+i-1] = dp[j+1][j+i-1] + dp[j][j+i-2] - dp[j+1][j+i-2] + pal[j][j+i-1];
      // thx discrete math
    }
  }
  int q; cin >> q;
  for (int i = 0; i < q; i++)
  {
    int l,r;
    cin >> l >> r; 
    l--;r--;
    cout << dp[l][r] << '\n';
  }
  
  

}