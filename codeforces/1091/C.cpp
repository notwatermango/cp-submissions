// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
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
  int n;
  cin >> n;
  vector<int> v,vres;
  set<int> S;
  for (int i = 2; i * i <= n; i++)
  {
    if(n%i == 0){
      S.insert(i);
      S.insert(n/i);
    }
  }
  vres.push_back(1);
  vres.push_back((n*(n+1))/2);
  for (auto e:S)
  {
    // int start = 0;
    // int res = 0;
    // for (int j = 0; j < n; j++)
    // {
    //   start += e;
    //   start %= n;
    //   if(0 == start) break;
    //   res += start+1;
    // }
    // res++;
    // vres.push_back(res);
    int nq = n/e;
    int res = (nq*(2 + (nq-1) * e) )/ 2;
    vres.push_back(res);
  }
  sort(all(vres));
  mango(vres);
  for(auto e:vres){
    cout << e << ' ';
  }
  cout << '\n';
}