// #include <bits/stdc++.h>
#include <iostream>
#include <utility>
#include <vector>
#include <numeric>
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
  cin >> tc;
  for(int i = 0; i < tc; ++i) {
    // cout << "Case #" << i+1 << ": ";
    solve();
  }
  
  return 0;
}

void solve(){
  int n;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }
  vector<int> res(n);
  for (int i = 0; i < n; i+=2)
  {
    res[i] = arr[i+1]*-1;
    res[i+1] = arr[i];
    int gc = gcd(res[i] , res[i+1]);
    res[i]/=gc;
    res[i+1]/=gc;
  }
  if(n%2 == 1){
    for (int i = 0; i < n-1; i++)
    {
    
    if(abs(res[i] - arr[n-1]) <= 10000 && abs(res[i] - arr[n-1]) != 0){
      
        res[n-1] = arr[i];
        res[i] += arr[n-1]*-1;
      break;
    } else if(abs(res[i] + arr[n-1]) <= 10000 && abs(res[i] + arr[n-1]) != 0){
        res[n-1] = arr[i]*-1;
        res[i] += arr[n-1];
        break;
    }
    }
  }
  // int sum = 0;
  for (int i = 0; i < n; i++)
  {
    cout << res[i] << ' ';
  }
  cout << '\n';
  
  

   
}