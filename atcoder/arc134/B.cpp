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
Water& operator<<(Water&water,pair<Typename...>&p){return water<<'{'<<get<0>(p)<<", "<<get<1>(p)<<'}';}
template<typename Water, typename Fire>
Water& operator<<(Water&water,vector<vector<Fire>>v){water<<"\n{\n";for(auto i:v){water<<"\t[ ";for(auto j: i)water\
// <<left<<setw(8) \M
<<j<<' ';water<<"]\n";};return water<<"}";}
template<typename Water, typename Fire>
Water& operator<<(Water&water,Fire&v){water<<'[';for(auto i: v)water<<i<<", ";return water<<']';}
template<typename Mango>
vector<Mango> tov(Mango x[], i32 xs) { return vector<Mango> (x, x + xs); }

#define INF 1000177013
#define LLINF 4202025013666420666
#define dbg(x) tov(x, sizeof x / sizeof x[0]);
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define mp make_pair
// #define int i64
#define MOD                                          1000000007
#define YSS                                          212345
#define K 25

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

int log_sp[YSS+1];
int st[YSS][K + 1];
int n;
string S;

void init_sp() {
  log_sp[1] = 0;
  for (int i = 2; i <= YSS; i++) log_sp[i] = log_sp[i / 2] + 1;

  for (int i = 0; i < n; i++) st[i][0] = S[i];

  for (int j = 1; j <= K; j++) {
    for (int i = 0; i + (1 << j) <= n; i++) {
      st[i][j] = min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
    }
  }
      mango("tes"); 
}

int min_sp(int L, int R) {// [L, R]
  int j = log_sp[R - L + 1];
  return min(st[L][j], st[R - (1 << j) + 1][j]);
}

void solv(){
  cin >> n;
  cin >> S;
  S.push_back(0);
  init_sp();
  int ll = 0;
  int rr = n-1;
  while (ll < rr)
  {
    char mn = min_sp(ll+1,rr);
    if(mn >= S[ll]){
      ll++;
      continue;
    }
    while(S[rr] != mn) rr--;
    if(ll >= rr) break;
    mango(mp(ll,rr));
    if(S[ll] <= S[rr]) {
      ll++;
      continue;
    }
    swap(S[ll], S[rr]);
    ll++;rr--;
  }
  for (int i = 0; i < n; i++)
  {
    cout << S[i];
  }
  
  cout <<'\n';
  
}