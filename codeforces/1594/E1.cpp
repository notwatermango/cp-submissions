#include <iostream>
#include <cmath>
using namespace std;

long long powmod(long long base, long long exp) {
  long long res = 1;
  while (exp > 0)
  {
    if (exp % 2 == 1) {
      res = (res * base) % (1000000000 + 7);
    }
    exp = exp >> 1;
    base = (base * base) % (1000000000 + 7);
  }
  return res;
}

long long solve(long long n){
  if(n == 1) return 6;
  long long res = 6;
  long long fours = pow(2, n) - 2;
  res *= powmod(4, fours);
  return res % (1000000000 + 7);
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  long long n;
  cin>>n;
  cout<<solve(n)<<'\n';
  return 0;
}