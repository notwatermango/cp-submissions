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
  // cin >> tc;
  for(i32 i = 0; i < tc; ++i) {
    // cout << "Case #" << i+1 << ": ";
    solv();
  }
  return water;
}

void solv(){
  int n; cin >> n;
  int s[n+1];
  for(int i = 1; i < n+1; i++) {
    cin >> s[i];
  }
  s[0]= 0;
  int b = LLINF;
  int a = LLINF;
  int ab = LLINF;
  int n2 = n+2;
  

  {
    int tt[n2];
    tt[0] = tt[1] = 0;
    for (int i = 2; i < n2; i++)
    {
      tt[i] = s[i-1] - tt[i-1] - tt[i-2];
      if(i % 3 == 2) {
        ab = min(ab, s[i-1]);
      }
      if(i % 3 == 0) {
        a = min(a, tt[i]);
        // a = max(a, (int)0);
      }
      if(i % 3 == 1) {
        b = min(b, tt[i]);
        // b = max(b, (int)0);
      }
    }
    mango(dbg(tt));
    
  }



  if(a == LLINF) a= 0;
  if(b == LLINF) b= 0;
  a = -a;
  b = -b;
  a = max(a,(int)0);
  b = max(b,(int)0);
  mango(a);
  mango(b);
  mango(ab);

  // b = ab -a;
  int res[n2];
  res[0] = a;
  res[1] = b;
  if(a <0 || b <0) {
    cout << "No\n";
    return;
  }
  for (int i = 2; i < n2; i++)
  {
    res[i] = s[i-1] - res[i-1] - res[i-2];
    if(res[i] < 0) {
      cout << "No\n";
      return;
    }
  }
  cout << "Yes\n";
  for (int i = 0; i < n2; i++)
  {
    cout << res[i] << ' ';
  }
  cout << '\n';
  
  
  
  
  
}
/*
7
6 2 0 3 4 4 1
*/