// #include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <iomanip>
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
  int n;
  cin >> n;
  if(n == 1) {
    cin >> n;
    cout << "1\n";
    return;
  }
  int arr[n][n];
  int sum = 0;
  int ii, jj;
  int mx = 0;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cin >> arr[i][j];
      if(arr[i][j] == 0){
        ii = i; jj = j;
      }
    }
    mx = max(sum, mx);
  }
  int reali = ii;
  if(ii == 0) ii ++;
  else ii --;
  int summ = 0;
  for (int i = 0; i < n; i++)
  {
    sum += arr[ii][i];
    summ += arr[reali][i];
  }
  mango(sum);
  arr[reali][jj] = sum - summ;
  bool sad = false;
  for (int i = 0; i < n; i++)
  {
    summ = 0;
    for (int j = 0; j < n; j++)
    {
      summ+=arr[i][j];
    }
    if(summ != sum) {
      sad = true;
      break;
    }
  }
  mango(sad);
  for (int i = 0; i < n; i++)
  {
    summ = 0;
    for (int j = 0; j < n; j++)
    {
      summ+=arr[j][i];
    }
    if(summ != sum){
      sad = true;
      break;
    }
    
  }
  mango(sad);
  summ = 0;
  for (int i = 0; i < n; i++)
  {
    summ+=arr[i][i];
  }
  if(summ != sum){
    sad = true;
  }
  mango(sad);
  summ = 0;
  for (int i = 0; i < n; i++)
  {
    summ+=arr[i][n-1-i];
  }
  if(summ != sum){
    sad = true;
  }
  mango(sad);
  if(sad || arr[reali][jj] < 1) cout << -1 <<'\n';
  else cout << arr[reali][jj] << '\n';
  
  
  
  
  
  
  

  
}