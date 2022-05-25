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
int abborz = 0;
int ask(int a, int b, int c) {
  cout << "? " << a << ' ' << b << ' ' << c << endl;
  int x; cin >> x;
  return x;
}
void solv() {
  int n; cin >> n;
  if (n == -1) {abborz =1; return;}
  // 0 ->>>>>>>>>>>>>>>>>>> IMPOSTOR 0 
  // 1 ->>>>>>>>>>>>>>>>>>> CREWMATE 1
  int evil, gg;
  for (int i = 1; i < n + 1; i += 3) {
    if (ask (i, i+1, i+2)) {
      gg = i;
    } else evil = i;
  }
  mango(gg);
  mango(evil);

  int a, b, c, d, e, f;
  a = b = c = evil;
  b++, c++, c++;
  d = e = f = gg;
  e++, f++, f++;

  // take f
  bool f_innocence = false;
  bool fac_not_sure = false;
  if (ask(f, a, c)) f_innocence = true, fac_not_sure= true;

  if (f_innocence) {
    gg = f;
    if (fac_not_sure) evil = b;
    else evil = a;
  } else {
    // EVIL F Orrrrrr maybe abc all evil
    if (ask(d, e, a) and ask(d, e, b)) {
      // evil f orrr maybe def all gg
      if (ask(f, e, a) and ask(f, e, b)) {
        // def all gg
        gg = f;
        evil = a;
      } else {
        evil = f;
        gg = e;
      }
    } else {
      evil = a;
      gg = f;
    }
  }
  vector<int> res;
  res.push_back(evil);

  // smoke now
  for (int i = 1; i < n + 1; ++i) {
    if (i == gg or i == evil) continue;
    if (not ask(gg, evil, i)) res.push_back(i);
  }
  cout << "! " << sz(res) << ' ';
  for (int i = 0; i < sz(res); ++i) {
    cout << res[i] << ' ';
  } cout << endl;
}