// #include <bits/stdc++.h>
#include <iostream>
#include <map>
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
  string s1,s2;
  cin >> s1 >> s2;
  int n1 = sz(s1);
  int n2 = sz(s2);
  bool b1,b2,ss;
  b1 = b2 = ss = false;
  if(n1 > n2){
    b1 = true;
    int pt1 = 0;
    bool bad = false;
    for (int i = 0; i < n2; i++)
    {
      while(pt1 < n1 && s1[pt1] != s2[i]){
        pt1++;
      }
      if(s1[pt1] != s2[i]){
        bad= true;
      }
      pt1++;
    }
    if(!bad){
      cout << "automaton\n";
      return;
    }
    
  } else if(n2 > n1){
    cout << "need tree\n";
    return;
  }
  ss = true;
  map<char,int> m1,m2;
  for (int i = 0; i < n1; i++)
  {
    m1[s1[i]]++;
  }
  for (int i = 0; i < n2; i++)
  {
    m2[s2[i]]++;
  }
  for (int i = 0; i < 26; i++)
  {
    if(m2[i+'a'] > m1[i+'a']){
      ss = false;
    }
  }
  if(!ss){
    cout << "need tree\n";
    return;
  }
  if(!b1){
    cout << "array\n";
    return;
  }
  cout << "both\n";

  
  
  
}