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
#define MOD                                          998244353
#define YSS                                          112345

notwatermango;

signed main() {
  fastmango;
  i32 tc = 1;
  cin >> tc;
  for(i32 i = 0; i < tc; ++i) {
    // cout << "Case #" << i+1 << ": ";
    solv();
  }
  return water;
}

void solv() {
  int n; cin >> n;
  string s;
  cin >> s;
  string sb = s;
  // bool bruh = false;
  // char tmp = 0;
  // int itmp = INF;
  // bool ggall = false;
  int sw = MOD;
  for (int i = (n+1)/2; i < n; i++)
  {
    sb[i] = s[n-1-i];
    // if(ggall) {
      // for (int j = (n)/2; j < i-1; j++)
      // {
        // s[j] = 'Z';
        // s[n-j-1] = 'Z';
      // }
      // ggall = false;
      
      // s[i] = 'Z';
      // s[n-i-1] = 'Z';
    // }

    // if(s[i] > s[n-1-i]) {
      //  sw--;
      //  break;
    // }

    // if(not bruh and s[i] < s[n-1-i]) {
      // ABC - ACC
      // tmp = s[n-1-i];
      // s[n-1-i] = s[i];
      // mango(n-1-i);
      // itmp = n - 1 - i;
      // mango(tmp);
      // ggall = 1;
    // } else {
      // s[i] = s[n-i-1];
      // bruh = 1;
    // }

  }
  mango(sb);
  mango(s);
  if(sb > s) sw--;

  mango(s);
  int b = ((n+1)/2);
  // mango(b);
  int wow = 0;
  // int res = 0;
  for (int i = b-1; i >-1; i--)
  {
    sw += (s[i]-'A')*powllm(26, wow++, MOD);
    sw %= MOD;
    // mango(sw);
  }
  // wow = 0;
  // for (int i = b-1; i >= itmp; i--)
  // {
    // if(i == itmp) {
      // sw += (s[i]-'A')*powllm(26, wow, MOD);
      // sw %= MOD;

    // }wow++;
  // }
  


  mango(sw+1);

  cout << (sw+1)%MOD << '\n';
  
  

}
/*
ccczzz
26*26 * 2 -> a..... b......      = 1352


26 * 2 -> ca.... cb.....         = 52

ccc, cca ,ccb                    = 3

*/