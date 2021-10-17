// PRIMES PRECALC
// sieve linear

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 110000;
int lp[N+1];
vector<int> pr;

void precalc(){
  // not my code
  for (int i=2; i<=N; ++i) 
  {
    if (lp[i] == 0) {
      lp[i] = i;
        pr.push_back (i);
    }
    for (int j=0; j<(int)pr.size() && pr[j]<=lp[i] && i*pr[j]<=N; ++j)
    {
        lp[i * pr[j]] = pr[j];
    }
  }

  // closest bigger primes init
  int aw = 112345;
  for (int i = 110000; i > -1; --i)
  {
    if(lp[i] == i) aw = i;
    lp[i] = aw;
  }
  
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n,m;
  cin >> n >> m;
  int arr[n][m];
  int colgg = 12345678;
  int rowgg = 12345678;
  precalc();

  for (int i = 0; i < n; i++)
  {
    int ct = 0;
    for (int j = 0; j < m; j++)
    {
      cin >> arr[i][j];
      ct+=lp[arr[i][j]] - arr[i][j];
    }
    // cout<<ct<<'\n';
    rowgg = min(rowgg, ct);
  }

  for (int j = 0; j < m; j++)
  {
    int ct   = 0;
    for (int i = 0; i < n; i++)
    {
      ct+=lp[arr[i][j]] - arr[i][j];
    }
    
    colgg = min(colgg, ct);
  }
  

  cout<<min(colgg,rowgg)<<'\n';


  
  return 0;
}