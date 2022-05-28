#include <bits/stdc++.h>
using namespace std;
int main() {
  int64_t n, a, b; cin >> n >> a >> b;
  int64_t sn = (n+1)*n/2;
  int64_t ab = lcm(a,b);
  int64_t lasta = n-(n%a), lastb = n-(n%b);
  int64_t lastab = n-(n%ab);
  int64_t firsta = a, firstb = b;
  int64_t firstab = ab;
  int64_t acount = n/a, bcount = n/b;
  int64_t abcount = n/ab;
  int64_t sa = (firsta + lasta)*acount/2;
  int64_t sb = (firstb + lastb)*bcount/2;
  int64_t sab = (firstab + lastab)*abcount/2;
  cout << sn - sa - sb + sab << '\n';

  return 0;
}