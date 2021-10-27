#include <bits/stdc++.h>
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

vector<int> v;

int fup(int x){
  while (v[x] != x)
  {
    x = v[x];
  }
  return x;
}

void uf(int x, int y){
  v[fup(x)] = v[fup(y)];
}

void solv(){
  int n, m;
  cin  >> n >> m;
  v.assign(m+1, -1);
  mango(v);
  int ct = -1;
  
  for (int i = 0; i < n; i++)
  {
    int x;
    cin >>x;
    if(x == 0){
      ct++;
      continue;
    } 
    // int pp = -1;
    // int A[x];
    int mem;
    cin >> mem;
    if(v[mem] == -1) v[mem] = mem;
    for (int j = 1; j < x; j++)
    {
      int a;
      cin >> a;
      if(v[a] == -1) v[a] = a;
      uf(a,mem);
      mem = a;
    }
    
  }

  mango(v);
  int vn = sz(v);
  bool ok = false;
  for (int i = 1; i < vn; i++)
  {
    if(v[i] != -1) ok =true;
    if(i == v[i]) ct++;

  }
  if(!ok) ct++;

  
  cout << ct << '\n';
}