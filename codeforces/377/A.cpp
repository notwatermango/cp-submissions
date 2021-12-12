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
int drx[] = {1, 0 , 0,-1};
int dry[] = {0, 1,-1, 0};
int n,m;
vector<vector<char>> arr;
vector<vector<int>> vis;
vector<vector<pair<int,int>>> vv;
int mx = 0;

void bfs(int sx, int sy){
	queue<pair<int,int>> q;
	q.push(mp(sx, sy));
	vis[sx][sy] = 1;
	while(not q.empty()){
		int nx = q.front().first;
		int ny = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int px = nx +drx[i];
			int py = ny+dry[i];
			if(px >= n || px < 0 || py < 0 || py >= m) continue;
			if(vis[px][py] || arr[px][py] == '#') continue;
			vis[px][py] = vis[nx][ny] + 1;
			mx = max(vis[px][py], mx);
			q.push(mp(px,py));
		}	
	}
}

void solv(){
	cin >> n; cin >> m;
	int k; cin >> k;
	arr.assign(n, vector<char>(m, 0));
	vis.assign(n, vector<int>(m, 0));
	mango(vis);
	int ii,jj; jj = INF;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> arr[i][j];
			if(arr[i][j] == '.' && jj==INF){
				ii = i;
				jj = j;
			}
		}
	}
	if(not k){
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				cout << arr[i][j];
			}
			cout << '\n';
		}
		return;
	}
	bfs(ii,jj);
	mango(vis);
	vv.assign(mx+1, vector<pair<int,int>>());
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			vv[vis[i][j]].push_back(mp(i,j));
		}
	}
	for (int i = sz(vv) - 1; i >= 0; i--)
	{
		for (int j = 0; j < sz(vv[i]); j++)
		{
			if(!k) break;
			k--;
			int ix = vv[i][j].first;
			int jx = vv[i][j].second;
			arr[ix][jx] = 'X';
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << arr[i][j];	
		}
		cout << '\n';
		
	}
	
	
	
}