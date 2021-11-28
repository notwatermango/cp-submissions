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
  return water;
}

int mx= 0;
int cc = 0;

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
    mx = max(sc[x], mx);
  } else{
    cc++;
  }
}

void make_set(int x){
  par[x] = x;
  sc[x] = 1;
}

void solv(){
  int n, d;
  cin >> n >> d;
  par.assign(n,0);
  sc.assign(n,0);
  for (int i = 0; i < n; i++)
  {
    make_set(i);
  }
  for (int i = 0; i < d; i++)
  {
    int a,b;
    cin>>a >> b;
    a--;b--;
    // cout << i << ' ';
    connect_d(a,b);
    vector<int> v;
    for (int j = 0; j < n; j++)
    {
      if(par[j] != j) continue;
      v.push_back(sc[j]);
    }
    sort(all(v));
    v.pop_back();
    mango(v);
    int res = mx-1;
    for (int j = sz(v)-1; j > sz(v)-1-cc; j--)
    {
      res+=v[j];
    }
    mango(mx);
    cout << res << '\n';
    
  }
  mango(sc);
  
  
  
}