// #include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
// #define int int64_t


signed main(){
  ios_base::sync_with_stdio(false); cin.tie(0);
  int a,b;
  cin >> a >> b;
  int arr1[a];
  int arr2[b];
  int arr3[b];
  for (int i = 0; i < a; i++)
  {
    cin >> arr1[i];
  }
  for (int i = 0; i < b; i++)
  {
    cin >> arr2[i];
    arr3[i] = arr2[i];
  }
  sort(arr1, arr1+a);
  sort(arr2, arr2+b);
  int pt1 = 0;
  int pt2 = 0;
  map<int,int> ctr;
  int sum = 0;
  while (pt1 != a && pt2 != b)
  {
    if(arr1[pt1] <= arr2[pt2]){
      pt1++;
      sum++;
    } else {
      pt2++;
    }
    ctr[arr2[pt2]] = sum;
  }
  for (int i = pt2; i < b; i++)
  {
    ctr[arr2[i]] = a;
  }
  

  for (int i = 0; i < b; i++)
  {
    cout << ctr[arr3[i]] << ' ';
  }
  
  
  
  
  return 0;
}