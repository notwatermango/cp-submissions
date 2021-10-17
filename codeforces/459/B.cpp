#include <iostream>
#include <algorithm>
using namespace std;

#define int int64_t

signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  int maxx= 0, minn = 1234567890;
  int mxc, mnc;
  mxc = mnc = 0;
  for (int i = 0; i < n; i++)
  {
    int q;
    cin >> q;
    if(q > maxx){
      maxx = q;
      mxc = 1;
    } else if( q == maxx){
      mxc++;
    }
    if(q < minn){
      minn = q;
      mnc = 1;
    } else if(q == minn){
      mnc++;
    }
  }
  if(maxx - minn == 0){
    // Nc2
    cout<<"0 "<<mxc*(mxc-1)/2<<'\n';
    return 0;
  }
  cout<<maxx - minn << ' ' << mnc*mxc;
  
  return 0;
}