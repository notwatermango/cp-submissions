// #include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
using namespace std;
#define int int64_t


signed main(){
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n;
  cin >> n ;
  int x;
  int ze = 0;
  int on = 0;
  int sum = 1;
  for (int i = 0; i < n; i++)
  {
    cin >> x;
    if(x == 1){
      if(on){
        sum *= ze+1;
      }
      on++;
      ze = 0;
    }else{
      ze++;
    }
  }
  if(!on){
    sum = 0;
  }
  cout << sum << '\n';
  
  return 0;
}