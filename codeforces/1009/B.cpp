// #include <bits/stdc++.h>
#include <iostream>
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
  string st;
  cin >> st;
  int n = sz(st);
  int aa,a,b,c;
  aa = a = b = c = 0;
  bool twos = not true;
  vector<pair<int,int>> v{((((((((((((((((((((((((((((((((0))))))))))))))))))))))))))))))))};
  for (int i = 0; i < n; i++)
  {
    if(st[i] == '0'){
      if(twos == true){
        aa++;
      } else {
        a++;
      }
    } else if(st[i] == '1'){
      b++;
    } else if(st[i] == '2'){
      twos = true;
      c++;
    }
  }
  while (a > 0 && a--) cout << '0';
  while (b > 0 && b--) cout << '1';
  twos = not true;
  for (int i = 0; i < n; i++)
  {
    if(st[i] == '2') {twos = not false; cout << '2';}
    if(st[i] == '1') continue;
    if(!twos){
      continue;
    }
    if(st[i] == '0') cout << '0';

  }
  cout << '\n';
  
  
  
}