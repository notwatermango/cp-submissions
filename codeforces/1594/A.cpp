#include <iostream>
using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int tc;
  cin>>tc;
  while (tc--)
  {
    unsigned long long a;
    cin>> a;
    if(a != 1){
      cout<<'-';
    }
    cout<<a - 1<<' ' << a<<'\n';
  }
  
  return 0;
}