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
Water& operator<<(Water&water,vector<vector<Fire>>v){water<<"\n{\n";for(auto i:v){water<<"\t[ ";for(auto j: i)water<<j<<' ';water<<"]\n";};return water<<"}";}
template<typename Water, typename Fire>
Water& operator<<(Water&water,Fire&v){water<<'[';for(auto i: v)water<<i<<", ";return water<<']';}
template<typename Mango>
vector<Mango> tov(Mango x[], i32 xs) { return vector<Mango> (x, x + xs); }

#define YSS                                                   5005
#define INF                                                   1000177013
#define LLINF                                                 4202025013666420666
#define dbg(x) tov(x, sizeof x / sizeof x[0]);
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define MOD                                                   998244353
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

/* nCr */
vector<int> fac,finv,inv;

void c_init() {
  fac.resize(YSS);
  finv.resize(YSS);
  inv.resize(YSS);
  fac[0] = fac[1] = 1;
  inv[1] = 1;
  finv[0] = finv[1] = 1;
  for(int i=2; i<YSS; i++){
    fac[i] = fac[i-1]*i%MOD;
    inv[i] = MOD-MOD/i*inv[MOD%i]%MOD;
    finv[i] = finv[i-1]*inv[i]%MOD;
  }
}
int c(int n, int r){
  if(n<r || n<0 || r<0) return 0;
  return fac[n]*finv[r]%MOD*finv[n-r]%MOD;
}
/* ~nCr*/

void solv(){
  string S; cin >> S;
  int n = sz(S);
  c_init();
  vector<int> ctr(26);
  for (int i = 0; i < n; i++)
  {
    ctr[S[i] -'a']++;
  }
  

  vector<vector<int>> dp(27, vector<int>(n+1));
  dp[0][0] = 1;
  int sum = 0;
  for (int i = 0; i < 26; i++)
  {
    for (int j = 0; j <= n; j++)
    {
      for (int k = 0; k <= ctr[i]; k++)
      {
        if(j+k > n) break;
        dp[i+1][j+k] += dp[i][j] * c(j+k,j) % MOD;
        dp[i+1][j+k] %= MOD;
      }
      
    }
    
    
  }
  int res = 0;
  for (int i = 1; i <= n; i++)
  {
    res += dp[26][i];
  }
    res %= MOD;
  mango(dp);
  cout << res << '\n';
  
}