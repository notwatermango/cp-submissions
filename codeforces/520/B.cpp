// #include <bits/stdc++.h>
#include <iostream>
#include <queue>
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

vector<int> vis(2*10001, INF);

int bfs(int st, int dst){
  queue<int> Q;
  Q.push(st);
  while(!Q.empty()){
    int now = Q.front();
    if(now == dst) return vis[dst];
    Q.pop();
    if(vis[now] < vis[now-1]){
      Q.push(now-1);
      vis[now-1] = vis[now] + 1;
    }
    if(now*2 < 2*10000 && vis[now] < vis[now*2]){
      Q.push(now * 2);
      vis[now*2] = vis[now] + 1;
    }

  }
  return -1;
}

void solv(){
  int n,m;
  cin >> n >> m;
  vis[0] = 0;
  vis[n] = 0;
  if(n > m){
    cout << n-m << '\n';
    return;
  }
  if(n == m){
    cout << "0\n";
    return;
  }
  cout << bfs(n, m) << '\n';

}