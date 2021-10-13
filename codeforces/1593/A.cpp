#include <iostream>
using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int x;
  cin >> x;
  while (x--)
  {
    int a,b,c;
    cin>> a>> b>>c;
    int maxx = max(a, max(b,c));
    if(a == maxx && b !=maxx && c!=maxx){
      a+=1;
    } else if(a != maxx && b == maxx && c!=maxx){
      b+=1;
    } else if(a!=maxx && b!=maxx && c==maxx){
      c+=1;
    }
    cout << maxx + 1 - a <<' '<< maxx + 1 - b<<' ' << maxx + 1 - c <<'\n';
  }
  
  return 0;
}