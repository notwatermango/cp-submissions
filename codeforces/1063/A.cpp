#include <iostream>
#include <algorithm>
using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int a;
  cin >> a;
  string st;
  cin >> st;
  int k = st.length();
  int ct[26] = {0};
  for (int i = 0; i < k; i++)
  {
    ct[st[i] - 'a']++;
  }
  for (int i = 0; i < 26; i++)
  {
    for (int j = 0; j < ct[i]; j++)
    {
      cout << char(i + 'a');
    }
    
  }
  cout << '\n';
  
  
  return 0;
}