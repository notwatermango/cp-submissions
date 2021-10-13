#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int x;
  cin>>x;
  while (x--)
  {
    string st;
    cin >> st;
    int res = 0;
    while (st.back() != '5' && st.back() != '0')
    {
      st.pop_back();
      res++;
    }
    int n = st.length();
    // cout<<"n "<<n<<'\n';
    int minn = 1234567;
    vector<int> z;
    bool five = false;
    for (int i = n-1; i > -1; i--)
    {
      if(st[i] == '0'){
        z.push_back(i);
      } else 
      if(st[i] == '5'){
        five = true;
        if(z.size()){
          minn = min(minn, n-1-i-1 );
          // cout<<"HIatas" <<i;
        }
        if(z.size() == 2){
          minn = min(minn, n-1-i-2);
          // cout<<"HI";
        }
      } else {
        if(five && (st[i] == '2' || st[i] == '7')){
          minn = min(minn, n-1-i-1);
        }
        if(z.size() == 2 && st[i] != '0'){
          minn = min(minn, n-1-i-2);
          // cout<<"HIbwh" <<i;
        }
      }
      if(z.size() >= 2 && st[i] != '0'){
          minn = min(minn,int( n-1-i-z.size()));
          // cout<<"HI" <<i;
        }
    }
    

    cout << res+minn << '\n';
    
    

  }
  
  return 0;
}