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
#define sz(x) (int)(x).sc()
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

vector<int> par, sc;
int get_parent(int x){
  if(x == par[x]){
    return x;
  }
  return par[x] = get_parent(par[x]);
}

void connect_d(int x, int y){
  x = get_parent(x);
  y = get_parent(y);
  if(x!=y){
    if(sc[x] < sc[y]){
      swap(x,y);
    }
    par[y] = x;
    sc[x] += sc[y];
  }
}

void make_set(int x){
  par[x] = x;
  sc[x] = 1;
}

void solv(){
  int n, m;
  cin >> n >> m;
  par.assign(n,0);
  sc.assign(n,0);
  for (int i = 0; i < n; i++)
  {
    make_set(i);
  }
  
  for (int i = 0; i < m; i++)
  {
    int x;
    cin >> x;
    int mem;
    for (int j = 0; j < x; j++)
    {
      int user;
      cin >> user;
      user--;
      if(j != 0){
        connect_d(mem, user);
      }
      mem = user;
    }
  }
  mango(par);
  vector<int> vm(n);
  for (int i = 0; i < n; i++)
  {
    par[i] = get_parent(i);
    vm[par[i]]++;
  }
  mango(par);
  mango(vm);
  for (int i = 0; i < n; i++)
  {
    cout << vm[par[i]] << ' ';
  }
  cout << '\n';
  
}