#include <iostream>
#include <algorithm>
using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin>>n;
  int arr[n];
  int arr2[n];
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
    arr2[i] = arr[i];
  }
  sort(arr, arr+n);
  int c= 0;
  for (int i = 0; i < n; i++)
  {
    if(arr2[i] != arr[i]){
      c++;
    }
  }
  if(c < 3){
    cout << "YES\n";
  }else{
    cout<<"NO\n";
  }
  
  
  return 0;
}