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
#define notwatermango void solv();
i64 powllm(i64 b, i64 a, i64 m) { b %= m; i64 res = 1; while (a > 0) { if (a & 1) res = res * b % m; b = b * b % m; a >>= 1; } return res; }
i64 powll(i64 b, i64 a) { i64 res = 1; while (a > 0) { if (a & 1) res = res * b; b = b * b; a >>= 1; } return res; }
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
  vector<int> b(n), a(n);
  map<int,int> count, countb;
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
    count[a[i]]++;
  }
  for (int i = 0; i < n; i++)
  {
    cin >> b[i];
    countb[b[i]]++;
  }
  for (int i = 0; i < n; i++)
  {
    if(count[a[i]] != countb[a[i]]){
      cout << "No\n";
      return;
    }
  }
  

  for (int i = 0; i < n-2; i++)
  {
    mango(b[i]);
    int ai = i;
    int bi = -1;
    for (int j = i; j < n; j++)
    {
      if(a[j] == b[i]) {
        bi = j;
        // break;
      }
    }
    if(bi == -1){
      cout << "No\n";
      return;
    }
    mango(mp(ai,bi));
    if(ai == bi) continue;
    
    for (int j = bi; j >= ai; )
    {
      if(j-2 >= ai) {
        // jump
        int mybi = a[j];
        a[j] = a[j-1];
        a[j-1] = a[j-2];
        a[j-2] = mybi;
        j-=2;
      } else if(j-1 >= ai && j+1<n) {
        // bruh twice
        int mybi = a[j];
        a[j] = a[j+1];
        a[j+1] = a[j-1];
        a[j-1] = mybi;
        j--;
      } else break;
    }
    mango(a);
  }
  mango(b);
  vector<int> v1,v2;
  int sad = 1;

  int gg = 1;
  for (int i = n-3; i < n; i++)
  {
    if(b[i] != a[i]) gg = 0;
  }
  if(gg) sad = 0;
  
  
  int tmp = a[n-1];
  a[n-1] = a[n-2];
  a[n-2] = a[n-3];
  a[n-3] = tmp;
  gg = 1;
  for (int i = n-3; i < n; i++)
  {
    if(b[i] != a[i]) gg = 0;
  }
  if(gg) sad = 0;

  mango(a);
  tmp = a[n-1];
  a[n-1] = a[n-2];
  a[n-2] = a[n-3];
  a[n-3] = tmp;
  gg = 1;
  mango(a);
  for (int i = n-3; i < n; i++)
  {
    if(b[i] != a[i]) gg = 0;
  }
  if(gg) sad = 0;
  

  for (int i = 0; i < n; i++)
  {
    if(count[a[i]] > 1){
      sad = 0;
    }
  }
  
  
  if(sad){
      cout << "No\n";
      return;
  }

  for (int i = 0; i < n-3; i++)
  {
    if(b[i] != a[i]) {
      cout << "No\n";
      return;
    }
  }
  cout << "Yes\n";
  
  


  
  
}