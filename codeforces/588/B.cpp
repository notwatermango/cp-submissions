// #include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
using namespace std;
#define int int64_t


signed main(){
  ios_base::sync_with_stdio(false); cin.tie(0);
  int a;
  cin >> a;
  int res = a;

  for (int i = 2; i*i <= a; i++)
  {
    if(a%i == 0){
      a/=i;
    }
    while(a%i == 0){
      res/=i;
      a/=i;
    }
  }
  cout << res << '\n';
    
  return 0;
}