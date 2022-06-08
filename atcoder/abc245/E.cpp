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
  for(i32 i = 0; i < tc; ++i) {
    // cout << "Case #" << i+1 << ": ";
    solv();
  }
  return water;
}

void solv() {
  int n; cin >> n; int m;cin>>m;
  vector<pair<int,int>> choc(n),box(m);
  for (int i = 0; i < n; i++)
  {
    cin >> choc[i].first;
  }for (int i = 0; i < n; i++)
  {
    cin >> choc[i].second;
  } vector<int> ww(m),hh(m);
  for (int i = 0; i < m; i++)
  {
    cin >> box[i].first;
    ww[i] = box[i].first;
  }for (int i = 0; i < m; i++)
  {
    cin >> box[i].second;
    hh[i] = box[i].second;
  }

  // compress
  // sort(all(ww));
  // sort(all(hh));
  // map<i32,i32> pw,ph;
  // for (int i = 0; i < m; i++)
  // {
  //   pw[ww[i]] = i;
  //   ph[hh[i]] = i;
  // }
  // for (int i = 0; i < m; i++)
  // {
    // box[i] = mp(pw[box[i].first], ph[box[i].second]);
  // }
  sort(all(box), greater<pair<int,int>>());
  sort(all(choc), greater<pair<int,int>>());
  int p = 0;
  mango(box);
  multiset<int> ms;
  for (int i = 0; i < n; i++)
  {
    while(p < m and box[p].first >=  choc[i].first){
      ms.insert(box[p].second);
      p++;
    }
    if(ms.empty()) {cout << "No\n"; return;}
    auto it = ms.lower_bound(choc[i].second);
    if(it == ms.end()) {cout <<"No\n"; return;}
    ms.erase(it);
  }
  cout << "Yes\n";
  

  
  
  
  
  
  
  
  
  
  
}