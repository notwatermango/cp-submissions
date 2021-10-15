#include <iostream>
using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int64_t n,a,b,c;
  cin >> n >> a >> b >> c;
  if(n%4 == 0){
    cout << 0 << '\n';
    return 0;
  }
  int64_t res = 4*a;
  if(n%4 == 1){
    // need 3
    res = min(res, 3*a);
    res = min(res, c);
    res = min(res, a+b);

  } else if(n%4 == 2){
    // need 2
    res = min(res, 2*a);
    res = min(res, b);
    res = min(res, 2*c);
  } else if(n%4 == 3){
    // need 1
    res = min(res, a);
    res = min(res, c*3);
    res = min(res, c+b);
  }
  cout << res << '\n';
  
  
  return 0;
}