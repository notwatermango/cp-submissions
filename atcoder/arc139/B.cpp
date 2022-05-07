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

int gcd(int a, int b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}
int lcm(int a, int b) {
  return a*b/gcd(a,b);
}

void solv() {
  int n, a, b, x, y, z;
  cin >> n >> a >> b >> x >> y >> z;
  if (a < b) {
    swap(a, b), swap(y, z);
  }
  int res = n*x;
  /**
   *  +1      x 
   *  +a      y
   *  +b      z
   *  +ab     w
   */
  y = min(y, a*x);
  z = min(z, b*x);
  int ab = lcm(a, b);
  int w = min(ab/b*z, ab/a*y);


  mango(vector<int>({a, b, ab}));
  mango(vector<int>({y, z, w}));

  int cost = 0;

  int nab = max(n/ab-1, (int) 0);

  cost  += (nab)*w;
  n     -= (nab)*ab;

  mango(cost);

  mango(n);

  // `i` = a_suu
  #define b$ to_string(i) + " --> " + to_string(cand+cost);
  for (int i = 0; i*a <= n; ++i) {
    int cand  =   i*y;
    int b_bun =   n - (i*a);
    int b_suu =   b_bun/b;
    cand      +=  b_suu*z;
    b_bun     -=  b_suu*b;
    // nokoru
    cand      +=  b_bun*x;
    // mango(b_suu);
    // mango(b$);
    res       =   min(res, cand + cost);
  }
  cout << res << '\n';
}