#include <iostream>
#include <map>
using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  map<int,int> ctr;
  cin >> n;
  int maxx = 1;
  int arr[n];
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
    ctr[arr[i]]++;
    maxx = max(maxx, ctr[arr[i]]);
  }
  cout << n-maxx << '\n';



  
  


  
  return 0;
}