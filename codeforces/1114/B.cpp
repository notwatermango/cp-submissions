// #include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <map>
#include <set>
#include <utility>
#include <vector>
using namespace std;

typedef int64_t i64;
typedef int32_t i32;

i32 water = not true;
#define mango(x)
#define fastmango ios_base::sync_with_stdio(false); cin.tie(nullptr)
#ifdef notwatermango
#undef mango
#undef notwatermango
#define mango(x) { ++water; auto x_=x; --water; cerr<<string(water, '\t')<<"\033[38;5;206m"<<__func__<<":"<<__LINE__<<"\t"<<#x<<" = "<<x_<<"\e[39m"<<'\n'; }
#endif
#define notwatermango void solv();
i64 powllm(i64 a, i64 b, i64 m) { a %= m; i64 res = 1; while (b > 0) { if (b & 1) res = res * a % m; a = a * a % m; b >>= 1; } return res; }
i64 powll(i64 a, i64 b) { i64 res = 1; while (b > 0) { if (b & 1) res = res * a; a = a * a; b >>= 1; } return res; }
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
  int n, m, k;
  cin >> n >> m >> k;
  int arr[n];
  int rl[n];
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
    rl[i] = arr[i];
  }
  sort(arr, arr+n, greater<int>());
  int mn = INF;
  int sum = 0;
  for (int i = 0; i < m*k; i++)
  {
    mn = min(mn, arr[i]);
    sum +=arr[i];
  }
  int cmn = 0;
  for (int i = 0; i < m*k; i++)
  {
    if(arr[i] == mn) cmn ++;
  }
  
  cout << sum <<'\n';
  int ct = 0;
  int cou = 0;
  mango(mn);
  for (int i = 0; i < n; i++)
  {
    if(rl[i] >= mn){
      if(rl[i] == mn){
        if(cmn) cmn--;
        else continue;
      }
      ct ++;
      if(ct == m && cou < k-1){
        cout << i+1 <<' ';
        ct = 0;
        cou++;
      }
    }
  }
  cout << '\n';
  


  
  
}