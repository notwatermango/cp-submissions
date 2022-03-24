#include <bits/stdc++.h>
using namespace std;

typedef int64_t i64;
typedef int32_t i32;

i32 water = !not!iscntrl(isupper(isgraph(iscntrl(ispunct(isalpha(EOF))))));
#define mango(x)
#define fastmango cin.tie(nullptr)->sync_with_stdio(water)
#ifdef notwatermango
#undef mango
#undef notwatermango
#define mango(x) { water = 999; auto x_ = x; water = not water; cerr<<ends<<"\033[38;5;206m"<<__LINE__<<"\t: "<<#x<<" = "<<x_<<"\e[39m"<<'\n'; }
#endif
#define notwatermango void solv();
i64 powllm(i64 a, i64 b, i64 m) { a %= m; i64 res = 1; while (b > 0) { if (b & 1) res = res * a % m; a = a * a % m; b >>= 1; } return res; }
i64 powll(i64 a, i64 b) { i64 res = 1; while (b > 0) { if (b & 1) res = res * a; a = a * a; b >>= 1; } return res; }
template<typename Water, typename ...Typename>
Water& operator<<(Water&water,pair<Typename...>&p){return water<<'{'<<get<0>(p)<<", "<<get<1>(p)<<'}';}
template<typename Water, typename Fire> 
Water& operator<<(Water&water,vector<vector<Fire>>v){water<<"\n{\n";for(auto i:v){water<<"\t[ ";for(auto j: i)water\
// <<left<<setw(8) \M
<<j<<' ';water<<"]\n";};return water<<"}";}
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
#define YSS                                          212345

notwatermango

signed main(){
  fastmango;
  i32 tc = 1;
  // cin >> tc;
  for(i32 i = 0; i < tc; ++i) {
    // cout << "Case #" << i+1 << ": ";
    solv();
  }
  return water;
}

struct FenwickTree {
  vector<int> bit; // binary indexed tree
  int n;

  FenwickTree(int n) {
    this->n = n;
    bit.assign(n, 0);
  }

  FenwickTree(vector<int> a) : FenwickTree(a.size()) {
    for (size_t i = 0; i < a.size(); i++)
      add(i, a[i]);
  }

  int sum(int r) {
    int ret = 0;
    for (; r >= 0; r = (r & (r + 1)) - 1)
      ret += bit[r];
    return ret;
  }

  int sum(int l, int r) { return sum(r) - sum(l - 1); }

  void add(int idx, int delta) {
    for (; idx < n; idx = idx | (idx + 1))
      bit[idx] += delta;
  }
};

void solv(){
  int n; cin >> n;
  FenwickTree ft = FenwickTree(YSS);
  vector<pair<int,int>> vv(n);
  vector<int> vf(n),vs(n);
  for (int i = 0; i < n; i++)
  {
    cin >> vv[i].first; vf[i] = vv[i].first;
  } for (int i = 0; i < n; i++)
  {
    cin >> vv[i].second; vs[i] = vv[i].second;
  } 
  sort(all(vv));

  // compress coordinate < YSS
  sort(all(vf));
  sort(all(vs), greater<int>());
  map<int,int> mf,ms;
  for (int i = 0; i < n; i++)
  {
    mf[vf[i]] = i;
    ms[vs[i]] = i;
  }
  vector<pair<int,int>> nv;
  map<pair<int,int>,int> pm;
  for (int i = 0; i < n; i++)
  {
    vv[i].first = mf[vv[i].first];
    vv[i].second = ms[vv[i].second];
    if(pm[mp(vv[i].first, vv[i].second)] == 0) {
      nv.push_back(mp(vv[i].first, vv[i].second));
    }
    pm[mp(vv[i].first, vv[i].second)]++;
  }
  mango(vv);
  mango(nv);

  sort(all(nv));
  // do the thing
  int res = 0;
  for (int i = 0; i < sz(nv); i++)
  {
    int wow = ft.sum(nv[i].second); // gte vvs
    mango(pm[mp(nv[i].first, nv[i].second)]);
    mango(wow);
    res += wow*pm[mp(nv[i].first, nv[i].second)];
    mango(nv[i].second);
    ft.add(nv[i].second, pm[mp(nv[i].first, nv[i].second)]);
    mango(
      "------------"
    );
    res += pm[mp(nv[i].first, nv[i].second)]*pm[mp(nv[i].first, nv[i].second)];
  }
  cout << res<< '\n';
  



  
  

  
  
  
  
}
