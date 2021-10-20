// #include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
// #define int int64_t


signed main(){
  ios_base::sync_with_stdio(false); cin.tie(0);
  map<int,int> ord;
  map<int,bool> vis;
  int n ; cin >> n ;
  int arr1[n];
  int arr2[n];
  for (int i = 0; i < n; i++)
  {
    cin >> arr1[i];
  }for (int i = 0; i < n; i++)
  {
    cin >> arr2[i];
  }
  int pt1,pt2;
  pt1 = pt2 = 0;
  int c = 0;
  // int a = 10;
  while (pt1 <n && pt2< n)
  {
    // cout << "LETSGO " << pt1 << ' ' << pt2 << '\n';
    if(vis[arr1[pt1]]) {
      pt1++;
      // cout << "lewat\n";
      continue;
    }
    if(arr1[pt1] == arr2[pt2]){
      vis[arr1[pt1]] = true;
      vis[arr2[pt2]] = true;
      pt1++;
      pt2++;
      // cout << "same\n";
      continue;
    }
    while (pt1<n&&pt2<n && arr1[pt1] != arr2[pt2])
    {
      vis[arr2[pt2]] = true;
      pt2++;
      c++;
      // cout<<pt1<<pt2;
    }
    // cout << "go\n";
    vis[arr1[pt1]] = true;
    pt1++;
    pt2++;
  }
  

  
  
  cout <<c << '\n';
  
  
  return 0;
}