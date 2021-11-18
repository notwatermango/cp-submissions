// #include <bits/stdc++.h>
#include <iostream>
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
  int pre[n];
  int suf[n];
  for(int i = 0; i < n; ++i) cin >> arr[i];
  pre[0] = ~arr[0];
  suf[n-1] = ~arr[n-1];
  for (int i = 1; i < n; i++)
  {
    pre[i] = pre[i-1] & ~arr[i];
  }
  for (int i = n - 2; i >= 0; i--)
  {
    suf[i] = suf[i+1] & ~arr[i];
  }
  int mx = -INF;
  int ii = -INF;
  for (int i = 0; i < n; i++)
  {
    int res;
    if(i == 0) res = arr[i] & suf[i+1];
    else if(i == n-1) res = arr[i] & pre[i-1];
    else {
      res = arr[i] & pre[i-1] & suf[i+1];
    }
    if(res > mx){
      mx = res;
      ii = i;
    }
  }
  cout << arr[ii];
  for (int i = 0; i < n; i++)
  {
    if(i == ii) continue;
    cout << ' ' << arr[i];
  }
  cout << '\n';
  mango(mx);
  
  
  
  
}