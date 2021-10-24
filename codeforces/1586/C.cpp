// #include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

// #define int int64_t
#define MOD 1000000007
#define LLINF 4202000013666420666
#define INF 1000177013

void solve();

signed main(){
  ios_base::sync_with_stdio(false); cin.tie(0);
  int tc = 1;
  // cin >> tc;
  for(int i = 0; i < tc; ++i) {
    // cout << "Case #" << i+1 << ": ";
    solve();
  }
  
  return 0;
}

void solve(){
  int n,m;
  cin >> n >> m;
  char arr[n][m];
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cin >> arr[i][j];
    }
  }
  int sum = 0;
  int v[m];
  for (int j = 0; j < m; j++)
  {
    for (int i = 0; i < n; i++)
    {
      if(i > 0 && j > 0){
        if(arr[i-1][j] == 'X' && arr[i][j-1] == 'X'){
          sum++;
          break;   
        }
      }
    }
    v[j] = sum;
  }
  for (int i = 0; i < m; i++)
  {
    // cout << v[i] << '\n';
  }
  
  int q;
  cin >> q;
  for (int i = 0; i < q; i++)
  {
    int x,y;
    cin >> x >> y;
    x--;y--;
    if(v[y] - v[x] > 0){
      cout << "NO\n";
    } else{
      cout << "YEs\n";
    }
  }
  
  
}