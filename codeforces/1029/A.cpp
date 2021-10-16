#include <iostream>
#include <algorithm>
using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n,k;
  cin >> n >> k;
  string st;
  cin >> st;
  int ct;
  for (int i = 1; i < n; i++)
  {
    int j = 0;
    ct = 0;
    int x = i;
    while(x<n && j<n&&st[x] == st[j]){
      ct++;
      // cout<<st[x]<<st[j];
      x++;
      j++;
    //  / cout << x << j ;
    }
    if(x == n || j == n){
      break;
    } else{
      ct = 0;
    }
  }
  // cout << ct<<'\n';
  cout << st;
  for (int i = 1; i < k; i++)
  {
    for (int j = ct; j < n; j++)
    {
      cout<<st[j];
    }
    
  }
  cout<<'\n';
  
  
  return 0;
}