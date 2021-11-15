// #include <bits/stdc++.h>
#include <iostream>
#include <queue>
#include <vector>
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
  deque<int> v;
  int arr[n];
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }
  v.push_back(arr[0]);
  arr[0] = -1;
  for (int tt = 0; tt < 100; tt++)
  { 
    for (int i = 1; i < n; i++)
    {
      if(arr[i] == -1) continue;
      if(arr[i]%3 == 0 && v.front() == arr[i]/3){
        v.push_front(arr[i]);
        arr[i] = -1; continue;
      }
      if(v.back() % 3 == 0 && v.back()/3 == arr[i]){
        v.push_back(arr[i]);
        arr[i] = -1; continue;
      }
      if(v.front() %2 == 0 && v.front()/2 == arr[i]){
        v.push_front(arr[i]);
        arr[i] = -1; continue;
      }
      if(arr[i] % 2 ==0 && v.back() == arr[i]/2){
        v.push_back(arr[i]);
        arr[i] = -1; continue;
      }
    }
  }
  mango(v);
  for(auto e: v) cout << e << ' ';
  cout << '\n';
  
}