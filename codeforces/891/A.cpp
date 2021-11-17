// #include <bits/stdc++.h>
#include <vector>
#include <iostream>
#include <numeric>
#include <algorithm>
#include <iomanip>
using namespace std;

typedef int64_t i64;
typedef int32_t i32;

i32 water = not true;
#define mango(x)
#define fastmango ios_base::sync_with_stdio(false); cin.tie(nullptr)
#ifdef notwatermango
#undef notwatermango
#undef mango
#define mango(x) {++water; auto x_=x; --water; cerr<<string(water, '\t')<<"\033[38;5;206m"<<__func__<<":"<<__LINE__<<"\t"<<#x<<" = "<<x_<<"\e[39m"<<'\n';}
#endif
#define notwatermango void solv();
template<typename Ostream, typename Cont>
typename enable_if<is_same<Ostream,ostream>::value, Ostream&>::type operator<<(Ostream& water,  const Cont& v){ water<<"["; for(auto& x:v) water<<x<<", "; return water<<"]"; }
template<typename Ostream, typename ...Ts>
Ostream& operator<<(Ostream& water,  const pair<Ts...>& p){ return water<<"{"<<p.first<<", "<<p.second<<"}"; }

#define MOD 1000000007
#define LLINF 4202025013666420666
#define INF 1000177013
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define mp make_pair
// #define int i64

notwatermango

signed main(){
  fastmango;
  i32 tc = 1;
  // cin >> tc;
  for(i32 i = 0; i < tc; ++i) {
    // cout << "Case #" << i+1 << ": ";
    solv();
  }
  return 0;
}

void solv(){
  int n;
  cin >> n;
  int arr[n];
  vector<vector<int>> v(n, vector<int>(n));
  for(int i = 0; i < n; ++i) cin >> arr[i];
  int mn = INF;
  for (int i = 0; i < n; i++)
  {
    int gc = arr[i];
    for (int j = i; j < n; j++)
    {
      gc = gcd(gc, arr[j]);
      v[i][j] = gc;
      if(gc == 1){
        mn = min(mn, j-i);
      }
    }
  }
  // for (int i = 0; i < n; i++)
  // {
  //   for (int j = 0; j < n; j++)
  //   {
  //     cout << v[i][j] << ' ';
  //   }
  //   cout << '\n';
  // }
  int res = mn-1+n;
  if(mn == INF){
    res = -1;
  }
  if(mn == 0){
    int ct = 0;
    for (int i = 0; i < n; i++)
    {
      if(arr[i] == 1) ct++;
    }
    res = n-ct;
  }
  cout << res <<'\n';
}
