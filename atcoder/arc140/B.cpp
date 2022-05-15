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
  string s; cin >> s;
  // let's find R
  set<pair<int,int>> S;
  for (int i = 0; i < n; ++i) {
    if (s[i] == 'R') {
      // left
      int ca = 0;
      int j = i;
      while (j - 1 > -1 and s[j-1] == 'A') {
        ca++;
        j--;
      }
      int cc = 0;
      j = i;
      while (j + 1 < n and s[j+1] == 'C') {
        cc++;
        j++;
      }
      if (min(ca, cc) == 0) continue;
      S.insert(mp(min(ca, cc), i));
    }
  }
  mango(S);
  int ct = 0;
  while (not S.empty()) {
    // 1st operation
    auto it = S.end();
    it = prev(it);
    pair<int,int> qq = *it;
    pair<int,int> nx = mp(qq.first-1, qq.second);
    S.erase(it);
    if (nx.first != 0) {
      S.insert(nx);
    }
    mango("First op");
    mango(S);
    ct++;
    if (S.empty()) break;

    // 2nd operation
    it = S.begin();
    qq = *it;
    nx = mp(qq.first-1, qq.second);
    S.erase(it);
    // if (nx.first != 0) {
    //   S.insert(nx);
    // }
    mango("Second op");
    mango(S);
    ct++;

  }
  mango(ct);
  cout << ct << '\n';
}