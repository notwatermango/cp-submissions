// #include <bits/stdc++.h>
#include <algorithm>
#include <queue>
#include <iostream>
#include <iomanip>
#include <map>
#include <set>
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
i64 powllm(i64 a, i64 b, i64 m) {a %= m; i64 res = 1; while (b > 0) { if (b & 1) res = res * a % m; a = a * a % m; b >>= 1; } return res; }
i64 powll(i64 a, i64 b) {i64 res = 1; while (b > 0) { if (b & 1) res = res * a; a = a * a; b >>= 1; } return res; }
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

int n,m, c = 0;
vector<vector<int>> vis;
vector<vector<char>> arr;
int xp[] = {0 , 0 , 1 , -1};
int yp[] = {1, -1 , 0 , 0};

bool dfs(int si, int sj, int fi, int fj){
  // cout << si << sj << '\n';
  vis[si][sj] = c;
  for (int i = 0; i < 4; i++)
  {
    int xx = si + xp[i];
    int yy = sj + yp[i];
    if(xx == fi && yy == fj) continue;
    if(not (xx < n && xx > -1 && yy < m && yy > -1)) continue; 
    if(arr[xx][yy] != arr[si][sj]) continue;
    if(vis[xx][yy]){
      if(fi!=INF && vis[xx][yy] == vis[fi][fj]) return true;
      continue;
    }
    if(dfs(xx, yy, si, sj)) return true;
  }
  return false;
  

}

void solv(){
  cin >> n >> m;
  vis.assign(n, vector<int>(m, 0));
  arr.assign(n, vector<char>(m));
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cin >> arr[i][j];
    }
  }
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      if(not vis[i][j]){
        c++;
        if(dfs(i, j, INF, INF)){
          cout << "Yes\n";
          return;
        }
      }
    }
    
  }
  cout << "No\n";
  
}