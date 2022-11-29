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
// <<left<<setw(8) \M
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
  int b, k, sx, sy, gx, gy;
  cin >> b >> k >> sx >> sy >> gx >> gy;
  // main road at bn, n = 0, 1, ...
  vector<pair<int, pair<int,int>>> cds, cdg;
  // cost, x, y

  // cds
  // let's find nearest bn from sx sy
  // to up, to y where y = bn <= sy
  int ups = sy / b * b;
  int downs = sy / b * b + b;
  int lefts = sx / b * b;
  int rights = sx / b * b + b;

  cds.emplace_back((sy - ups) * k, mp(sx, ups));
  cds.emplace_back((downs - sy) * k, mp(sx, downs));
  cds.emplace_back((sx - lefts) * k, mp(lefts, sy));
  cds.emplace_back((rights - sx) * k, mp(rights, sy));

  int upg = gy / b * b;
  int downg = gy / b * b + b;
  int leftg = gx / b * b;
  int rightg = gx / b * b + b;
  cdg.emplace_back((gy - upg) * k, mp(gx, upg));
  cdg.emplace_back((downg - gy) * k, mp(gx, downg));
  cdg.emplace_back((gx - leftg) * k, mp(leftg, gy));
  cdg.emplace_back((rightg - gx) * k, mp(rightg, gy));
  // mango(cdg);
  // cds and cdg are all in line
  int n = 4;
  int ans = abs(gx - sx) + abs(gy - sy);
  ans *= k;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      int linecost = LLINF;
      // case one of them in intersection
      if (
        (cds[i].second.second % b == 0 and cds[i].second.first % b == 0)
      or(cdg[j].second.second % b == 0 and cdg[j].second.first % b == 0)
      ) {
        linecost = min(linecost, 
          abs(cds[i].second.second - cdg[j].second.second)
        + abs(cds[i].second.first - cdg[j].second.first)
        + cds[i].first + cdg[j].first 
        );
      } 
      // one col one row
      else if (
        (
          (cds[i].second.second % b == 0 and cds[i].second.first % b != 0)
        &&(cdg[j].second.second % b != 0 and cdg[j].second.first % b == 0)
        )
      or
        (
          (cds[i].second.second % b != 0 and cds[i].second.first % b == 0)
        &&(cdg[j].second.second % b == 0 and cdg[j].second.first % b != 0)
        )
      ) {
        linecost = min(linecost, 
          abs(cds[i].second.second - cdg[j].second.second)
        + abs(cds[i].second.first - cdg[j].second.first) 
        + cds[i].first + cdg[j].first 
        );
      }
      // same col
      else if (
        cds[i].second.second / b * b == cdg[j].second.second / b * b and
        cds[i].second.first / b * b != cdg[j].second.first / b * b 
      ) {
        // go left
        linecost = min(linecost,
        cds[i].second.second - cds[i].second.second / b * b
        + cdg[j].second.second - cdg[j].second.second / b * b
        + abs(cds[i].second.first - cdg[j].second.first)
        + cds[i].first + cdg[j].first
        );
        // go right
        linecost = min(linecost,
        abs(cds[i].second.second - (cds[i].second.second / b * b + b))
        + abs(cdg[j].second.second - (cdg[j].second.second / b * b + b))
        + abs(cds[i].second.first - cdg[j].second.first)
        + cds[i].first + cdg[j].first
        );
      }
      // same row
      else if (
        cds[i].second.first / b * b == cdg[j].second.first / b * b and
        cds[i].second.second / b * b != cdg[j].second.second / b * b
      ) {
        // go up
        linecost = min(linecost,
        cds[i].second.first - cds[i].second.first / b * b
        + cdg[j].second.first - cdg[j].second.first / b * b
        + abs(cds[i].second.second - cdg[j].second.second)
        + cds[i].first + cdg[j].first
        );
        // go down
        linecost = min(linecost,
        abs(cds[i].second.first - (cds[i].second.first / b * b + b))
        + abs(cdg[j].second.first - (cdg[j].second.first / b * b + b))
        + abs(cds[i].second.second - cdg[j].second.second)
        + cds[i].first + cdg[j].first
        );
      } 
      else {
        linecost = min(linecost, 
          abs(cds[i].second.second - cdg[j].second.second)
        + abs(cds[i].second.first - cdg[j].second.first) 
        + cds[i].first + cdg[j].first 
        );
      }

      ans = min(ans, linecost);
    }
  }
  cout << ans << '\n';


}