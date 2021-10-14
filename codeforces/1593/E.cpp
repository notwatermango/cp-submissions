#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<vector<int>> adj;
vector<int> ctr;

void solve(){
  int n, k;
  cin >> n >> k;
  adj.assign(n, vector<int>());
  ctr.assign(n, 0);

  for (int i = 1; i < n; i++)
  {
    int a,b;
    cin >> a >> b;
    a--; b--;
    adj[a].push_back(b);
    adj[b].push_back(a);
    ctr[a]++;
    ctr[b]++;
  }

  stack<int> aw;
  stack<int> next;

  for (int i = 0; i < n; i++)
  {
    if(ctr[i] == 1){
      aw.push(i);
    }
  }
  int nodes = n;

  for (int i = 0; i < k; i++)
  {
    if(nodes == 1 || nodes == 2) {
      nodes = 0;
      break;
    }
    while (!aw.empty())
    {
      int now = aw.top();
      aw.pop();
      if(ctr[now] != 1){
        continue;
      }
      ctr[now] -= 1;

      for(auto e:adj[now]){
        if(ctr[e] == 2){
          next.push(e);
        } 
        ctr[e]--;
      }

      nodes--;
    }
    while (!next.empty())
    {
      aw.push(next.top());
      next.pop();
    }
  }
  cout<<nodes<<'\n';
  

}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int tc;
  cin >> tc;
  while (tc--)
  {
    solve();
  }
  
  
  return 0;
}