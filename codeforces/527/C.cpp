// #include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <map>
#include <set>
#include <utility>
#include <vector>
using namespace std;

typedef int64_t i64;
typedef int32_t i32;

i32 water = not true;
#define mango(x)
#define fastmango ios_base::sync_with_stdio(false); cin.tie(nullptr)
#ifdef notwatermango
#undef mango
#undef notwatermango
#define mango(x) { ++water; auto x_=x; --water; cerr<<string(water, '\t')<<"\033[38;5;206m"<<__func__<<":"<<__LINE__<<"\t"<<#x<<" = "<<x_<<"\e[39m"<<'\n'; }
#endif
#define notwatermango void solv();
i64 powllm(i64 a, i64 b, i64 m) { a %= m; i64 res = 1; while (b > 0) { if (b & 1) res = res * a % m; a = a * a % m; b >>= 1; } return res; }
i64 powll(i64 a, i64 b) { i64 res = 1; while (b > 0) { if (b & 1) res = res * a; a = a * a; b >>= 1; } return res; }
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
  return water;
}

void solv(){
  int w,h,n;
  cin >> w >> h >> n;
  set<int> sw, sh;
  map<int,int> mw, mh;
  mw[w]++;
  mh[h]++;
  for (int i = 0; i < n; i++)
  {
    char cj;
    int x;
    cin >> cj >> x;
    if(cj == 'H'){
      if(sh.empty()){
        mh[h]--;
        if(!mh[h]){
          mh.erase(h);
        }
        mh[h-x]++;
        mh[x]++;
      } else {
        auto lb = sh.lower_bound(x);
        if(lb == sh.end()){
          // cout << "HO\n";
          auto befor = prev(lb);
          int bf = *befor;
          mh[h-bf]--;
          if(!mh[h-bf]){
            mh.erase(h-bf);
          }
          mh[x-bf]++;
          mh[h-x]++;
        }
        else if(lb == sh.begin()){
          int bf = *sh.begin();
          mh[bf]--;
          if(!mh[bf]){
            mh.erase(bf);
          }
          mh[bf-x]++;
          mh[x]++;
        } else {
          int bf = *prev(lb);
          int ar = *lb;
          mh[ar-bf]--;
          if(!mh[ar-bf]) mh.erase(ar-bf);
          mh[ar-x]++;
          mh[x-bf]++;
        }
      }
      sh.insert(x);
    } else{
      if(sw.empty()){
        mw[w]--;
        if(!mw[w]){
          mw.erase(w);
        }
        mw[w-x]++;
        mw[x]++;
      } else {
        auto lb = sw.lower_bound(x);
        if(lb == sw.end()){
          // cout << "HO\n";
          auto befor = prev(lb);
          int bf = *befor;
          mw[w-bf]--;
          if(!mw[w-bf]){
            mw.erase(w-bf);
          }
          mw[x-bf]++;
          mw[w-x]++;
        }
        else if(lb == sw.begin()){
          int bf = *sw.begin();
          mw[bf]--;
          if(!mw[bf]){
            mw.erase(bf);
          }
          mw[bf-x]++;
          mw[x]++;
        } else {
          int bf = *prev(lb);
          int ar = *lb;
          mw[ar-bf]--;
          if(!mw[ar-bf]) mw.erase(ar-bf);
          mw[ar-x]++;
          mw[x-bf]++;
        }
      }
      sw.insert(x);
    }
    int mxw = prev(mw.end())->first;
    int mxh = prev(mh.end())->first;
    mango(mxw);
    mango(mxh);
    cout << mxw * mxh <<'\n';
  }
  
}