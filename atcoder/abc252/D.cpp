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
#define YSS                                          212345

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
/* fenw tree */
struct FenwickTree {
  vector<int> bit; // binary indexed
  int n;

  FenwickTree(int n) {
    this->n = n;
    bit.assign(n, 0);
  }

  FenwickTree(vector<int> a) : FenwickTree(a.size()) {
    for (size_t i = 0; i < a.size(); i++)
      add(i, a[i]);
  }

  int sum(int r) {
    int ret = 0;
    for (; r >= 0; r = (r & (r + 1)) - 1)
      ret += bit[r];
    return ret;
  }

  int sum(int l, int r) { return sum(r) - sum(l - 1); }

  void add(int idx, int delta) {
    for (; idx < n; idx = idx | (idx + 1))
      bit[idx] += delta;
  }
};
/* ~fenw tree */
void solv() {
  int n; cin >> n;
  vector<int> arr(n);
  FenwickTree greatez(YSS+1);
  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
    greatez.add(arr[i], 1);
  }
  sort(all(arr));
  int ls = 0;
  int res = 0;
  for (int i = 0; i < n; ++i) {
    if (i and arr[i-1] != arr[i]) {
      ls = i;
    }
    res += ls*greatez.sum(arr[i] + 1, YSS-1);
  }
  cout << res << '\n';
}