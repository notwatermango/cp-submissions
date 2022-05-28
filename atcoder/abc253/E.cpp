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
#define MOD                                          998244353
#define YSS                                          112345

notwatermango;

class mint {
  int x;
public:
  mint(int x=0) : x((x%MOD+MOD)%MOD) {}
  mint operator-() const { return mint(-x); }
  mint& operator+=(const mint& a) { if ((x += a.x) >= MOD) x -= MOD; return *this; }
  mint& operator-=(const mint& a) { if ((x += MOD-a.x) >= MOD) x -= MOD; return *this; }
  mint& operator*=(const  mint& a) { (x *= a.x) %= MOD; return *this; }
  mint operator+(const mint& a) const { mint res(*this); return res+=a; }
  mint operator-(const mint& a) const { mint res(*this); return res-=a; }
  mint operator*(const mint& a) const { mint res(*this); return res*=a; }
  mint pow(int t) const { if (!t) return 1; mint a = pow(t>>1); a *= a; if (t&1) a *= *this; return a; }
  mint inv() const { return pow(MOD-2); }
  mint& operator/=(const mint& a) { return (*this) *= a.inv(); }
  mint operator/(const mint& a) const { mint res(*this); return res/=a; }
  friend ostream& operator<<(ostream& os, const mint& m){ os << m.x; return os; }
};

#define int mint


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
  i32 n;

  FenwickTree(i32 n) {
    this->n = n;
    bit.assign(n, (int)0);
  }

  FenwickTree(vector<int> a) : FenwickTree(a.size()) {
    for (size_t i = 0; i < a.size(); i++)
      add(i, a[i]);
  }

  int sum(i64 r) {
    int ret = 0;
    for (; r >= 0; r = (r & (r + 1)) - 1) {
      ret += bit[r];
    }
    return ret;
  }

  int sum(i64 l, i64 r) { return sum(r) - sum(l - 1) + MOD; }

  void add(i64 idx, int delta) {
    for (; idx < n; idx = idx | (idx + 1)) {
      bit[idx] += delta;
    }
  }
};
/* ~fenw tree */
void solv() {
  i32 n, m, k;
  cin >> n >> m >> k;
  vector<FenwickTree> ft(n, FenwickTree(m+2));
  for (i32 i = 1; i <= m; ++i) ft[0].add(i, 1);
  for (i32 i = 1; i < n; ++i) {
    for (i32 j = 1; j <= m; ++j) {
      int lower = ft[i-1].sum(0, max(j - k, (i32)0));
      int upper = ft[i-1].sum(min(j + k, (i32)m+1), m+1);
      if (k == 0) {
        ft[i].add(j, ft[i-1].sum(m+1));
      } else {
        ft[i].add(j, lower + upper);
      }
    }
  }
  int a = 10, b = 5;
  cout << ft[n-1].sum(m) << '\n';
}