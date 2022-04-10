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

int n,x,y;
vector<int> arr;
void solv() { 
  cin >> n >> x >> y;
  arr.resize(n);
  // xmax ymin
  vector<int> bad;
  vector<int> vx,vy;
  int ct = 0;
  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
    if(x == y and arr[i] == x) ct++;
    if(arr[i] > x or arr[i] < y) bad.push_back(i);
    if(arr[i] == x) vx.push_back(i);
    if(arr[i] == y) vy.push_back(i);
  }
  mango(bad);
  mango(vx);
  mango(vy)
  if(vx.empty() or vy.empty()) {
    cout << "0\n"; return;

  }
  int res = 0;
  for (int r = 1; r < n; ++r) {
    auto itx = lower_bound(all(vx), r);
    if(itx == vx.begin() and *itx > r) continue;
    if(itx != vx.begin() and *itx != r) --itx;
    // itx max x but not greater than r
    auto ity = lower_bound(all(vy), r);
    if(ity == vy.begin() and *ity > r) continue;
    if(ity != vy.begin() and *ity != r) --ity;
    // itx max y but not greater than r
    mango(*itx);
    mango(*ity);
    int l = min(*itx, *ity);
    mango(mp(l,r));

    int badleft = -1;
    
    if(not bad.empty()) {
      auto itbad = upper_bound(all(bad), r);
      if(itbad == bad.begin()) {/*ok*/}
      else {
        --itbad;
        mango(*itbad);
        badleft = *itbad;
      }
    }
    mango(badleft);
    if(badleft > l) continue;

    res += l - badleft;

    
  }
  if(x == y and arr[0] == x) {
    res++;
  }
  cout << res << '\n';


}