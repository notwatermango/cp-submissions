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
  cin >> tc;
  for(i32 i = 0; i < tc; ++i) {
    // cout << "Case #" << i+1 << ": ";
    solv();
  }
  return 0;
}

void solv(){
  int n,m;
  cin >> n >> m;
  int ux,uy,dx,dy;
  int mux,muy,mdx,mdy;
  ux=uy=dx=dy=0;
  mux=muy=mdx=mdy=0;
  int x,y;
  x = y = 0;
  string s;
  cin >> s;
  int sadge = -1;
  for (int i = 0; i < sz(s); i++)
  {
    if(s[i] == 'R'){
      y++;
    } else if(s[i] == 'L'){
      y--;
    } else if(s[i] == 'U'){
      x++;
    } else if(s[i] == 'D'){
      x--;
    }
    ux = max(ux, x);
    uy = max(uy, y);
    dx = min(dx, x);
    dy = min(dy, y);
    if(uy - dy >= m || ux - dx >= n){
      sadge = i;
      break;
    }
    mux = ux;
    muy = uy;
    mdx = dx;
    mdy = dy;
  // cout << mdy << " mdy ";
  }
  // cout << sadge << "sad ";
  cout << 1 + mux << ' ' << -1 * mdy + 1 << '\n';
  
  
}