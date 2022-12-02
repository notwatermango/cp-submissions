#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main () {
    int n, m; cin >> n >> m;
    vector<ll> x(n);
    for (int i = 0; i < n; i++)
    {
        cin >> x[i];
    }
    // vector<pair<ll, ll >> streak(m);
    map<ll, ll> streak;
    for (int i = 0; i < m; i++)
    {
        int c, y; cin >> c >> y;
        streak[c] = y; 
    }
    vector<vector<ll>> dp(n+1, vector<ll>(n+1));
    dp[0][0] = 1;
    // take i coin, j streak
    #define chmax(a, b) a= max(a, b);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            // take
            if (dp[i][j])
            chmax(dp[i+1][j+1], dp[i][j] + x[i] + streak[j+1]);
            chmax(dp[i+1][0], dp[i][j]);
        }
    }
    // for (auto &&e : dp)
    // {
    //     for (auto &&i : e)
    //     {
    //         cout << i << ' ';
    //     }
    //     cout << '\n';
    // }
    

    ll ans = 0;
    for (int i = 0; i <= n; i++)
    {
        chmax(ans, dp[n][i]);
    }
    cout << ans - 1 << '\n';
    
    

    
    
}