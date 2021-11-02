// #include <bits/stdc++.h>
#include <iostream>
#include <queue>
#include <utility>
#include <map>
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
  cin >> tc;
  for(i32 i = 0; i < tc; ++i) {
    // cout << "Case #" << i+1 << ": ";
    solv();
  }
  return 0;
}

void solv(){
  int n;
  cin >> n;
  vector<pair<bool,int>> arr2(n);
  for (int i = 0; i < n; i++)
  {
    cin >> arr2[i].second;
  }
  string S;
  cin >> S;
  queue<int> q1,q2;
  for (int i = 0; i < n; i++)
  {
    bool ok = S[i] == 'B'? true: false;
    arr2[i].first = ok;
  }
  // bool bad = false;
  sort(all(arr2));
  // take inc ers as smol
  for (int i = 0; i < n; i++)
  {
    if(arr2[i].first) {
      q1.push(arr2[i].second);
    } else{
      q2.push(arr2[i].second);
    }
  }
  // q1 blue can decrease
  // q2 red can increase
  bool bad = false;
  // cout << sz(q1) << ' ' << sz(q2) << '\n';
  for (int i = 0; i < n; i++)
  {
    int ii = i+1;
    if(q1.empty() && q2.empty()){
      cout << "WAH"; break;
    }
    if(q1.empty()){
      if(q2.front() > ii){
        bad = true; break;
      } else{
        q2.pop();
        continue;
      }
    }
    if(q2.empty()){
      if(q1.front() < ii){
        bad = true; break;
      } else{
        q1.pop();
        continue;
      }
    }
    if(q1.front() >= ii){
      q1.pop();
      continue;
    }
    if(q1.front() < ii){
      if(q2.front() > ii){
        bad = true;
        break;
      }
      else{
        q2.pop();
        continue;
      }
    }


  }
  if(bad) cout << "NO\n";
  else cout << "YES\n";
  
  
  
  

    
}