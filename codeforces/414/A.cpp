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
  int n, k;
  cin >> n >> k;
  int n2 = n/2;
  if(n == 1){
    if(k == 0) cout << "1\n";
    else cout << "-1\n";
    return;
  }
  if(n2 > k){
    cout << "-1\n";
    return;
  }
  int need = k - (n2-1);
  cout << need << ' ' << need * 10 << ' ';
  for (int i = 1; i < n2; i++)
  {
    if(i*2 -1 == need || i *2 == need || i*2-1 == need*10 || i*2 == need*10){
      n2++;
      continue;
    }
    cout << i*2-1 << ' ' << i*2 << ' ';
  }
  if(n%2 == 1){
    cout<< 999999999;
  }
  cout << '\n';
  // mango(need);

  
}