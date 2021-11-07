// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <map>
#include <set>
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
  set<int> S, S2;
  vector<int> res;
  int ct = 0;
  for (int i = 0; i < n; i++)
  {
    int x;
    cin >> x;
    if(x > 0){
      int q = sz(S);
      int q2 = sz(S2);
      S.insert(x);
      S2.insert(x);
      if(q == sz(S) || q2 == sz(S2)){
        // double in
        cout << "-1\n";
        return;
      }
      ct++;

    } else{
      auto it = S.find(-1*x);
      if(it == S.end()){
        // out no
        cout << "-1\n";
        return;
      }
      S.erase(it);
      ct++;
      if(S.empty()){
        res.push_back(ct);
        S2.clear();
        ct = 0;
      }
    }
  }
  if(!S.empty()){
    cout << "-1\n";
    return;
  }
  mango(res);
  cout << sz(res) << '\n';
  for(auto e: res){
    cout<<e<<' ';
  }
  cout << '\n';
  

}