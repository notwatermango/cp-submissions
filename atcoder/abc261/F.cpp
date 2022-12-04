#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
using ost = tree<pair<int,int>, null_type, less<pair<int,int>>, rb_tree_tag, tree_order_statistics_node_update>;
#define int long long
int c[312345], x[312345];
signed main () {
    int n; cin >> n;
    map<int,int> ccount;
    for (int i = 0; i < n; i++)
    {
        cin >> c[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> x[i];
    }
    int sw = 0;
    ost bruh;
    vector<ost> rip(312345);
    for (int i = 0; i < n; i++)
    {   
        int bm; // greater than x[i]
        int bmc; // greater but same color
        bruh.insert(make_pair(-x[i], -i));
        bm = bruh.order_of_key(make_pair(-x[i], -i));
        rip[c[i]].insert(make_pair(-x[i], -i));
        bmc = rip[c[i]].order_of_key(make_pair(-x[i], -i));
        // cout << "de " << bm << ' ' << bmc << '\n';
        sw += bm - bmc;
    }
    
    cout << sw << '\n';
    
    return 0;
}