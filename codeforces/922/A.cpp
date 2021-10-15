#include <iostream>
using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int a,b;
  cin >> a >> b;
  if(
    ((b == 0 || b == a) && a != 0)
  ||((a-(b-1) )% 2 !=0)
  ||(a-(b-1) < 0)
  ||(a == 0 && b>1)
  ||(b == 1 && a != 0)
    ){
    cout << "No\n";
  } else {
    cout << "Yes\n";
  }
  return 0;
}