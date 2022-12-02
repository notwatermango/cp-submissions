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
#define YSS                                          3123

notwatermango;

signed main() {
  // fastmango;
  i32 tc = 1;
  // cin >> tc;
  for (i32 i = 0; i < tc; ++i) {
    // cout << "Case #" << i+1 << ": ";
    solv();
  }
  return water;
}
int mod;
template<class T,class T2> void Add(T& x,T2 y,int p=MOD){
	x+=y;
	if(x>=p)
		x-=p;
}
// Binary Indexed Tree (1.1 基本実装)
// 1-based indexing
class BIT
{
public:

	BIT() = default;

	// 長さ size の数列で初期化
	explicit BIT(size_t size)
		: m_bit(size + 1) {}

	// 数列で初期化
	explicit BIT(const std::vector<long long>& v)
		: BIT(v.size())
	{
		for (int i = 0; i < v.size(); ++i)
		{
			add((i + 1), v[i]);
		}
	}

	// 閉区間 [1, r] の合計を返す (1-based indexing)
	long long sum(int r) const
	{
		long long ret = 0;

		for (; 0 < r; r -= (r & -r))
		{
      Add(ret, m_bit[r], mod);
		}

		return ret;
	}

	// 閉区間 [l, r] の合計を返す (1-based indexing)
	long long sum(int l, int r) const
	{
		return (sum(r) - sum(l - 1));
	}

	// 数列の i 番目の要素を加算 (1-based indexing)
	void add(int i, long long value)
	{
		for (; i < m_bit.size(); i += (i & -i))
		{
      Add(m_bit[i], value, mod);
		}
	}

private:

	std::vector<long long> m_bit;
};

void solv() {
  int n; cin >> n >> mod;
  // vector<int> tens({1, 10, 100, 1000});
  // vector<vector<int>> dp(YSS, vector<int> (YSS));
  // let dp i j : |S| == i and |T| == j
  // transition is adding k-length new segment
  // dp[i + k][j + tens[k]] += dp[i][j] * 25
  // even
  // dp[i + 1][j + 1] = dp[i][j] * 25

  // let x = tens[k];
  // g(x) = 1 - 9, 10 - 99, ...

  // dp[i + g(x)begin][j + x] += dp[i][j]*25
  // dp[i + g(x)end - 1][j + x] += dp[i][j]*25

  
  // dp[i + g(x)][j + x] += dp[i][j] * 25


  // for i < j dp[i][j] = 0
  vector<BIT> dp(YSS, BIT(YSS + 1)); // we swap i and j

  // also we have the super init
  // initial segment is already tens
  // dp[2][1..9] = 26
  dp[2].add(1,26);
	dp[2].add(10,mod-26);
	dp[3].add(10,26);
	dp[3].add(100,mod-26);
	dp[4].add(100,26);
	dp[4].add(1000,mod-26);
	dp[5].add(1000,26);
  for (int i = 1; i < n + 1; i++)
  {
    for (int j = 1; j < n + 1; j++)
    {
      int dpj = dp[i].sum(j);
      if (dpj == 0) continue;
      dp[i+2].add(j+1,25*dpj%mod);
      dp[i+2].add(j+10,mod-25*dpj%mod);
      dp[i+3].add(j+10,25*dpj%mod);
      dp[i+3].add(j+100,mod-25*dpj%mod);
      dp[i+4].add(j+100,25*dpj%mod);
      dp[i+4].add(j+1000,mod-25*dpj%mod);
      dp[i+5].add(j + 1000, 25 * dpj % mod);
    }
  }
  

  int ans = 0;
  for (int i = 1; i < n; i++)
  {
    // for (int j = n; j <= n; j++)
    // {
    //   // cout << dp[i].sum(j,j) << ' ';
    //   if (j == n)
    //   {
        Add(ans, dp[i].sum(n), mod);
      // }
      
    // } 
    // cout << '\n';
    
  }
  
  cout << ans << '\n';
  

  
}
