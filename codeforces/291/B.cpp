#include <iostream>
#include <sstream>
#include <algorithm>
using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  string buff;
  char cj;
  bool inquotes = false;
  string al;
  getline(cin,al);
  for(int i = 0; i < al.length(); ++i)
  {
    cj = al[i];
    if(cj == '"'){
      inquotes = !inquotes;

      if(!inquotes){
        cout << '<' << buff << ">\n";
      }
      buff.clear();
      continue;
    }
    if(!inquotes && cj == ' ' && !buff.empty()){
      cout << '<' << buff << ">\n";
      buff.clear();
      continue;
    } 
    if(!inquotes && cj == ' '){
      continue;
    }
    buff.push_back(cj);

  }
  if(!buff.empty()){
    cout << '<' << buff << ">\n";
  }
  return 0;
}