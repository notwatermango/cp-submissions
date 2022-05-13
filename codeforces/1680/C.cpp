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
  string sr; cin >> sr;
  int n = sz(sr);
  deque<char> s;
  for (int i = 0; i < n; ++i) {
    s.push_back(sr[i]);
  }
  // free pops
  while (not s.empty() and s.back() == '0') s.pop_back();
  while (not s.empty() and s.front() == '0') s.pop_front();
  n = sz(s);
  

  vector<pair<int,int>> pre(n);
  int c1,c0;
  c1 = c0 = 0;
  int a0 = 0;
  for (int i = 0; i < n; ++i) {
    if (s[i] == '0') c0++, a0++;
    else c1++;
    pre[i] = mp(c0,c1);
  }

  mango(pre);
  int mn = min(a0, n-a0);
  int cost = 0;
  int d1 = 0,d0 = a0;
  for (int i = 0; i < n; ++i) {
    if (s[i] == '0') d0--;
    else d1++;
    mn = min(mn, max(d1, d0));
  }
  for (int i = n-1; i > -1 ; --i) {
    if (s[i] == '0') c0--;
    else cost++;
    // max(cost, c0)
    mn = min(mn, max(cost, c0));
    if (cost > c0) break;

    int rest = -1;
    // ok when cost < c0
    for (int j = i; j > 0; j/=2) {
      while (rest + j < i and cost + pre[rest+j].second < c0 - pre[rest + j].first) rest += j;
    }
    int cand1,cand0;
    cand1 = cost + pre[rest].second;
    cand0 = c0 - pre[rest].first;
    mn = min(mn, max(cand1, cand0));
    if (rest + 1< i) {
      rest++;
      cand1 = cost + pre[rest].second;
      cand0 = c0 - pre[rest].first;
      mn = min(mn, max(cand1, cand0));
    }
  }
  cout << mn << '\n';

}