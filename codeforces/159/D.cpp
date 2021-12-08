// #include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <numeric>
#include <utility>
#include <vector>
#include <queue>
#include <cmath>
#include <stack>
#include <map>
#include <set>
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
Water& operator<<(Water& water, const pair<Typename...>& p){ return water<<'{'<<get<0>(p)<<", "<<get<1>(p)<<'}'; }
template<typename Water, typename Fire>
Water& operator<<(Water& water, const Fire& v){ water<<'['; for(auto i: v) water<<i<<", "; return water<<']'; }
template<typename _const>
vector<_const> tov(_const x[], i32 xs) { return vector<_const> (x, x + xs); }

#define INF 1000177013
#define LLINF 4202025013666420666
#define dbg(x) tov(x, sizeof x / sizeof x[0]);
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define MOD 1000000007
#define mp make_pair
#define int i64

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
  int n = s.length();
  vector<int> v1(n),v2(n); // manacher
  for (int i = 0, l = 0, r = 0; i < n; i++)
  {
    int k = 1;
    if(i <= r) k = min(v1[r+l-i], r-i+1);
    while(i - k > -1 && i + k < n && s[i-k] == s[i+k]) k++;
    v1[i] = k;
    k--;
    if(i + k > r){
      l = i-k;
      r = i+k;
    }
  }
  for (int i = 0, r = 0, l = 0; i < n; i++)
  {
    int k = 0;
    if(i <= r) k = min(v2[r+l-i+1], r-i+1);
    while(i - k > 0 && i + k < n && s[i-k-1] == s[i+k]) k++;
    v2[i] = k;
    k--;
    if(i + k > r){
      l = i-k-1;
      r = i+k;
    }
  }
  mango(v1);
  mango(v2);
  int sum  = 0;
  for (int i = 0; i < n-1; i++)
  {
    int a,b; a= b = 0;
    for (int j = 0; j < n; j++)
    {
      if(j <= i){
        a+= ((v1[j] >= i-j+1)?1:0) + ((v2[j] >= i-j+1)?1:0);
      } else {
        b+= min(v1[j], j-i) + min(v2[j], j-i-1);
      }
    }
    mango(mp(a,b));
    sum += a*b;
  }
  
  cout << sum <<'\n'; 
}