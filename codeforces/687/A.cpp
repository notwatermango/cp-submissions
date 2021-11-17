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

vector<vector<int>> adj;
vector<int> vis;
bool bad = false;

void bfs(int st){
  vis[st] = 1;
  queue<int> q;
  q.push(st);
  while(not q.empty()){
    int now = q.front();
    q.pop();
    for(auto e: adj[now]){
      if(!vis[e]) {
        q.push(e);
        vis[e] = vis[now] * -1;
      }
      if(vis[e] == vis[now]){
        bad = true;
      }
    }
  }
}

void solv(){
  int n,m;
  cin >> n >> m;
  adj.assign(n, vector<int>());
  vis.assign(n, 0);
  int fr, to;
  for (int i = 0; i < m; i++)
  {
    cin >> fr >> to;
    fr--; to--;
    adj[fr].push_back(to);
    adj[to].push_back(fr);
  }
  for (int i = 0; i < n; i++)
  {
    if(!vis[i]) bfs(i);
  }
  if(bad){
    cout << "-1\n";
    return;
  }
  int cta = 0;
  int ctb = 0;
  for(int i = 0; i < sz(vis); ++i){
    if(vis[i] == 1){
      cta++;
    } else {
      ctb++;
    }
  }
  cout << cta << '\n';
  for(int i = 0; i < sz(vis); ++i){
    if(vis[i] == 1){
      cout << i + 1 << ' ';
    } 
  }
  cout << '\n' << ctb << '\n';
  for(int i = 0; i < sz(vis); ++i){
    if(vis[i] == -1){
      cout << i + 1 << ' ';
    } 
  }
  cout <<'\n';
  
}