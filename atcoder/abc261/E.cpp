#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main () {
    int n, c; cin >> n >> c;
    vector<int> andz(34); // nearest zero
    vector<int> orz(34); // nearest one
    vector<int> xorz(34);
    vector<vector<int>> xorzsw(n+3, vector<int>(34)); // pref of xor
    // for (int i = 0; i < 33; i++)
    // {
    //     if (((int) 1 << i) & c) {
    //         orz[i] = 1;
    //     } else andz[i] = 1;
    // }
    
    for (int i = 2; i < n + 2; i++)
    {
        int t, a; cin >> t >> a;
        if (t == 1) {
            for (int j = 0; j < 33; j++)
            {
                if (((int) 1 << j) & ~a) {
                    andz[j] = i;
                }
            }
        }
        if (t == 2) {
            for (int j = 0; j < 33; j++)
            {
                if (((int) 1 << j) & a) {
                    orz[j] = i;
                }
            }
        }
        if (t == 3) {
            for (int j = 0; j < 33; j++)
            {
                if (((int) 1 << j) & a) {
                    xorz[j]++;
                }
            }
        }
            for (int j = 0; j < 33; j++)
            {
                xorzsw[i][j] = xorz[j];
            }

        // up until i we will define latest orz or andz
        // cout << "andz " << andz[1] << " orz " << orz[1] << '\n';
        int newc = 0;
        for (int j = 0; j < 33; j++)
        {
            int bitz = 0;
            int idx = andz[j];
            if (orz[j] > andz[j]) {
                bitz = 1;
                idx = orz[j];
            }
            if (orz[j] == 0 and andz[j] == 0) {
                bitz = ((int) 1 << j) & c ? 1 : 0;
                idx = 0;
                // cout << bitz << 'c';
            }
            // else cout << bitz << ' ';
            // now till idx
            int xx = xorzsw[i][j] - xorzsw[idx][j];
            // cout << "xx " << xorzsw[i][j] << ' ' << xorzsw[idx][j]<< ' ';
            // if (xx & 1) cout << "(" << 1 <<")";
            if (xx & 1) bitz ^= 1;
            if (bitz) newc |= (int) 1 << j;    
        }
        cout << newc << '\n';
        c = newc;
        
    }
    
}