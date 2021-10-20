// #include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <cmath>
using namespace std;
#define int int64_t


signed main(){
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n;
  cin >> n;
  int arr[n][n];
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cin >> arr [i][j];
    }
  }

  int one = arr[0][1]*arr[2][0]/arr[1][2];
  int ff = sqrtl(one);
  cout << ff;
  for (int i = 1; i < n; i++)
  {
    cout<< ' ' << arr[0][i]/ff ;
  }
  cout << '\n';
  
  
  return 0;
}