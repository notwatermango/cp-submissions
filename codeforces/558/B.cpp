#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
using namespace std;
// #define int int64_t

// ! WA try multiple max eqs

signed main(){
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n;
  cin >> n;
  int arr[n];
  map<int,int> m;
  map<int,int> sta;
  map<int,int> end;
  int maxx = 0;
  vector<int>v;
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
    m[arr[i]]++;
    if(m[arr[i]] == 1){
      sta[arr[i]] = i;
    }
    end[arr[i]] = i;
    if(m[arr[i]] > maxx){
      v.clear();
      v.push_back(arr[i]);
      maxx=m[arr[i]];
    } else if(m[arr[i]] == maxx){
      v.push_back(arr[i]);
    }
  }
  int minn = 12345678;
  int ggs = -1;
  int gge = -1;
  for(auto e: v){
    if(end[e] - sta[e] < minn){
      ggs = sta[e];
      gge = end[e];
      minn = end[e]-sta[e];
    }
  }
  cout << ggs+1 << ' ' << gge+1 << '\n';
  
  
  return 0;
}