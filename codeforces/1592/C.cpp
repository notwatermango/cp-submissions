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

vector<int> arr, vis, zor;
vector<vector<int>> adj;
int treexor;
int ok;

int dfs(int x) {
  if (ok == 2) return 0;
  mango(x);
  vis[x] = 1;
  zor[x] = arr[x];
  for (auto e: adj[x]) if (not vis[e]) {
    zor[x] ^= dfs(e); 
  }
  if (zor[x] == treexor) {
    ok++;
    return 0;
  }
  return zor[x];
}

void solv() {
  int n, k; cin >> n >> k;
  ok = false;
  arr.resize(n);
  vis.assign(n, 0);
  zor.assign(n, 0);
  adj.assign(n, vector<int>());
  treexor = 0;
  for (int i = 0; i < n; ++i) cin >> arr[i], treexor ^= arr[i];
  // if we have 00000 we can divide into 2 literally anywhere

  // WRONG:
  // if we have xorsubtree equals xortree then the exclusion of subtree is 00000

  // SO :
  // find 2 edges


  // therefore can divide into 3, careful not to choose subtree rooted at 1
  

  for (int i = 0; i < n-1; ++i) {
    int fr, to; cin >> fr >> to; fr--, to--;
    adj[fr].push_back(to);
    adj[to].push_back(fr);
  }
  mango(adj);

  // k > 2
  if (not treexor) { cout << "YES\n"; return; }
  if (k == 2 and treexor) { cout << "NO\n"; return; }


  // k > 3
  // let's find subtreexor = treexor somewhere
  // let tree root at 0
  // but don't check subtree rooted 0
  mango("dfs");
  vis[0] = 1;
  for (auto e: adj[0]) {
    dfs(e);
  }
  mango(zor);
  mango(vis);
  mango(ok);
  if (ok >= 2) {

    // i can make n-2 connected
    // when n == 3 i can't o things except treexor = 0 (NOT including all equal)
    if (n == 3) {
      int alleq = 1;
      for (int i = 1; i < n; ++i) {
        if (arr[i]^arr[i-1]) alleq = 0;
      }
      if (not treexor or alleq) cout << "YES\n";
      else cout <<"NO\n";
      return;
    }


    cout << "YES\n";
  } else cout << "NO\n";





}