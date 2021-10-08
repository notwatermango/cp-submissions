#include <iostream>
using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int tc;
  cin>>tc;
  while (tc--)
  {
    int n;
    char cjar;
    string st;
    cin>>n>>cjar>>st;
    bool done = false;
    bool good = true;
    for (int i = 0; i < n; i++)
    {
      if(st[i] != cjar) {
        good = false;
        break;
      }
    }
    
    if(good){
      cout<<"0\n";
      continue;
    }


    for (int i = n-1; i >= n/2; i--)
    {
      if(st[i] == cjar){
        cout<<"1\n"<<i+1<<'\n';
        done = true;
        break;
      }
    }
    if(done) continue;

    cout<<"2\n"<<n<<' '<<n-1<<'\n';
    
    
    
  }
  
  return 0;
}