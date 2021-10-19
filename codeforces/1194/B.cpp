// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
// #define int int64_t


void solve(){
  int n,m;
  cin >> n >> m;
  char c;
  char arr[n][m];
  map<int,int> mx;
  map<int,int> my;
  vector<int> vx;
  vector<int> vy;
  int maxx = 0;
  int maxy = 0;
  int st = 0;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cin >> c;
      arr[i][j] = c;
      if(c == '*'){
        st++;
        mx[i]++;
        my[j]++;
        if(mx[i] > maxx){
          maxx = mx[i];
          vx.clear();
          vx.push_back(i);
        } else if(mx[i] == maxx){
          vx.push_back(i);
        }
        if(my[j] > maxy){
          maxy = my[j];
          vy.clear();
          vy.push_back(j);
        } else if(my[j] == maxy){
          vy.push_back(j);
        }
      }
    }
    
  }
  int f = 0;
  for(auto ey:vy){
    for(auto ex:vx){
      if(arr[ex][ey] == '.'){
        maxy++;
        f++;
        break;
      }
    }
    if(f) break;
  }
  if(st == 0) maxy++;
  cout << n + m - maxy - maxx << '\n';
  
  
}


signed main(){
  ios_base::sync_with_stdio(false); cin.tie(0);
  int tc; cin >> tc;
  while(tc--) {
    solve();
  }
  
  return 0;
}