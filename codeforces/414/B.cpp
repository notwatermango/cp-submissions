// #include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
using namespace std;

typedef int64_t i64;
typedef int32_t i32;

i32 water = not true;
#define mango(x)
#define fastmango ios_base::sync_with_stdio(false); cin.tie(nullptr)
#ifdef notwatermango
#undef notwatermango
#undef mango
#define mango(x) {++water; auto x_=x; --water; cerr<<string(water, '\t')<<"\033[38;5;206m"<<__func__<<":"<<__LINE__<<"\t"<<#x<<" = "<<x_<<"\e[39m"<<'\n';}
#endif
#define notwatermango void solv();
template<typename Ostream, typename Cont>
typename enable_if<is_same<Ostream,ostream>::value, Ostream&>::type operator<<(Ostream& water,  const Cont& v){ water<<"["; for(auto& x:v) water<<x<<", "; return water<<"]"; }
template<typename Ostream, typename ...Ts>
Ostream& operator<<(Ostream& water,  const pair<Ts...>& p){ return water<<"{"<<p.first<<", "<<p.second<<"}"; }

#define MOD 1000000007
#define LLINF 4202025013666420666
#define INF 1000177013
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define mp make_pair
#define int i64

notwatermango

signed main(){
  fastmango;
  i32 tc = 1;
  // cin >> tc;
  for(i32 i = 0; i < tc; ++i) {
    // cout << "Case #" << i+1 << ": ";
    solv();
  }
  return 0;
}

void solv(){
  int n, k;
  cin >> n >> k;
  k--;
  vector<int> dp(n+1);
  for (int i = 1; i <= n; i++)
  {
    dp[i] = n/i;
  }
  for (int q = 0; q < k; q++)
  {
    for (int i = 1; i <= n; i++)
    {
      for (int j = i; j <= n; j+=i)
      {
        if(i == j) continue;
        dp[i] += dp[j];
        dp[i] %= MOD;
      }
    }
  }
  // int sum = 0;
  mango(dp);
  cout << dp[1] << '\n';
  
  
  
}

/*
3 2
1 1, 1 2, 1 3
2 2, 3 3

6 4
1 1 1 1, 1 1 1 2, 1 1 2 2, 1 2 2 2 * 5  = 20
2 2 2 2, 2 2 2 4, 2 2 4 4, 2 4 4 4      = 4
         2 2 2 6, 2 2 6 6, 2 6 6 6      = 3
2 2 4 6, 2 4 4 6, 2 4 6 6               = 3
4 4 4 4, 4 4 4 6, 4 4 6 6, 4 6 6 6      = 4
                                        * 34
3 3 3 3, 3 3 3 6, 3 3 6 6, 3 6 6 6      = 3


*/