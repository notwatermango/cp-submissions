// #include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
using namespace std;
#define int int64_t


signed main(){
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n,m;
  cin >> n >> m;
  int minn;
  if(m == 0){
    cout << n << ' ' << n << '\n';
    return 0;
  }
  if(m >= (n+1)/2){
    minn = 0;
  } else {
    minn = n - m*2;
  }
  int maxx = 0;
  for (int i = 2; i <= n; i++)
  {
    if(i*(i-1)/2 >= m){
      maxx = i;
      break;
    }
  }
  cout << minn << ' ' << n - maxx << '\n';
  



  
  return 0;
}