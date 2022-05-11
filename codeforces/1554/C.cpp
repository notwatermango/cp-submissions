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
<<left<<setw(4) \
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

string bitz(int x) {
  return bitset<14>(x).to_string();
}

// void solv() {
void solv2() {
  int n, m; cin >> n >> m;
  mango(bitz(n));
  mango(bitz(m));
}

void solv3() {
// void solv2() {
  int n = 69, m = 696;
    int k = 640;
  cin >> n >> m >> k;
    mango(bitz(n));
    mango(bitz(m)); 
    mango(bitz(k));
    mango(bitz(k^n));
  for (int i = 0; i <= m; ++i) {
    cout << setw(3) << (i^n) << ' ';
  }
  return;
  // int n; cin >> n;
  for (int zor = 0; zor < 12; ++zor) {
    for (int i = 0; i < n; ++i) {
      cout << setw(4) << (i ^ zor) << ' ';
    }
    cout << '\n';
  }
}

void solv() {
  int n, m; cin >> n >> m;
  mango(bitz(n));
  mango(bitz(m));
  // ans = n ^ x
  // x > m
  int super_min_x = m+1;
  // cand = super_min_x but all 1
  int cand = super_min_x;
  string w = bitset<40>(cand).to_string();
  bool ok = 0;
  for (int i = 0; i < sz(w); ++i) {
    if (w[i] == '1') ok = 1;
    if (ok) w[i] = '1';
  }
  cand = bitset<40>(w).to_ullong();
  mango(bitz(cand));

  // make cand^n smaller
  for (int i = 40; i > -1; --i) {
    // care for i'th bit
    int onz = ((int)1 << i);
    if ((onz & cand) != (onz & n)) {
      // try to make bit i of cand same
      int tryz = cand ^ onz;
      if (tryz >= super_min_x) {
        cand = tryz;
      }
    }
  }
  mango(bitset<40>(cand).to_string());
  cout << (cand^n) << '\n';

}