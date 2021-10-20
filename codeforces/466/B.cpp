// #include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
using namespace std;
#define int int64_t


signed main(){
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n, a,b;
  int rawa,rawb;
  cin >> n >> rawa >> rawb;
  a = rawa;
  b = rawb;
  int nn = n*6;
  int ab = a*b;
  if(ab >= nn){
    // ok ?
    cout << ab << '\n';
    cout << a << ' ' << b << '\n';
  } else {
    int aa = min(a,b);
    int bb = max(a,b);
    a = aa;
    b = bb;
    int ok;
    int res;
    for (int k = 0; k < nn; k++)
    {
      ok = 0;
      int cek = nn+k;
      for (int i = a; i*i <= nn; i++)
      {
        if(cek%i == 0){
          if(cek/i < b){
            break;
          }else {
            ok = i;
            res = cek;
            break;
          }
        }
      }
      if(ok) break;
    }
    if(ok){
      cout << res << '\n';
      if(rawa > rawb){
        cout << res/ok << ' ' << ok << '\n';
      } else {
        cout << ok << ' ' << res/ok << '\n';
      }
    } else{
      cout << "Bye world\n";
    }
    

  }
  return 0;
}