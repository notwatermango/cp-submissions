/*

try constructing bipartite graph

if a says b impostor, a and b differs
else create a fake node to differs to a and b

*/

#include <iostream>
#include <vector>
using namespace std;

vector<vector<pair<int, int>>> adj;
vector<int> vis;
vector<int> ct (2, 0);
bool bad;
int v, e, fcount;


void dfs(int start){
  if(start < v){
    ct[vis[start]]++;
  }
  for(auto e: adj[start]){
    if(vis[start] == vis[e.first] && vis[start] != -1) {
      bad = true;
      return;
    } 
    if(vis[e.first] != -1) continue;
    vis[e.first] = vis[start] ^ 1;
    dfs(e.first);
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int tc;
  cin >> tc;
  while (tc--)
  {
    bad = false;
    cin >> v >> e;
    fcount = v;
    adj.assign(v+e+2, vector<pair<int, int>>());
    vis.assign(v+e+2, -1);
    while(e--)
    {
      int from,to;
      string str;
      cin>> from >> to >> str;
      from--;
      to--;
      if(str == "imposter"){
        adj[from].push_back({to, 1});
        adj[to].push_back({from, 1});
      } else {
        // teammate
        adj[from].push_back({fcount, 1});
        adj[fcount].push_back({from, 1});
        adj[to].push_back({fcount, 1});
        adj[fcount].push_back({to, 1});
        fcount++;
      }
    }
    int res = 0;
    for (int i = 0; i < v; i++)
    {
      if(vis[i] != -1) {
        continue;
      }
      if(adj[i].empty()){
        res++;
        continue;
      }
      vis[i] = 0;
      ct[0] = ct[1] = 0;
      dfs(i);
      res += max(ct[0],ct[1]);
    }
    if(bad){
      cout<<"-1\n";
      continue;
    }
    cout<<res<<'\n';
    
  }
  

  


  return 0;
}