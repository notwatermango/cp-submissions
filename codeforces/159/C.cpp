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
  int k; string S;
  cin >> k >> S;
  string res = S;
  vector<bool> v(sz(S)*k);
  for (int i = 1; i < k; i++)
  {
    res+=S;
  }
  vector<vector<int>> vv(26);
  mango(res);
  for (int i = 0; i < sz(res); i++)
  {
    vv[res[i]-'a'].push_back(i);
  }
  mango(vv);
  int qq;
  cin >> qq;
  for (int i = 0; i < qq; i++)
  {
    int a; char cj;
    cin >> a >> cj;
    a--;
    v[vv[cj-'a'][a]] = true;
    vv[cj-'a'].erase(vv[cj-'a'].begin() + a);
  }
  mango(vv);
  for (int i = 0; i < sz(res); i++)
  {
    if(v[i]) continue;
    cout << res[i];
  }
  cout << '\n';  
  
}