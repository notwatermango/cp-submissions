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
#define notwatermango void solv();
i64 powllm(i64 a, i64 b, i64 m) { a %= m; i64 res = 1; while (b > 0) { if (b & 1) res = res * a % m; a = a * a % m; b >>= 1; } return res; }
i64 powll(i64 a, i64 b) { i64 res = 1; while (b > 0) { if (b & 1) res = res * a; a = a * a; b >>= 1; } return res; }
template<typename Water, typename ...Typename>
Water& operator<<(Water&water,pair<Typename...>&p){return water<<'{'<<get<0>(p)<<", "<<get<1>(p)<<'}';}
template<typename Water, typename Fire>
Water& operator<<(Water&water,vector<vector<Fire>>v){water<<"\n{\n";for(auto i:v){water<<"\t[ ";for(auto j: i)water\
// <<left<<setw(8) \M
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

notwatermango

signed main() {
  fastmango;
  i32 tc = 1;
  // cin >> tc;
  for(i32 i = 0; i < tc; ++i) {
    // cout << "Case #" << i+1 << ": ";
    solv();
  }
  return water;
}
vector<int> a;

bool ok(double x) {
  vector<double> b(sz(a));
  for (int i = 0; i < sz(b); i++) b[i] = (double)a[i]-x;
  vector dp(sz(b), vector<double>(2));
  // mango(b);
  dp[0][1] = b[0];
  for (int i = 0; i < sz(b); i++)
  {
    if(i - 1 > -1) {
      dp[i][0] = dp[i-1][1];
      dp[i][1] = dp[i-1][1] + b[i];
      dp[i][1] = max(dp[i][1], dp[i-1][0] + b[i]);
    }
    if(i - 2 > -1) {
      dp[i][1] = max(dp[i][1], dp[i-2][1] + b[i]);
    }
  }
  // mango(dp);
  double mx = max(dp.back()[1], dp.back()[0]);
  if(mx > 0) return true;
  return false;
}

bool ok2(int x) {
  vector b = a;
  int bg = 0, eq = 0;
  for (int i = 0; i < sz(b); i++) {
    if(b[i] > x) bg++;
    if(b[i] == x ) eq++;
  }
  int sm = sz(b) - bg - eq;
  // if(not eq) return false; nibuntansaku
  if(sm == bg || sm + 1 == bg) return true;
  // if(sm > bg) mango(sm);
  for (int i = 0; i < sz(b); i++)
  {
    // if sm > bg avoid sm
    if(sm > bg) {
      if(b[i] < x) b[i] = 1;
      else b[i] = 0;
    } 
    // if bg > sm avoid bg
    else {
      if(b[i] > x) b[i] = 1;
      else b[i] = 0;
    }
  }

  vector dp(sz(b), vector<int>(2));
  dp[0][1] = b[0];
  for (int i = 0; i < sz(b); i++)
  {
    if(i - 1 > -1) {
      dp[i][0] = dp[i-1][1];
      dp[i][1] = dp[i-1][0] + b[i];
      dp[i][1] = min(dp[i][1], dp[i-1][1] + b[i]);
    }
    if(i - 2 > -1) {
      dp[i][1] = min(dp[i][1], dp[i-1][1] + b[i]);
    }
  }
  int mn = min(dp.back()[0], dp.back()[1]);
  // mango(mn);
  if(sm < bg) {
    // take all sm
    // take eq too
    int took = sm+eq;
    // we must also take mn
    if(mn > took) {
      // then mid can't be x
      return false;
    } 
  } else {
    // take all bg and eq
    int took = bg + eq;
    // 
    if (mn >= took ) return false;
  }
  return true;


  

  

} 

void solv() {
  int n; cin >> n;
  a.assign(n, 0);
  int mz = 0;
  for (int i = 0; i < n; i++) cin >> a[i], mz = max(mz,a[i]);
  
  double avg = 0;
  for (double i = (double)INF; i > 0.0001; i/=2) {
    while(avg + i < (double)INF + 1 and ok(avg+i)) avg+=i;
  }
  cout << avg << '\n';
  vector b = a;
  sort(all(b));
  int mid = -1;
  for (int i = sz(b); i > 0; i/=2) {
    while(mid + i < sz(b) and ok2(b[mid + i])) mid+=i;
  }
  mango(mid);
  mango(ok2(3));
  mango(b[mid]);
  cout << b[mid] << '\n';
  



}