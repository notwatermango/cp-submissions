// #include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
using namespace std;
#define int int64_t


signed main(){
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n, s;
  cin >> n >> s;
  int arr[n];
  // int dp[n];
  int sum=0;
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }
  sort(arr, arr+n);
  int midi = n/2;
  if(arr[midi] == s){
    cout << "0\n";
    return 0;
  }
  bool toright = false;
  if(arr[midi] < s){
    toright = true;
  }
  for (int i = 0; i < n; i++)
  {
    if(toright && i >= midi && arr[i] < s)
    sum+=abs(arr[i]-s);
    if(!toright && i <= midi && arr[i] > s)
    sum+=abs(arr[i]-s);
    
  }
  cout << sum <<'\n';
  

  
  return 0;
}