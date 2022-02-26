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
// template<typename Water, typename Fire>
// Water& operator<<(Water&water,Fire&v){water<<'[';for(auto i: v)water<<i<<", ";return water<<']';}
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
map<int,int> bruh;
int ncr(int n, int r){
  if(n<r || n<0 || r<0) return 0;
  if(bruh.count(n)) return bruh[n];
  // return fac[n]*finv[r]%MOD*finv[n-r]%MOD;
  int res = finv[r]%MOD;
  for (int i = 0; i < r; i++)
  {
    res *= n-i;
    res%=MOD;
  }
  return bruh[n] = res;
}
/* ~nCr*/

void solv(){
  int n; cin >> n;
  int k; cin >> k;
  int arr[n];
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }
  for (int i = 1; i < n; i++)
  {
    arr[0]-=arr[i];
  }

  arr[0] -= k;
  if(arr[0] < 0 ) {
    cout << "0\n";
    return;
  }

  int res = 1;

  c_init();
  for (int i = 0; i < n; i++)
  { 
    res*= ncr(arr[i]+k-1, k-1);
    res%=MOD;
  }

  cout << res << '\n';
  







  
}
