// #include <bits/stdc++.h>
#include <iostream>
#include <deque>
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
  int n;
  cin >> n;
  if(n < 8){
    if(n < 4) cout << "NO\n";
    else {
      cout << "YES\n";
      if(n == 4) cout << "1 * 2 = 2\n2 * 3 = 6\n6 * 4 = 24\n";
      if(n == 5) cout << "4 * 5 = 20\n3 - 1 = 2\n2 + 2 = 4\n20 + 4 = 24\n";
      if(n == 6) cout << "6 - 5 = 1\n1 * 1 = 1\n1 * 2 = 2\n2 * 3 = 6\n6 * 4 = 24\n";
      if(n == 7) cout << "7 - 6 = 1\n1 * 1 = 1\n4 * 5 = 20\n3 - 1 = 2\n2 + 2 = 4\n20 + 4 = 24\n";
    }






    return;
  }
  cout << "YES\n";
  deque<int> v;
  for (int i = 0; i < n; i++)
  {
    v.push_back(i+1);
  }
  while(v.back() != 1){
    int x = v.back(); v.pop_back();
    if(x == 8 || x == 3){
      v.push_front(x);
      continue;
    }
    int y = v.back(); v.pop_back();
    if(y == 8 || y == 3){
      v.push_front(y);
      y = v.back(); v.pop_back();
    }
    cout << x << " - " << y << " = " << x-y << '\n';
    v.push_front(x-y);
  }
  mango(v);
  sort(all(v));
  while(find(all(v), 2) != v.end()){
    v.erase(find(all(v), 2));
    cout << "2 - 1 = 1\n";
  }
  while(sz(v) > 3){
    v.pop_front();
    cout << "1 * 1 = 1\n";
  }
  if(v.front() == 1){
    cout << "1 * 3 = 3\n";
  }
  mango(v);
  cout << "3 * 8 = 24\n";

  
  
  
}