#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
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
int n; 

typedef tree< pair<int,int>, null_type, less<pair<int,int>>, rb_tree_tag, tree_order_statistics_node_update > ordered_set;

void solv() {
  cin >> n;
  int k; cin >> k;
  vector<pair<int,int>> arr(k);
  ordered_set a;
  for (int i = 0; i < k; ++i) {
    cin >> arr[i].first;
    arr[i].second = i;
  }
  map<int,vector<int>> indexes;
  for (int i = k; i < n; ++i) {
    int x; cin >> x;
    indexes[x].push_back(i);
    a.insert(mp(i, x));
  }
  int pijak = 0;
  sort(all(arr), [](pair<int,int> a, pair<int,int> b){
    if(a.first == b.first) return a.second > b.second;
    return a.first < b.first;
  });
  mango(arr);
  mango(a);
  int mn = LLINF;
  for (int i = 0; i < k; ++i) {
    if(arr[i].first <= pijak) continue;
    pijak = arr[i].first;
    
    while (not indexes.empty() and indexes.begin()->first <= pijak) {
      // del all
      while (not indexes.begin()->second.empty()) {
        int todel = indexes.begin()->second.back();
        indexes.begin()->second.pop_back();
        a.erase(a.lower_bound(mp(todel, 0)));
      }
      indexes.erase(indexes.begin());
    }
    if(not a.empty()) mn = min(mn, a.begin()->first - arr[i].second);
  }
  mango(a);
  if(mn == LLINF) cout << "-1\n";
  else cout << mn << '\n';
}