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
#define INF 2
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

#define double long double

void solv(){
  cout << fixed << setprecision(9);
  int r, s, p;
  cin >> r >> s >> p;
  double dp[r+1][s+1][p+1];
  for(int i = 0; i < r+1; ++i) for(int j = 0; j < s+1; ++j) for(int k = 0; k < p+1; ++k) dp[i][j][k] = 0;
  dp[r][s][p] = 1;
  for (int sum = r+s+p+1 - 1; sum >= 0; sum--)
  {
    for (int j = s+1 - 1; j >= 0; j--)
    {
      for (int k = p+1 - 1; k >= 0; k--)
      {
        int i = sum - j - k;
        if(i < 0 || i > r) continue;
        if(i == 0 && j == 0) continue;
        if(j == 0 && k == 0) continue;
        if(i == 0 && k == 0) continue;
        double ij,jk,ik;
        ij = i * j;
        jk = j * k;
        ik = i * k;
        double al = ij + jk + ik;
        if(al == 0) continue;
        double pij = ij/al;
        double pjk = jk/al;
        double pik = ik/al;
        mango(pik);
        dp[i][j][k-1] += dp[i][j][k] * pjk;
        dp[i][j-1][k] += dp[i][j][k] * pij;
        dp[i-1][j][k] += dp[i][j][k] * pik;
      }
    }
  }
  for (int i = 0; i < r+1; i++)
  {
    for (int j = 0; j < s+1; j++)
    {
      for (int k = 0; k < p+1; k++)
      {
        // mango(i);
        // mango(j);
        // mango(k);
        if(dp[i][j][k] != 0) {
          // cout << i << ' ' << j << ' ' << k << '\n' ;
          // cout << dp[i][j][k] << '\n';
        }
      }
      // cout << "p";
      
    }
    // cout << '\n';
    
  }
  double rr, ss, pp;
  rr = ss = pp = 0;
  for(int i = 0; i < r + 1; ++i) rr += dp[i][0][0];
  for(int i = 0; i < s + 1; ++i) ss += dp[0][i][0];
  for(int i = 0; i < p + 1; ++i) pp += dp[0][0][i];
  cout << rr << ' ' << ss << ' ' << pp << '\n';


}