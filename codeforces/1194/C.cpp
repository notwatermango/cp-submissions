// #include <bits/stdc++.h>
#include <iostream>
#include <map>
#include <algorithm>
#include <iomanip>
using namespace std;

// #define int int64_t
#define MOD 1000000007
#define LLINF 4202000013666420666
#define INF 1000177013

void solve();

signed main(){
  ios_base::sync_with_stdio(false); cin.tie(0);
  int tc = 1;
  cin >> tc;
  for(int i = 0; i < tc; ++i) {
    // cout << "Case #" << i+1 << ": ";
    solve();
  }
  
  return 0;
}

void solve(){
  string s,t,p;
  cin >> s>> t >> p;
  if(t.length() < s.length() || t.length() > s.length() + p.length()){
    cout << "NO\n";
    return;
  }
  int ct[26] = {0};
  int cs[26] = {0};
  int cp[26] = {0};
  int tn = t.length();
  int sn = s.length();
  int pn = p.length();
  for (int i = 0; i < tn; i++)
  {
    ct[t[i] - 'a']++;
  }
  for (int i = 0; i < sn; i++)
  {
    cs[s[i] - 'a']++;
  }
  for (int i = 0; i < pn; i++)
  {
    cp[p[i] - 'a']++;
  }
  for (int i = 0; i < 26; i++)
  {
    // cout << cs[i] << ' ' << ct[i] << ' ' << cp[i] << '\n';
    if(cs[i] + cp[i] < ct[i]){
      cout << "NO\n";
      return;
    }
  }
  int tt,ss;
  tt = ss = 0;
  while (ss < sn && tt <tn)
  {
    if(s[ss] != t[tt]){
      // s take from p;
      if(cp[t[tt]-'a']){
        cp[t[tt]-'a']--;
        tt++;
        continue;
      } else{
        cout << "NO\n";
        return;
      }
    }
    ss++;
    tt++;
  }
  while (tt < tn)
  {
    tt++;
    if(cp[t[tt]-'a']){
      cp[t[tt]-'a']--;
    }else{
      cout <<"NO\n";
      return;
    }
  }
  
  if(ss != sn || tt != tn){
    cout << "NO\n";
    return;
  }
  
  cout << "YES\n";
  return;
  
  
  
  

}