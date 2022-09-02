#include <vector>
#include <iostream>
#include <map>
using namespace std;

// 5c2 5! / 2! / (5-2)!

unsigned long long custom_fn(int a, int b){
  unsigned long long res = 1;
  for (int i = b-2; i <= b; i++)
  {
    res*=i;
  }

  for (int i = 1; i <= a; i++)
  {
    res/=i;
  }
  
  
  

  return res;
}

void solve(){
  int n;
  map<int, long long> ct1;
  map<int, long long> ct2;
  vector<pair<int, int>> v;
  cin>>n;
  int a = n;
  while (n--)
  {
    int a,b;
    cin >> a >> b;
    v.push_back({a,b});
    ct1[a] ++;
    ct2[b] ++;
  }
  unsigned long long ok = custom_fn(3, a);
  for(auto e:v) {
    ok -= (ct1[e.first]-1) * (ct2[e.second]-1);
  }
  // cout<<ok<<' '<<bad<<'\n';
  cout<<ok<<'\n';


  
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