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

#define JM 112345
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

void solv(){
  string st;
  cin >> st;
  int n = sz(st);
  stack<int> s1, s2;
  for (int i = 0; i < n; i++)
  {
    if(st[i] == '(') {
      s1.push(1);
      s2.push(i);
    } else {
      if(not s1.empty() and s1.top() == 1) {
        s1.pop();
        s2.pop();
      }
      else {
        s1.push(0);
        s2.push(i);
      }
    }
  }
  int mem = INF;
  int mx, ok;
  mx = ok = 1;
  s2.push(n);
  while(not s2.empty()) {
    int hi = s2.top();
    s2.pop();
    if(mem != INF) {
      int cand = mem - hi;
      if(mx < cand) {
        mx = cand;
        ok = 1;
      } else if(mx == cand) {
        ok++;
      }
    }
    mem = hi;
  }
  int cand = mem+1;
  if(mx < cand) {
    mx = cand;
    ok = 1;
  } else if(mx == cand) {
    ok++;
  }
  if(mx == 1) ok = 1;

  cout << mx-1 << ' ' << ok << '\n';
  
}