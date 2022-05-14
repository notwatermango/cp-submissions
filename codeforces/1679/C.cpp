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
  FenwickTree fa(n+2), fb(n+2);
  FenwickTree fseta(n+2), fsetb(n+2);
  mango(n);
  int q; cin >> q;
  for (int i = 0; i < q; ++i) {
    int x1,y1;
    int cmd; cin >> cmd;
    if (cmd == 1) {
      cin >> x1 >> y1;
      if (not fa.sum(x1, x1)) fseta.add(x1, 1);
      if (not fb.sum(y1, y1)) fsetb.add(y1, 1);
      fa.add(x1, 1);
      fb.add(y1, 1);
    } else if (cmd == 2) {
      cin >> x1 >> y1;
      fa.add(x1, -1);
      fb.add(y1, -1);
      if (not fa.sum(x1, x1)) fseta.add(x1, -1);
      if (not fb.sum(y1, y1)) fsetb.add(y1, -1);
    } else if (cmd == 3) {
      int x2, y2;
      cin >> x1 >> y1 >> x2 >> y2;
      int xx = fseta.sum(x1, x2);
      int yy = fsetb.sum(y1, y2);
      mango(xx);
      mango(yy);
      if (xx == x2-x1+1 || yy == y2-y1+1) { 
        cout << "Yes\n"; 
      } else cout << "No\n";
    }
  }
}