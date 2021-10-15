#include <iostream>
using namespace std;

int solve(int a){
  while(a % 2 == 0){
    a/=2;
  }
  while(a % 3 == 0 ){
    a/=3;
  }
  return a;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  int a;
  cin >> a;
  a = solve(a);
  int b;
  
  for (int i = 1; i < n; i++)
  {
    cin >> b;
    b = solve(b);
    if(b != a){
      cout << "No\n";
      return 0;
    }
  }
  cout << "Yes\n";
  
  
  return 0;
}