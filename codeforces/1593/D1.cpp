#include <iostream>
using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int tc;
  cin >> tc;
  while (tc--)
  {
    int n;
    cin>>n;
    int arr[n];
    int minn = 10000000;
    int gg = true;
    for (int i = 0; i < n; i++)
    {
      cin >> arr[i];
      if(i!=0 && gg){
        if(arr[i] != arr[i-1]){
          // cout<<arr[i] <<" vs "<<arr[i-1];
          gg = false;
        }
      }
      minn = min(arr[i], minn);
    }
    int maxx = 1;
    for (int i = 0; i < n; i++)
    {
      arr[i]-=minn;
      maxx=max(maxx, arr[i]);
    }
    int res = 1;
    for (int j = maxx; j >= 2; j--)
    {
      bool bad = false;
      for (int i = 0; i < n; i++)
      {
        if(arr[i] == 0 )continue;
        if(arr[i] % j != 0){
          bad =true;
          break;
        }
      }
      if(!bad){
        res = j;
        break;
      }
      
    }
    
    if(gg){
      cout << "-1\n";
    }else{
      cout << res<<'\n';

    }
    
    

    
  }
  
  return 0;
}