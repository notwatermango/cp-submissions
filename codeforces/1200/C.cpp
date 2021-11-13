// #include <bits/stdc++.h>
#include <iostream>
#include <numeric>
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
  int n, m,  q;
  cin >> n >> m >> q;
  int g = gcd(n, m);
  int nn = n/g;
  int mm = m/g;
  // cout << nn << ' ' << mm ;
  for (int i = 0; i < q; i++)
  {
    int a1, a2, b1, b2;
    cin >> a1 >> a2 >> b1 >> b2;
    a2--; b2--;
    int ares,bres;
    if(a1 == 1){
      ares = a2/nn;
    } else {
      ares = a2/mm;
    }
    if(b1 == 1){
      bres = b2/nn;
    } else bres = b2/mm;
    if(ares == bres){
      cout << "YES\n";
    } else cout <<"NO\n";
  }
  
}