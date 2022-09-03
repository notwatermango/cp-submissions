#include <bits/stdc++.h>
using namespace std;

typedef int64_t i64;
typedef int32_t i32;

i32 water = !not!iscntrl(isupper(isgraph(iscntrl(ispunct(isalpha(EOF))))));
#define mango(x)
#define fastmango cin.tie(nullptr)->sync_with_stdio(water)
#define precisemango(x) cout << fixed << setprecision(x)
#ifdef notwatermango
#undef mango
#undef notwatermango
#define mango(x) { water = 999; auto x_ = x; water = not water; cerr<<ends<<"\033[38;5;206m"<<__LINE__<<"\t: "<<#x<<" = "<<x_<<"\e[39m"<<'\n'; }
#endif
#define notwatermango void solv()
i64 powllm(i64 a, i64 b, i64 m) { a %= m; i64 res = 1; while (b > 0) { if (b & 1) res = res * a % m; a = a * a % m; b >>= 1; } return res; }
i64 powll(i64 a, i64 b) { i64 res = 1; while (b > 0) { if (b & 1) res = res * a; a = a * a; b >>= 1; } return res; }
template<typename Water, typename ...Typename>
Water& operator<<(Water&water,pair<Typename...>&p){return water<<'{'<<get<0>(p)<<", "<<get<1>(p)<<'}';}
template<typename Water, typename Fire>
Water& operator<<(Water&water,vector<vector<Fire>>v){water<<"\n{\n";for(auto i:v){water<<"\t[ ";for(auto j: i)water\
// <<left<<setw(8) \笑
<<j<<' ';water<<"]\n";};return water<<"}";}
template<typename Water>
Water& operator<<(Water&water,string&v){for(auto i: v)water<<i;return water;}
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
#define int i64
#define MOD                                          1000000007
#define YSS                                          112345

notwatermango;

signed main() {
  fastmango;
  i32 tc = 1;
  // cin >> tc;
  for (i32 i = 0; i < tc; ++i) {
    // cout << "Case #" << i+1 << ": ";
    solv();
  }
  return water;
}

/* fenw tree */
struct FenwickTree {
  vector<int> bit; // binary indexed
  int n;

  FenwickTree(int n) {
    this->n = n;
    bit.assign(n, 0);
  }

  FenwickTree(vector<int> a) : FenwickTree(a.size()) {
    for (size_t i = 0; i < a.size(); i++)
      add(i, a[i]);
  }

  int sum(int r) {
    int ret = 0;
    for (; r >= 0; r = (r & (r + 1)) - 1)
      ret += bit[r];
    return ret;
  }

  int sum(int l, int r) { return sum(r) - sum(l - 1); }

  void add(int idx, int delta) {
    for (; idx < n; idx = idx | (idx + 1))
      bit[idx] += delta;
  }
};
/* ~fenw tree */

void solv() {
  int n, m, q; cin >> n >> m >> q;
  FenwickTree ft(m + 1); // rows
  vector<pair<int,int>> latest(n + 1);
  vector<vector<pair<pair<int,int>,pair<int,int>>>> queues(q);
  vector<int> cmds;
  vector<int> ans;
  vector<int> ros;
  vector<pair<int,int>> roco;
  vector<pair<pair<int,int>, int>> frtox;
  for (int i = 0; i < q; ++i) {
    int cmd; cin >> cmd; cmds.push_back(cmd);
    if (cmd == 1) { // add col
      int fr, to; cin >> fr >> to;
      int x; cin >> x;
      frtox.push_back(mp(mp(fr, to), x));
      // ft.add(fr - 1, x);
      // ft.add(to, -x);
      // get at to
    } else if (cmd == 2) { // change row
      int ro, x; cin >> ro >> x;
      ros.push_back(ro);
      latest[ro] = mp(x, i);
    } else { 
      int row, col; cin >> row >> col;
      int j = ans.size();
      queues[latest[row].second].push_back(mp(mp(row, col),mp(j, latest[row].first))); // j, latest
      ans.push_back(0);
      roco.push_back(mp(row, col));
    }
  }
  int z = -1;
  int i = -1;
  int j = -1;
  for (auto cmd: cmds) {
    i++;
    if (cmd == 1) {
      z++;
      auto [frto, x] = frtox[z];
      auto [fr, to] = frto;
      ft.add(fr -1, x);
      ft.add(to, -x);
    } else if (cmd == 2) {
      for (auto q: queues[i]) {
        ans[q.second.first] += q.second.second ;
        mango(q.second);
        // + change - ft
        ans[q.second.first] -= ft.sum(roco[q.second.first].second-1);
      }
    } else {
      j++;
      ans[j] += ft.sum(roco[j].second-1);
    }
  }
  for (auto an: ans) {
    cout << an << '\n';
  }
}