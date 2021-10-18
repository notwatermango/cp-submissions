#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
using namespace std;
#define int int64_t


signed main(){
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n,k;
  cin >> n >> k;
  if(k == 1) {
    cout <<  n <<'\n';
    return 0;
  }// ! Lupa melulu :(
  // cout<<bitset<64>(n)<<" e\n";
  int lz = __builtin_clzll(n);
  // cout<<"lz "<<lz<<'\n';
  int twos = 64-lz;
  // cout<< "twz " << twos << '\n';
  int a = ((int)1<<(twos)) - 1;
  cout << a <<'\n';
  // int ok = min(twos, k);
  // int ze = twos-ok;
  // cout << "ze "<< ze<<'\n';
  // int mx = ((int)1<<(ze));
  // cout << mx << '\n';
  // for(int i = 1; i < mx ;){
  //   a^=i;
  //   i = i<<1;
  //   // cout << i <<'\n';
  // }
  // cout << a <<'\n';
  return 0;
}