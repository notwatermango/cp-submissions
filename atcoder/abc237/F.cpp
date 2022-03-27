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
#define MOD                                          998244353
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

void solv(){
  int n,m;
  cin >> n >> m;
  vector dp(n+1, vector<vector<vector<int>>>(m+1, vector<vector<int>>(m+1, vector<int>(m+1))));
  dp[0][m][m][m] = 1;
  for (int i = 0; i < n; i++)
  {
    for (int a0 = 0; a0 < m+1; a0++)
    {
      for (int a1 = 0; a1 < m+1; a1++)
      {
        for (int a2 = 0; a2 < m+1; a2++)
        {
          for (int j = 0; j < m; j++)
          {
            if(j <= a0) dp[i+1][j][a1][a2] += dp[i][a0][a1][a2];
            else if(j <= a1) dp[i+1][a0][j][a2] += dp[i][a0][a1][a2];
            else if(j <= a2) dp[i+1][a0][a1][j] += dp[i][a0][a1][a2];
            dp[i+1][j][a1][a2] %= MOD;
            dp[i+1][a0][j][a2] %= MOD;
            dp[i+1][a0][a1][j] %= MOD;
          }
        }
      }
    }
  }
  int ans = 0;
  for (int a0 = 0; a0 < m; a0++)
  {
    for (int a1 = a0+1; a1 < m; a1++)
    {
      for (int a2 = a1+1; a2 < m; a2++)
      {
        ans += dp[n][a0][a1][a2];
        ans %= MOD;
      } 
    }  
  }
  cout << ans << '\n';

  
  


}