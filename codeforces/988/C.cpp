// #include <bits/stdc++.h>
#include <iostream>
#include <utility>
#include <map>
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
  int k; cin >> k;
  bool ok = not true;
  map<int,pair<int,int>> mq;
  for (int i = 0; i < k; i++)
  {
    int n; cin >> n;
    int arr[n];
    int sum = 0;
    for (int j = 0; j < n; j++)
    {
      cin >> arr[j];
      sum+=arr[j];
    }
    if(ok) continue;
    for (int j = 0; j < n; j++)
    {
      int tr = sum-arr[j];
      if(mq.find(tr) != mq.end() && mq[tr].first != i+1){
        ok = true;
        cout << "YES\n" << i+1 << ' ' << j+1 << '\n';
        cout << mq[tr].first << ' ' << mq[tr].second << '\n';
        break;
      }
      mq[tr] = mp(i+1, j+1);
    }
  }
  if(!ok) cout << "NO\n";
  
}