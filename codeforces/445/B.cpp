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
#define int i64

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
int ct = 0;

void bfs(int st){
  vis[st] = true;
  int now = st;
  queue<int> Q;
  Q.push(st);
  while(!Q.empty()){
    now = Q.front();
    Q.pop();
    for(auto e: adj[now]){
      if(!vis[e]){
        vis[e] = true;
        // cout << e << '\n';
        ct++;
        Q.push(e);
      }
    } 
  }
}

void solv(){
  int n, m;
  cin >> n >> m;
  adj.assign(n, vector<int>());
  vis.assign(n, 0);
  for (int i = 0; i < m; i++)
  {
    int x, y;
    cin >> x >> y;
    x--;y--;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  for (int i = 0; i < n; i++)
  {
    if(!vis[i] && !adj[i].empty()){
      bfs(i);
    }
  }
  int a = ((int)1 << ct);
  cout << a <<'\n'; 
}