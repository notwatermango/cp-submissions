// #include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
using namespace std;
// #define int int64_t


signed main(){
  ios_base::sync_with_stdio(false); cin.tie(0);
  string s;
  cin >> s;
  int a;
  cin >> a;
  while (a--)
  {
    int l,r,k;
    cin >> l >> r >> k;
    // cout << "OK";
    k%= r-l+1;
    k = r-l+1-k;
    string snew = "";
    // cout << l+k-1 << '\n';
    int ct = 0;
    for (int i = l+k-1; ct < r-l+1; i++)
    {
      if(i > r-1){
        i = l-1;
      }
      // cout << i << ' ';
      ct++;
      snew.push_back(s[i]);
    }
    
    // cout << snew << '\n';
    ct = 0;
    for (int i = l-1; i < r; i++)
    {
      s[i] = snew[ct];
      ct++;
    }
    
    
  }
  cout << s << '\n';
  
  return 0;
}