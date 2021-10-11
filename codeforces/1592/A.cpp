#include <iostream>
using namespace std;

void solve(){
  int n,h;
  cin >> n >> h;
  int a;
  int maxx1, maxx2;
  maxx1 = maxx2 = 0;
  for (int i = 0; i < n; i++)
  {
    cin >> a;
    if(a > maxx1){
      maxx2 = maxx1;
      maxx1 = a;
    } else if(a > maxx2){
      maxx2 = a;
    }
  }
  int wp = maxx1+maxx2;
  // cout << wp<<'\n';

  int res = h/wp;
  res*=2;
  h -= res*wp/2;
  if (h > 0){
    res++;
    h -= maxx1;
    if(h > 0){
      res++;
    }
  }
  cout << res << '\n';

}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int tc;
  cin >> tc;
  while (tc--)
  {
    solve();
  }
  
  return 0;
}