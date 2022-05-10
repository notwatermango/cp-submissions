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

void solv() {
  int n; cin >> n;
  // int ct = 0;
  // #define debug
  #ifdef debug
  map<int,int> pp;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      if (i % j != 0) {
        // if (j == 7) {ct++; mango(i); return;}
        // if (j == 8) {mango(ct);return;}
        // for (int k = 0; k < j; ++k) {
          // cout << ' ';
        // }
        // cout << j << '\n';
        pp[j]++;
        break;
      }
    }
  }
  #endif
  vector<int> cands;
  map<int,int> lprime;
  for (int i = 2; i < 100; ++i) {
    set<int> facts;
    int nn = i;
    for (int j = 2; nn > 1; ++j) {
      while (nn % j == 0 and nn) {
        facts.insert(j);
        nn/=j;
      }
    }
    if (facts.size() < 2) {
      cands.push_back(i);
      if (facts.empty()) lprime[i] = i;
      else lprime[i] = *(facts.begin());
    }
  }
  vector<int> dl, dr;
  dl.push_back(1);
  dr.push_back(2);
  for (int i = 1; i < sz(cands); ++i) {
    dl.push_back(dr[i-1]);
    dr.push_back(dl[i]*lprime[cands[i]]);
    if (dr[i] > 1e16+5) break;
  }
  mango(dl);
  mango(dr);

  // mango(lprime);
  // mango(cands);
  #ifdef debug
  for (auto e: pp) {
    mango(e);
  }
  #endif
  int res = 0;
  for (int i = 0; i < sz(dl); ++i) {
    res += cands[i] * (n/dl[i] - n/dr[i]) % MOD;
    res %= MOD;
  }
  cout << res << '\n';
  // cout << "2: " << n/2 << '\n';
  // cout << "3: " << n/2 - n/6 << '\n';
  // cout << "4: " << n/6 - n/12 << '\n';
  // cout << "5: " << n/12 - n/60 << '\n';
  // cout << "7: " << n/60 - n/420 << '\n';
  // cout << "8: " << n/420 - n/840 << '\n';
  // cout << "9: " << n/840 - n/2520 << '\n';
  // cout << "11: " << n/2520 - n/27720 << '\n';
  // cout << "13: " << n/27720 - n/360360 << '\n';
}