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
  // cin >> tc;
  for (i32 i = 0; i < tc; ++i) {
    // cout << "Case #" << i+1 << ": ";
    solv();
  }
  return water;
}

void solv() {
  int n; cin >> n;
  vector<int> arr1(n), arr2(n);
  map<int,int> fo1, fo2;
  for (int i = 0; i < n; ++i) {
    cin >> arr1[i];
    if (not fo1.count(arr1[i])) fo1[arr1[i]] = i;
  }
  for (int i = 0; i < n; ++i) {
    cin >> arr2[i];
    if (not fo2.count(arr2[i])) fo2[arr2[i]] = i;
  }
  vector<int> r1(n),r2(n);
  int mx = -1;
  for (int i = 0; i < n; ++i) {
    if (not fo2.count(arr1[i])) mx = LLINF;
    mx = max(mx, fo2[arr1[i]]);
    r1[i] = mx;
  }
  mx = -1;
  for (int i = 0; i < n; ++i) {
    if (not fo1.count(arr2[i])) mx = LLINF;
    mx = max(mx, fo1[arr2[i]]);
    r2[i] = mx;
  }
  mango(r1);
  mango(r2);
  int q; cin >> q;
  for (int i = 0; i < q; ++i) {
    int x,y; cin >> x >> y; x--, y--;
    mango(mp(x,y));
    if (r1[x] <= y and r2[y] <= x) cout << "Yes\n";
    else cout << "No\n";
  }


  // occurences


}