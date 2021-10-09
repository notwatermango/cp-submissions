#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>
using namespace std;

int battle_win(char a, char b){
  if( a == 'G'){
    if( b == 'G'){
      return 0;
    }
    if( b == 'C'){
      return 1;
    }
    return -1;
  }
  if( a == 'C'){
    if( b == 'C'){
      return 0;
    }
    if( b == 'P'){
      return 1;
    }
    return -1;
  }
  if( b == 'P'){
    return 0;
  }
  if( b == 'G'){
    return 1;
  }
  return -1;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n,m;
  cin>>n>>m;
  priority_queue<pair<pair<int,int>, string>> pq;
  priority_queue<pair<pair<int,int>, string>> pq2;
  
  for (int i = 0; i < 2*n; i++)
  {
    string st;
    cin>>st;
    pq.push({{0,-1*i}, st});
  }

  for (int j = 0; j < m; j++)
  {
    while(!pq.empty()){
      auto a = pq.top();
      pq.pop();
      auto b = pq.top();
      pq.pop();
      int res = battle_win(a.second[j] , b.second[j]);
      // cout<<a.second[j]<<" vs "<<b.second[j]<<'\n';
      if(res == 1){
        a.first.first++;
      } else if(res == -1){
        b.first.first++;
      }
      pq2.push(a);
      pq2.push(b);
    }
    while (!pq2.empty())
    {
      pq.push(pq2.top());
      pq2.pop();
      pq.push(pq2.top());
      pq2.pop();

    }
  }  
  while (!pq.empty())
  {
    cout<<1+pq.top().first.second*-1<<'\n';
    pq.pop();
  }
  

  
  return 0;
}