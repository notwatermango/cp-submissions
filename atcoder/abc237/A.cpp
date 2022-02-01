#include <bits/stdc++.h>
using namespace std;

int main(){
  long long n;
  cin >> n;
  long long two31 = pow(2,31);
  if(n < -two31 || n >= two31){
    cout << "No\n";
  } else cout << "Yes\n";
  return 0;
}