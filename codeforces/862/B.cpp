// #include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define int int64_t

vector<vector<int>> adj;
vector<int> vis;
vector<int> clr;

void colorise(int x, int c){
  clr[x] = c;
  for(auto e:adj[x]){
    if(!clr[e]){
      colorise(e, c*-1);
    }
  }
}

signed main(){
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n;
  cin >> n;
  adj.assign(n, vector<int>());
  vis.assign(n, 0);
  clr.assign(n, 0);
  for (int i = 0; i < n-1; i++)
  {
    int from, to;
    cin >> from >> to;
    from--;to--;
    adj[from].push_back(to);
    adj[to].push_back(from);
  }
  // is a tree
  // color
  int c = 1;
  for (int i = 0; i < n; i++)
  {
    if(clr[i] == 0){
      colorise(i,c);
    }
  }
  c = 0;
  for (int i = 0; i < n; i++)
  {
    if(clr[i] > 0) c++;
  }
  cout << (c-1)*(n-c-1)<<'\n';

  
  
  
  return 0;
}