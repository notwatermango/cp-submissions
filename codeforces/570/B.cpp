// #include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
using namespace std;
// #define int int64_t

// IMPLEMENTATION !!!!!!!!

signed main(){
  ios_base::sync_with_stdio(false); cin.tie(0);
  int m,n;
  cin >> m >> n;
  int res = m;
  res/=2;
  if(res == n){
    res++;
  } else if(res > n){
    res = n+1;
  } else {
    res = n-1;
  }
  if(res > m){
    res--;
  } else if(res < 1){
    res++;
  }
  // cout << m << " /2= " << m/2 << '\n';
  cout << res <<'\n';
  return 0;
}