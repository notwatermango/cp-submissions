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

vector<set<int>> adj;
vector<bool> vis;

int node, edge;

void bfs(int st){
  queue<int> q;
  q.push(st);
  vis[st] = 1;
  node++;
  while (not q.empty())
  {
    int now = q.front();
    q.pop();
    for(auto e: adj[now]){
      edge++;
      if(!vis[e]){
        q.push(e);
        vis[e] = 1;
        node++;
      }
    }
  }
  
}

void solv(){
  int n, m;
  cin >> n >> m;
  adj.assign(n, set<int>());
  vis.assign(n, 0);
  for (int i = 0; i < m; i++)
  {
    int fr, to;
    cin >> fr >> to;
    fr--; to--;
    adj[fr].insert(to);
    adj[to].insert(fr);
  }
  bool sad = 0;
  for (int i = 0; i < n; i++)
  {
    node = edge = 0;
    if(vis[i]) continue;
    bfs(i);
    edge/=2;
    // cout << node << ' ' << edge << '\n';
    if(node > 2 && edge != node*(node -1)/2){
      sad = 1;
    }
  }
  if(sad) cout << "NO\n";
  else cout <<"YES\n";  

  
}
