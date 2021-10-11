#include <iostream>
using namespace std;

string solve() {
  int n;
  cin >> n;
  string a,b;
  cin >> a >> b;
  for (int i = 0; i < n; i++)
  {
    if(a[i] == '1' && b[i] == '1')
    return "NO";
  }
  return "YES";
  
}


int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin>>t;
  while (t--)
  {
    cout << solve() << '\n';
  }
  
  return 0;
}