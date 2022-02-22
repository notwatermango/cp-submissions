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

notwatermango

signed main(){
  fastmango;
  i32 tc = 1;
  cin >> tc;
  for(i32 i = 0; i < tc; ++i) {
    // cout << "Case #" << i+1 << ": ";
    solv();
  }
  return water;
}

int n,x;
vector<int> arr, ggl, ggr, sum;

int getsum(int a, int b) { // []
  return sum[b+1] - sum[a];
}

void solv(){
  cin >> n >> x;
  sum.assign(n+2, 0);
  ggl.assign(n+2, 0);
  ggr.assign(n+2, 0);
  arr.assign(n+2, 0);
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
    sum[i+1] = arr[i] + sum[i];
  }
  int imx = 0;
  for (int i = 0; i < n; i++)
  {
    for (int j = i; j < n; j++)
    {
      imx = max(getsum(i,j), imx);
    }
  }

  for (int i = 0; i < n; i++)
  {
    int gggr = 0;
    for (int j = i+1; j < n; j++)
    {
      gggr+=arr[j];
      ggr[i] = max(ggr[i], gggr);
    }
    int gggl = 0;
    for (int j = i-1; j > -1; j--)
    {
      gggl += arr[j];
      ggl[i] = max(ggl[i] , gggl);
    }
  }
  



  int mem = imx;
  cout << mem << ' ';
  for (int i = 0; i < n; i++)
  {
    int mx = mem;
    for (int j = i; j < n; j++)
    {
      int cd = getsum(j-i, j) + ggl[j-i] + ggr[j];
      mx = max(mx, cd + (i+1)*x);
    }
    cout << mx << ' ';
    mem = max(mx, mem);
  }
  cout << '\n';
  
  

  
}