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
  int h,w;
  cin >> h >> w;
  int ah[h], aw[w];
  for (int i = 0; i < h; i++)
  {
    cin >> ah[i];
  }
  for (int i = 0; i < w; i++)
  {
    cin >> aw[i];
  }
  bool sadge = false;
  int qq = 0;
  for (int i = 0; i < h; i++)
  {
    for (int j = 0; j < w; j++)
    {
      int bh,bw;
      bh = bw = 0;
      if(ah[i] > j) bh = 1;
      if(aw[j] > i) bw = 1;
      if(ah[i] < j) bh = -1;
      if(aw[j] < i) bw = -1;
      if(!bh && !bw) continue;
      if((!bh && bw == 1) || (!bw && bh == 1)){
        // cout << bh << ' ' << bw << " from " << i << ' ' << j << '\n';
        sadge =true;
        break;
      } 
      if(bh == 1 || bw == 1 || bh == 0 || bw == 0) continue;
      // cout << bh << ' ' << bw << '\n';
      mango(i);mango(j);
      qq++;


    }
  }
  if(sadge) cout << "0\n";
  else{
    int res = 1;
    while (qq--)
    {
      res*=2;
      res%=MOD;
    }
    cout << res << '\n';
    
  }

  
  
  
}