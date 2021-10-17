#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
using namespace std;
#define int int64_t

int facts(int x){
  int res = 1;
  for (int i =1; i <= x; i++)
  {
    res*=i;
  }
  
  return res;
  
}

signed main(){
  ios_base::sync_with_stdio(false); cin.tie(0);
  string st1;
  string st2;
  cin >> st1 >> st2;
  int n = st1.length();
  int p1,m1,p2,m2;
  p1=m1=p2=m2=0;
  int q = 0;
  for (int i = 0; i < n; i++)
  {
    if(st1[i] == '-'){
      m1++;
    }else if(st1[i] == '+'){
      p1++;
    }
    if(st2[i] == '-'){
      m2++;
    }else if(st2[i] == '+'){
      p2++;
    } else if(st2[i] == '?'){
      q++;
    }
  }
  if(m2 == m1 && p2 == p1){
    cout<<"1.000000000000\n";
  } else if(m2>m1 || p2 > p1){
    cout <<"0.000000000000\n";
  } else{
    int need = p1-p2; 
    // q C need
    // cout << need << ' ' << q;
    int res = facts(q)/facts(need)/facts(q-need);
    cout<<fixed<<setprecision(9)<<double(res)/pow(2,q);

  }


  
  
  return 0;
}