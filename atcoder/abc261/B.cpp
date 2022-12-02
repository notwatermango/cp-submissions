#include <bits/stdc++.h>
using namespace std;

signed main () {
    int n;
    cin >> n;
    vector<vector<char>> arr(n, vector<char>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
        
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[i][j] == 'W' and arr[j][i] == 'L') continue;
            if (arr[i][j] == 'L' and arr[j][i] == 'W') continue;
            if (arr[i][j] == 'D' and arr[j][i] == 'D') continue;
            if (arr[i][j] == '-' and i == j) continue;
            cout << "incorrect\n"; return 0;
        }
        
    }
    cout << "correct\n"; 
    
    
    return 0;
}