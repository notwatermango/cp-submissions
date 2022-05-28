#include <bits/stdc++.h>
using namespace std;
int main() {
  map<int,int> ct;
  int q; cin >> q; for (int w = 0; w < q; ++w) {
    int cmd; cin >> cmd; if (cmd == 1) {
      int x; cin >> x; ct[x]++;
    } else if (cmd == 2) {
      int x, c; cin >> x >> c; c = min(c, ct[x]);
      ct[x] -= c; if (ct[x] == 0) ct.erase(x);
    } else {
      cout << (prev(ct.end())->first) - ct.begin()->first << '\n';
    }
  }
  return 0;
}