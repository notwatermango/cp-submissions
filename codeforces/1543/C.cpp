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
double v;
double res = 0;

map<string,bool> vis;

void lesgo(double c, double m, double p, int q, double rr, string now) {
  if(vis[now])return;
  vis[now] = true;
  // case take p
  res += rr*p*q;
  now.push_back('P');
  #ifdef debug
  mango(now);
  mango(c);
  mango(m);
  mango(p);
  mango(rr*p);
  #endif
  now.pop_back();
  if (rr < 1e-12) return;
  // mango(c + m + p);
  if (c == 0 and m == 0) return;
  // mango(rr);
  // mango(p);
  // mango(q);
  q++;
  // case take c
  double c1 = c-v;
  now.push_back('C');
  if (c == 0) {

  } else if (c1 < 1e-6) {
    double mm = m+c/2;
    double pp = p+c/2;
    if (m == 0) mm = 0, pp = p + c;
    lesgo(0, mm, pp, q, rr*c, now);
  } else {
    if (m == 0) lesgo(c1, 0, p+v, q, rr*c, now);
    lesgo(c1, m+v/2, p+v/2, q, rr*c, now);
  }

  now.pop_back();
  now.push_back('M');
  // case take m
  double m1 = m-v;
  if (m == 0) {

  } else if (m1 < 1e-6) {
    double cc = c+m/2;
    double pp = p+m/2;
    if (c == 0) cc = 0, pp = p + m;
    lesgo(cc, 0, pp, q, rr*m, now);
  } else {
    if (c == 0) lesgo(0, m1, p+v, q, rr*m, now);
    else lesgo(c+v/2, m1, p+v/2, q, rr*m, now);
  }


}

void solv() {
  int n; cin >> n;
  vis.clear();
  res = 0;
  precisemango(10);
  double c,m,p; cin >> c >> m >> p >> v;
  lesgo(c,m,p,1,1,"");
  cout << res << '\n';

}