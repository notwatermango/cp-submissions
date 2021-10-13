#include <iostream>
#include <algorithm>
using namespace std;

void solve(){
  int n,k;
  cin >> n >> k;
  int arr[k];
  for (int i = 0; i < k; i++)
  {
    cin >> arr[i];
    arr[i] = n-arr[i];
  } // mouse moves first
  sort(arr, arr+k);
  int ctr=0;
  for (int i = 0; i < k; i++)
  {
    n-=arr[i];
    if(n<1){
      // cout<<n<<'\n';
      break;
    }
    ctr++;
  }
  cout<<ctr <<'\n';
  
  
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int tc;
  cin>>tc;
  while (tc--)
  {
    solve();
  }
  
  return 0;
}