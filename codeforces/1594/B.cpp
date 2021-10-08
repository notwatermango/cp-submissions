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

int near2(long long n){
  int res = 1;
  long long tmp = 2;
  while (tmp <= n)
  {
    tmp *= 2;
    res++;
  }
  return res - 1;
  

}

int solve(long long n, long long k){
  if(k == 0) return 0;
  if(n == 0) return 0;
  if(k == 1) return 1;
  int col = near2(k);
  // if(col == 0) return 1;

  int res = powmod(n, col);

  int ne = k - powmod(2, col);
  // cout << col << ' '<<res<<' ';
  // cout<<ne<<'\n';

  res += solve(n, ne);
  return res % (1000000000+7);
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int tc;
  cin >> tc;
  while (tc--)
  {
    long long n, k;
    cin>>n>> k;
    cout << solve(n, k)<<'\n';
  }

  return 0;
}