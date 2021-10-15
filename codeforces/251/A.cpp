#include <cmath>
#include <iostream>
using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n,d;
  cin >> n >> d;
  int arr[n];
  int64_t c = 0;
  for (int i = 0; i < n; i++)
  {
    cin>>arr[i];
  }
  int64_t left = 0;
  int64_t right = 2;
  while (left < n-2)
  {
    while (right < n && arr[right] - arr[left] <= d)
    {
      right++;
    }
    // cout << right-left-2 << ' '<< right-left-1<<'\n';
    c += ((right-left-2) * (right-left-1))/2;
    left++;
    
  }
  
  
  
  cout << c<<'\n';
  
  return 0;
}