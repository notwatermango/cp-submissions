#include <iostream>
using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, p;
  cin>>n >> p;
  int c = 0;
  for (int i = 0; i < n; i++)
  {
    int a;
    cin>>a;
    if(a < p){
      c++;
    } else{
      continue;
    }
  }
  cout<<c<<'\n';
  
  return 0;
}