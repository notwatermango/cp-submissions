#include <bits/stdc++.h>
using namespace std;

typedef int64_t i64;
typedef int32_t i32;

i32 water = !not!iscntrl(isupper(isgraph(iscntrl(ispunct(isalpha(EOF))))));
#define mango(x)
#define fastmango cin.tie(nullptr)->sync_with_stdio(water)
#ifdef notwatermango
#undef mango
#undef notwatermango
#define mango(x) { water = 999; auto x_ = x; water = not water; cerr<<ends<<"\033[38;5;206m"<<__LINE__<<"\t: "<<#x<<" = "<<x_<<"\e[39m"<<'\n'; }
#endif
#define notwatermango void solv();
i64 powllm(i64 a, i64 b, i64 m) { a %= m; i64 res = 1; while (b > 0) { if (b & 1) res = res * a % m; a = a * a % m; b >>= 1; } return res; }
i64 powll(i64 a, i64 b) { i64 res = 1; while (b > 0) { if (b & 1) res = res * a; a = a * a; b >>= 1; } return res; }
template<typename Water, typename ...Typename>
Water& operator<<(Water& water, const pair<Typename...>& p){ return water<<'{'<<get<0>(p)<<", "<<get<1>(p)<<'}'; }
template<typename Water, typename Fire>
Water& operator<<(Water& water, const Fire& v){ water<<'['; for(auto i: v) water<<i<<", "; return water<<']'; }
template<typename _const>
vector<_const> tov(_const x[], i32 xs) { return vector<_const> (x, x + xs); }

#define INF 1000177013
#define LLINF 4202025013666420666
#define dbg(x) tov(x, sizeof x / sizeof x[0]);
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define MOD 1000000007
#define mp make_pair
#define int i64

notwatermango

signed main(){
  fastmango;
  i32 tc = 1;
  // cin >> tc;
  for(i32 i = 0; i < tc; ++i) {
    // cout << "Case #" << i+1 << ": ";
    solv();
  }
  return water;
}

map<string,int> pm;

string s1, s2;
bool isgood = false;

void lesgo(string st, bool isrev){
  if(pm[st]) return;
  pm[st]++;
  if(st == s2) isgood = true;
  if(isgood) return;
  if(sz(st) > sz(s2)) return;
  mango(mp(st, s2));

  string sq1 = st;
  sq1.push_back('1');
  lesgo(sq1, 0);

  string sq2 = st;
  if(sq2.back() == '0'){
    while (sq2.back() == '0')
    {
      sq2.pop_back();
    }
    lesgo(sq2, 0);
    
  }


  if(isrev) return;
  string sq = st;
  reverse(all(sq));
  lesgo(sq, 1);
}

void solv(){
  int n; cin >> n;
  int k; cin >> k;
  if(n == k){
    cout << "YES\n";
    return;
  }
  if(!(k & 1) && (n & 1)){ // cant convert odd to even
    cout <<"NO\n";
    return;
  }
  s1 = bitset<64>(n).to_string();
  s2 = bitset<64>(k).to_string();
  mango(s1);
  mango(s2);
  // trim lead
  reverse(all(s1));
  reverse(all(s2));
  while (s1.back() == '0')
  {
    s1.pop_back();
  }
  while (s2.back() == '0')
  {
    s2.pop_back();
  }
  reverse(all(s1));
  reverse(all(s2));
  // done trim lead
  if(!(k & 1) && !(n & 1)){ // all even
    while (sz(s1) > sz(s2))
    {
      if(s1.back() == '0') s1.pop_back();
      else break;
    }
    if(s1 == s2) cout << "YES\n";
    else cout << "NO\n";
    return;
  }
  // mango(s1);
  // mango(s2);
  if(sz(s1) > sz(s2)){ // longer
    while(s1.back() == '0' && sz(s1) > sz(s2)) s1.pop_back();
    int ok = 0;
    if(s1 == s2) ok ++;
    reverse(all(s1));
    if(s1 == s2) ok ++;
    if(ok){
      cout << "YES\n";
      return;
    }
    reverse(all(s1));
  }
  // mango(s1);
  
  lesgo(s1, 0);
  if(isgood) cout << "YES\n";
  else cout << "NO\n";
}