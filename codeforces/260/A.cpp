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
  int a;
  int b,n;
  string ss;
  cin >> a >> b >> n;
  ss = to_string(a);
  for (int lg = 0; lg < n; lg++)
  {
    int gt = -1;
    for (int i = 0; i < 10; i++)
    {
      if((a*10+i) % b == 0){
        a*=10;
        a+=i;
        gt = i;
        break;
      }
    }
    mango(lg);
    if(gt == -1){
      cout << "-1\n";
      return;
    }
    if((a*10 + gt) % b == 0){
      for (int k = lg; k < n; k++)
      {
        ss.push_back(gt+'0');
      }
      break;
    }
    ss.push_back(gt+'0');

  }
  cout << ss << '\n';

  
}