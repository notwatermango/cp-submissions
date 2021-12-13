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

void solv(){
  int n; cin >> n;
  int arr[n], arr2[n];
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i] >> arr2[i];
  }
  int a,b;
  a = b = 0;
  int ct = 1;
  for (int i = 0; i < n; i++)
  {
    if(b < a  && arr2[i] >= a) {
      ct += min(arr[i], arr2[i]) - max(a, b) + 1;
      mango("hi");
      mango(min(arr[i], arr2[i]));
      mango(max(a,b));
    }
    else if(a < b && arr[i] >= b) {
      ct += min(arr[i], arr2[i]) - max(a, b) + 1;
    }
    else if(arr2[i] == b && arr[i] == a){

    } else if(arr2[i] == arr[i]) {
      ct += arr[i] - max(a, b);
    } else if(arr2[i] > b && arr[i] > a){
      ct += max(min(arr[i],arr2[i]) - max(a,b), 0ll);
    }
    a = arr[i]; b = arr2[i];
  }
  
  cout << ct << '\n';
  
}