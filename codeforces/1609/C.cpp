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

const int N = 1010000;
int lp[N+1];
vector<int> pr;

void precalc(){
  for (int i=2; i<=N; ++i) 
  {
    if (lp[i] == 0) {
      lp[i] = i;
      pr.push_back (i);
    }
    for (int j=0; j<(int)pr.size() && pr[j]<=lp[i] && i*pr[j]<=N; ++j)
    {
      lp[i * pr[j]] = pr[j];
    }
  }
}

signed main(){
  fastmango;
  precalc();
  i32 tc = 1;
  cin >> tc;
  for(i32 i = 0; i < tc; ++i) {
    // cout << "Case #" << i+1 << ": ";
    solv();
  }
  return water;
}


void solv(){
  int n,e;
  cin >> n >> e;
  int arr[n];
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }
  // vector<int> vis(n);
  int sum = 0;
  vector<int> c1(n,0);
  for (int i = 0; i < n; i++)
  {
    // if(arr[i] == 1 && !vis[i]){
    //   vis[i]++;
    //   int k = 1;
    //   bool cx = 0;
    //   int cc = 0;
    //   while (i+e*k < n && (arr[i+e*k] == 1 || ((lp[arr[i+e*k]] == arr[i+e*k])&& !cx)) )
    //   {
    //     if(arr[i+e*k] != 1) cx = 1;
    //     vis[i+e*k]++;
    //     sum+=k;
    //     cc +=k;
    //     k++;
    //   }
    //   if(!cx) sum-=cc;
    // }
    if(lp[arr[i]] == arr[i] && arr[i] != 1){
      // vis[i]++;
      int cc = 0;
      int k =1;
      while(i+e*k < n && arr[i+e*k] == 1){
        // vis[i+e*k]++;
        k++;
      }
      int k2 = -1;
      while(i+e*k2 > -1 && arr[i+e*k2] == 1){
        // vis[i+e*k]++;
        k2--;
      }
      // if(cc && c1[i%e]) cout << c1[i%e] << '\n';
      k-=1;
      cc += k;
      k2 *=-1;
      k2 -=1;
      cc += k2*(k+1);
      mango(k);
      mango(k2);
      // cc += c1[i%e]
      sum += cc;
    }
  }
  // mango(c1);
  cout << sum <<'\n';
  
  
}