// #include <bits/stdc++.h>
#include <iostream>
#include <utility>
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
  int n,m,k;
  cin >> n >> m >> k;
  int arr[n];
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }
  vector<pair<pair<int,int>,int>> op(m);
  for (int i = 0; i < m; i++)
  {
    int l,r,d;
    cin >> l >> r >> d;
    l--;
    r--;
    op[i]= mp(mp(l,r), d);
  }
  vector<int> v(m+1);
  for (int i = 0; i < k; i++)
  {
    int x, y;
    cin >> x >> y;
    x--;
    v[x]++;
    v[y]--;
  }
  int times = 0;
  vector<int> vv(n+1);
  for (int i = 0; i < m; i++)
  {
    times+=v[i];
    // do op i *times;
    vv[op[i].first.first] += op[i].second*times;
    vv[op[i].first.second+1] -= op[i].second*times;
  }
  mango(v);
  mango(vv);
  int sm = 0;
  for (int i = 0; i < n; i++)
  {
    sm+=vv[i];
    cout << sm + arr[i]<<' ';
  }
  
  

}