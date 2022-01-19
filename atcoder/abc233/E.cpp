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
  string s; cin >> s;
  int n = sz(s);
  vector<int> sum(512345);
  int ak = 0;
  for (int i = 0; i < n; i++)
  {
    int ii = 100 + i;
    ak += int(s[i] - '0');
    sum[ii] = ak;
  }
  // for (int i = 0; i < n; i++)
  // {
  //   cout << sum[100+i] << '\n';
  // }
  // cout << '\n';
  
  // int aaa = 0;
  for (int i = 512344; i > 0; i--)
  {
    int a = sum[i];
    sum[i-1] += a/10;
    sum[i] = a%10;
    // if(sum[i]){
    //   aaa++;
    //   if(aaa == 7) break;
    //   for (int j = j-12; j < n; j++)
    //   {
    //     cout << sum[100+j] << '\n';
    //   }
    //   cout << '\n';
    // }

  }
  bool lesgo = 0;
  for (int i = 0; i < n+100; i++)
  {
    if(sum[i] > 0) {
      lesgo = 1;
    }
    if(lesgo) {
      cout << sum[i];
    }
  }
  cout << '\n';
  // cout << "349065850398865915384738153697722542688574377708317" << '\n';
  
  
  
  
}