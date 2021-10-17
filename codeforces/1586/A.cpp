// #include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
using namespace std;
// #define int int64_t

bool isPrime(int x) {
  for (int i = 2; i * i <= x; i++) 
  {
    if (x % i == 0)
      return false;
  }
  return true;
}

void solve(){
  int n;
  cin >>n;
  int arr[n];
  int sum = 0;
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
    sum+=arr[i];
  }

  if(!isPrime(sum)){
    cout << n << '\n';
    for (int i = 0; i < n; i++)
    {
      cout << i+1 <<' ';
    }
    cout << '\n';
    return;
  } else{
    for (int i = 0; i < n; i++)
    {
      if(!isPrime(sum-arr[i])){
        cout << n-1 << '\n';
        for (int j = 0; j < n; j++)
        {
          if(j == i) continue;
          cout << j+1 << ' ';
        }
        cout << '\n';
        return;
        
      }
    }
    
  }
  
}


signed main(){
  ios_base::sync_with_stdio(false); cin.tie(0);
  int tc; cin >> tc;
  while(tc--) {
    solve();
  }
  
  return 0;
}