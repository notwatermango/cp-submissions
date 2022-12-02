#include <bits/stdc++.h>
using namespace std;

signed main () {
    
    map<string, int> pp;
    int n; cin >> n;
    for (int i = 0; i < n; i++)
    {
        int ii = i+1;
        string s; cin >> s; if (pp.count(s)) {
            cout << s << "(" << pp[s] << ")\n";
        } else {
            cout << s << '\n';
        }
        pp[s]++;
    }
    
}