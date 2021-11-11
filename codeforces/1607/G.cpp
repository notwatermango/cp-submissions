// #include <bits/stdc++.h>
#include <iostream>
#include <utility>
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
#define int i64

notwatermango

signed main(){
  fastmango;
  i32 tc = 1;
  cin >> tc;
  for(i32 i = 0; i < tc; ++i) {
    // cout << "Case #" << i+1 << ": ";
    solv();
  }
  return 0;
}

void solv(){
  int n, k;
  cin >> n >> k;
  pair<int,int> res[n];
  pair<int,int> arr[n];
  int l,r;
  l = r = 0;
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i].first >> arr[i].second;
    if(arr[i].first < k){
      res[i].first = arr[i].first;
      res[i].second = k - arr[i].first;
    } else{
      res[i].first = k;
      res[i].second = 0;
    }
    arr[i].first -= res[i].first;
    arr[i].second -= res[i].second;
    l+=arr[i].first;
    r+=arr[i].second;
  }
  for (int i = 0; i < n; i++)
  {
    mango(arr[i]);
  }
  
  for (int i = 0; i < n; i++)
  {
    if(r-l > 0){
      mango("horas");
      // l kebanyakan
      int tmp = min((r-l)/2, min(arr[i].second, res[i].first));
      arr[i].second -= tmp;
      res[i].second += tmp;
      res[i].first -= tmp;
      l += tmp;
      r -= tmp;
    } else if(r-l < 0){
      // r kebanyakan
      int tmp = min((l-r)/2, min(arr[i].first, res[i].second));
      arr[i].first -= tmp;
      res[i].first += tmp;
      res[i].second -= tmp;
      l -= tmp;
      r += tmp;
    }
  }
  for (int i = 0; i < n; i++) mango(arr[i]);
  cout << abs(l-r) << '\n';
  for (int i = 0; i < n; i++)
  {
    cout << res[i].first << ' ' << res[i].second << '\n';
  }

  

  

  


  
  
}