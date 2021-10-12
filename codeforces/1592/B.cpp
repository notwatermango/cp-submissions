#include <iostream>
#include <algorithm>
using namespace std;

void solve(){
  int n, x;
  cin >> n >> x;
  int arr[n], arr2[n];
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
    arr2[i] = arr[i];
  }
  if(n/x >= 2){
    cout << "YES\n";
    return;
  }
  sort(arr2, arr2 + n);
  for (int i = n-x; i < x; i++)
  {
    if (arr2[i] != arr[i]){
      cout << "NO\n";
      return;
    }
  }
  cout << "YES\n";
  

}


int main(){
  int a;
  cin >> a;
  while (a--)
  {
    solve();
  }
  

}