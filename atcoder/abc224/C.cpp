// #include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <cmath>
using namespace std;

#define int int64_t
#define MOD 1000000007
#define LLINF 4202000013666420666
#define INF 1000177013

void solve();

signed main(){
  ios_base::sync_with_stdio(false); cin.tie(0);
  int tc = 1;
  // cin >> tc;
  for(int i = 0; i < tc; ++i) {
    // cout << "Case #" << i+1 << ": ";
    solve();
  }
  
  return 0;
}

void solve(){
  int n;
  cin >> n;
  long double x[n], y[n];
  for (int i = 0; i < n; i++)
  {
    cin >> x[i] >> y[i];
  }
  int ct = 0;
  // cout << "C";
  for (int i = 0; i < n-2; i++)
  {
    for (int j = i+1; j < n-1; j++)
    {
      // double og1 = ((double) x[i] - (double) x[j] )/ ((double) y[i] - (double)y[j]);
      // if(y[i] == y[j]) {
      //   og1 = -123.34567;
      // } 
      for (int k = j+1; k < n; k++)
      {
        long double g1 = 1234567891011;
        long double g2 = 1234567891011;
        if(y[i] != y[j]) g1 = (x[i]-x[j])/ (y[i]-y[j]);
        if(y[i] != y[k]) g2 = (x[i]-x[k])/ (y[i]-y[k]);
        if(g1 > g2){
          long double tmp = g1;
          g1 = g2;
          g2 = tmp;
        }
        if(g2 - g1 < 1e-60) continue;
        ct++;
        // double a,b,c;
        // a = sqrt(
        //   (x[i]-x[j]) * (x[i] - x[j]) + 
        // ((y[i]-y[j]) * (y[i] - y[j])));
        // b = sqrt(
        //   (x[i]-x[k]) * (x[i] - x[k]) + 
        // ((y[i]-y[k]) * (y[i] - y[k])));
        // c = sqrt(
        //   (x[j]-x[k]) * (x[j] - x[k]) + 
        // ((y[j]-y[k]) * (y[j] - y[k])));
        // double q = a+b+c;
        // q/=2;
        // // cout << q-a <<' '<< q-b<<' ' << q-c << '\n';
        // // cout << q <<'\n';
        // if(q-a < 1e-64 || q-b < 1e-64 || q-c < 1e-64){
        //   // cout << "qq";
        // } else {
        //   // cout << "OK";
        //   ct++;
        // }
        // double g1 = og1;
        // double g2 = ((double) x[i] - (double) x[k] )/ ((double) y[i] - (double)y[k]);
        // if(y[i] == y[k]) g2 = -123.34567;
        // cout << g2 << ' ' << g1 << '\n';
        // cout << "TES " << y[i] << y[j] << '\n';
        // if(g1 > g2){
        //   double tmp = g1;
        //   g1 = g2;
        //   g2 = tmp;
        // }
        // if(
        //   (x[i] == x[j] && x[i] == x[k]) 
        //   ||
        //   (y[i] == y[j] && y[j] == y[k])
        //   ||
        //   ( g2 - g1 < 1e-6)
          
        // ){
        //   continue;
        // }
        // cout << x[i] <<' '<< y[i] << ' ' << x[j] << ' ' << y[j] << ' ' << x[k] << ' ' << y[k] << '\n' << '\n';
        // c++;

      }
      
    }
    
  }
  cout << ct << '\n';
  
  
}