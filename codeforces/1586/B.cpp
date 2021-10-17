#include <bits/stdc++.h>
using namespace std;
// #define int int64_t

int n,m;

vector<vector<pair<int,int>>> rt;
vector<vector<int>> adj;
vector<bool> vis;
vector<int> ct;

void solve(){
  cin>>n>>m;
  rt.assign(n, vector<pair<int,int>>());
  adj.assign(n, vector<int>());
  vis.assign(n, false);
  ct.assign(n, 0);
  for (int i = 0; i < m; i++)
  {
    int a,b,c;
    cin >> a >> b >> c;
    a--;
    b--;
    c--;
    rt[b].push_back({a,c});
    ct[b]++;
  }
  int root = 0;
  for (int i = 0; i < n; i++)
  {
    if(ct[i] == 0){
      root = i;
    }
  }
  for (int i = 0; i < n; i++)
  {
    if(i == root) continue;
    cout << root+1 <<' '<<i+1<<'\n';
  }
  
  
  
  
  
  
  
  
}


signed main(){
  ios_base::sync_with_stdio(false); cin.tie(0);
  int tc; cin >> tc;
  while(tc--) {
    solve();
  }
  
  return 0;
}