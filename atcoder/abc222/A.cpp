#include <iostream>
using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  string a;
  cin>>a;
  while (a.length() < 4)
  {
    a = '0' + a;
  }
  cout<<a<<'\n';
  return 0;
}