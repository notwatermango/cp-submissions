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
  int a,b,c;
  cin >> a>> b >> c;
  int aa = a/3;
  int bb = b/2;
  int cc = c/2;
  int week = min(aa, min(bb,cc));
  a -= week*3;
  b -= week*2;
  c -= week*2;
  // cout << week*7 << " +" <<'\n';
  int aq = min(a,(int)3);
  int bq = min(b,(int)2);
  int cq = min(c,(int)2);
  int res = 0;
  for (int j = 0; j < 7; j++)
  {
    int aqq= aq;
    int bqq= bq;
    int cqq= cq;
    int ct = 0;
    for (int q = j; q < j+7; q++)
    {
      int i = q%7;
      if(i == 0 || i == 3 || i == 6){
        if(aqq) aqq--;
        else break;
      } else if(i == 1 || i == 5){
        if(bqq) bqq--;
        else break; 
      } else if(i == 2 || i == 4 ){
        if(cqq) cqq--;
        else break;
      }
      ct++;
    }
    // cout << ct << ' ';
    res = max(ct, res);
  }
  // cout << ct << '\n';
  
  


  // cout <<a << ' ' << b << ' ' << c << '\n';
  // cout << aq << ' ' << bq << ' ' << cq << '\n';
  cout << week*7+res << '\n';
}