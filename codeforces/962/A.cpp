#include <iostream>
using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  int arr[n],x;
  int sum = 0;
  for (int i = 0; i < n; i++)
  {
    cin >> x;
    sum+=x;
    arr[i] = sum;
  }
  sum++;
  for (int i = 0; i < n; i++)
  {
    if(arr[i] >= sum/2){
      cout << i+1 << '\n';
      break;
    }
  }
  
  return 0;
}