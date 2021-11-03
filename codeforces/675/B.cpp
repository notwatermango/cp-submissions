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
  int n,a,b,c,d;
  cin >> n >> a >> b >> c >> d;
  int mx = 0;
  mx = max(a+b, mx);
  mx = max(b+d, mx);
  mx = max(c+d, mx);
  mx = max(c+a, mx);
  int q1,q2,q3,q4;
  // cout << mx << "MX|";
  q1 = mx-a-b+1;
  q2 = mx-a-c+1;
  q3 = mx-b-d+1;
  q4 = mx-d-c+1;
  mx = 0;
  mx = max(q1, mx);
  mx = max(q2, mx);
  mx = max(q3, mx);
  mx = max(q4, mx);
  // cout << mx << "MX|";
  if(mx > n){
    cout << "0\n";
    return;
  }
  // cout << mx << ' ';
  int res = n*(n-mx+1);
  cout << res << '\n';

}