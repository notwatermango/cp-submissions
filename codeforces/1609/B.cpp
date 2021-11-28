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

void solv(){
  int n,q;
  cin >> n >> q;
  string s;
  cin >> s;
  // int ok = 0;
  vector<int> abc(n);
  int ct = 0;
  for (int i = 0; i < n; i++)
  {
    if(s[i] == 'a' && i < n-2) {
      if(s[i+1] == 'b' && s[i+2] == 'c'){
        abc[i] = 1;
        abc[i+1] = 1;
        abc[i+2] = 1;
        ct++;
      }
    }
    if(s[i] == 'b' && i < n-1 && i > 0){
      if(s[i+1] == 'c' && s[i-1] == 'a'){
        abc[i] = 1;
        abc[i+1] = 1;
        abc[i-1] = 1;
        ct++;
      }
    }
    if(s[i] == 'c' && i > 1){
      if(s[i-2] == 'a' && s[i-1] == 'b'){
        abc[i] = 1;
        abc[i-2] = 1;
        abc[i-1] = 1;
        ct++;
      }
    }
  }
  ct/=3;
  mango(abc); 
  for (int i = 0; i < q; i++)
  {
    int x; char cj;
    cin >> x >> cj; x--;
    if(s[x] == cj) {
      cout << ct << '\n';
      continue;
    }
    if(abc[x]){
      if(s[x] == 'a'){
        abc[x] = 0;
        abc[x+1] = 0;
        abc[x+2] = 0;
      } 
      if(s[x] == 'b'){
        abc[x] = 0;
        abc[x+1] = 0;
        abc[x-1] = 0;
      }
      if(s[x] == 'c'){
        abc[x] = 0;
        abc[x-2] = 0;
        abc[x-1] = 0;
      }
      ct--;
      if(cj == 'a' && x < n-2){
        if(s[x+1] == 'b' && s[x+2] == 'c'){
          ct++;
          abc[x] = 1;
          abc[x+1] = 1;
          abc[x+2] = 1;
        }
      }
      if(cj == 'c' && x > 1){
        if(s[x-1] == 'b' && s[x-2] == 'a'){
          ct++;
          abc[x] = 1;
          abc[x-1] = 1;
          abc[x-2] = 1;
        }
      }
    } else{
      if(cj == 'a' && x < n-2){
        if(s[x+1] == 'b' && s[x+2] == 'c'){
          ct++;
          abc[x] = 1;
          abc[x+1] = 1;
          abc[x+2] = 1;
        }
      } else if(cj == 'b' && x < n-1 && x > 0){
        if(s[x-1] == 'a' && s[x+1] == 'c'){
          ct++;
          abc[x] = 1;
          abc[x-1] = 1;
          abc[x+1] = 1;
        }
      } else if(cj == 'c' && x > 1){
        if(s[x-1] == 'b' && s[x-2] == 'a'){
          ct++;
          abc[x] = 1;
          abc[x-1] = 1;
          abc[x-2] = 1;
        }
      }
    }
    cout << ct <<'\n';
    mango(abc);
    s[x] = cj;
    // cout << s  <<'\n';
  }
  
  
}