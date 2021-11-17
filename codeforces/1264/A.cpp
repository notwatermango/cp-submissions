// #include <bits/stdc++.h>
#include <iostream>
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
#define int i64

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
  int arr[n];
  for (int i = 0; i < n; i++)
  { 
    cin >> arr[i];
  }
  if(n < 3){
    cout << "0 0 0\n";
    return;
  }
  vector<int> v;
  for (int i = 0; i < n/2; i++)
  {
    v.push_back(arr[i]);
  }
  if(v.back() == arr[n/2]){
    while (!v.empty() && v.back() == arr[n/2])
    {
      v.pop_back();
    }
  }
  if(v.empty()){
    cout << "0 0 0\n";
    return;
  }
  mango(v);
  vector<int> qq;
  int ct = 0;
  int a = v[0];
  for(auto e:v){
    if(a != e) {
      qq.push_back(ct);
      a = e;
      ct = 0;
    }
    ct++;
  }
  if(ct) qq.push_back(ct);
  if(sz(qq) < 3){
    cout << "0 0 0\n";
    return;
  }
  mango(qq);
  int g = qq[0];
  int s = 0;
  int si = 0;
  for (int i = 1; i < sz(qq) -1; i++)
  {
    s+=qq[i];
    si = i;
    if(s > g) break;
  }
  if(not(s > g)){
    cout << "0 0 0\n";
    return;
  }
  int b = 0;
  for (int i = si+1; i < sz(qq); i++)
  {
    b+=qq[i];
  }
  if(not(b > g)){
    cout << "0 0 0\n";
    return;
  }
  cout << g << ' ' << s << ' ' << b << '\n';
  
  
  
  
  

  
  
}