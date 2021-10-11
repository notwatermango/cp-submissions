/*
! TLE
*/


#include <iostream>
#include <map>
using namespace std;


void solve() {
  int n;
  cin >> n;
  int arr[n];
  map<int, int> M;
  long long sum = 0;
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
    sum += arr[i];
  }
  double avg = sum/(double)n;
  int avgint2 = (int) (avg*2);
  double avgw2 = avg*2;

  // avgw2 must be int;
  double aremainder = avgw2 - int(avgw2);
  // cout<<aremainder;
  if(aremainder > 1e-6) {
    cout << "0\n";
    return;
  }

  long long res = 0;
  for (int i = 0; i < n; i++)
  {
    res += M[avgint2 - arr[i]];
    M[arr[i]]++;
  }
  
  cout << res << '\n';

  
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int tc;
  cin >> tc;
  while (tc--)
  {
    solve();
  }
  
  return 0;
}