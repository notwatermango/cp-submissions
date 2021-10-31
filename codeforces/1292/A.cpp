// #include <bits/stdc++.h>
#include <iostream>
#include <set>
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
  int n, q;
  cin >> n >> q;
  int a, b;
  vector<vector<bool>> v(2, vector<bool> (n));
  int bb = 0;
  for (int i = 0; i < q; i++)
  {
    cin >> a >> b ;
    a--;b--;
    v[a][b] = !v[a][b];
    if(v[a][b]){
      if(v[!a][b]){
        bb++;
      }
      if(b > 0 && v[!a][b-1]){
        bb++;
      }
      if(b < n-1 && v[!a][b+1]){
        bb++;
      }
    } else{
      if(v[!a][b]){
        bb--;
      }
      if(b > 0 && v[!a][b-1]){
        bb--;
      }
      if(b < n-1 && v[!a][b+1]){
        bb--;
      }
    }
    if(bb) cout << "No\n";
    // if(bb) cout << "No " << bb << "\n";
    else cout <<"Yes\n";
  }
  
}