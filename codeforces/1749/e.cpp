#include <bits/stdc++.h>

using namespace std;

#define st first
#define nd second
#define pb push_back
#define popb pop_back
#define mp make_pair
#define all(x) x.begin(),x.end()
#define sortall(x) sort(all(x));
#define deb(x) cout << #x << " = " << x << endl
#define debv(x) cout << #x << ": "; for (int i = 0; i < (x).size(); i++) cout << (x)[i] << ' '; cout << endl
#define PI 3.1415926535897932384626
#define fastio ios_base::sync_with_stdio(false); cin.tie(); cout.tie(); srand(time(NULL)); cout << fixed << setprecision(9)
typedef long long				ll;
typedef unsigned long long		ull;
typedef long double				ld;
typedef pair<int, int>			pii;
typedef pair<ll, ll>			pll;
typedef pair<ld, ld>			pld;
typedef vector<int>				vi;
typedef vector<ll>				vl;
typedef vector<pii>				vii;
typedef vector<pll>				vll;
typedef map<int, int>			mii;
typedef set<pii>				sii;
typedef set<int>				si;

const ll mod2 = 1e9 + 7;                /// 1 000 000 007
const ll mod = 119 << 23 | 1;           /// 998244353
const ll mod3 = 467093870598391;        /// big prime
int inf = 1e9 + 7;
ll INF = 1e16 + 9;



ll power (ll x, ll y);
ll inv (ll x);
bool isPrime (ll x);
ll gcd (ll x, ll y);

//==============================================================================


vector<vi> m1 = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
vector<vi> m2 = {{1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

int n, m;

inline bool inside(int x, int y){
	if(x < 0 or x >= n){
		return false;
	}
	if(y < 0 or y >= m + 2){
		return false;
	}
	return true;
}

void solve(){
	// read input
	cin >> n >> m;
	vii E[n * (m + 2)]; // i * (m + 2) + j
	vector<string> grid(n);
	vector<vector<bool>> blocked(n, vector<bool>(m + 2, false));
	for(int i = 0; i < n; i++){
		cin >> grid[i];
		grid[i] = "." + grid[i] + ".";
	}
	// build a graph
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m + 2; j++){
			for(auto move : m1){
				int newx = i + move[0], newy = j + move[1];
				if(inside(newx, newy) and grid[newx][newy] == '#'){
					blocked[i][j] = true;
					//cout << i << ' ' << j << " is blocked" << endl;
					break;
				}
			}
		}
	}
	for(int i = 0; i < n; i++){
		grid[i][0] = '#';
		grid[i][m + 1] = '#';
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m + 2; j++){
			for(auto move : m2){
				int newx = i + move[0], newy = j + move[1];
				if(inside(newx, newy) and !blocked[i][j] and !blocked[newx][newy]){
					E[i * (m + 2) + j].pb({newx * (m + 2) + newy, grid[newx][newy] != '#'}); // creating edges of weight 1 if we need to add cacti moving to next field, 0 otherwise
				}
			}
		}
	}
	// dijkstra from left to right (with remembering parent)
	vi parent(n * (m + 2), -1), d(n * (m + 2), inf);
	set<pii> Q;
	for(int i = 0; i < n; i++){
		d[i * (m + 2)] = 0;
		Q.insert({0, i * (m + 2)});
	}
	while(Q.size()){
		auto tmp = *Q.begin();
		Q.erase(tmp);
		int v = tmp.nd, currd = tmp.st;
		if(currd > d[v]) continue;
		for(auto e : E[v]){
			int newv = e.st, newd = e.nd;
			if(currd + newd < d[newv]){
				d[newv] = newd + currd;
				Q.insert({d[newv], newv});
				parent[newv] = v;
			}
		}
	}
	// check if possible
	int best = m + 1;
	for(int i = 0; i < n; i++){
		if(d[best] > d[(i + 1) * (m + 2) - 1]){
			best = (i + 1) * (m + 2) - 1;
		}
	}
	// NO if impossible
	if(d[best] == inf){
		cout << "NO" << endl;
		return;
	}
	cout << "YES" << endl;
	// else recover the answer
	while(parent[best] != -1){
		int x = best / (m + 2), y = best % (m + 2);
		grid[x][y] = '#';
		best = parent[best];
	}
	for(int i = 0; i < n; i++){
		for(int j = 1; j <= m; j++){
			cout << grid[i][j];
		}
		cout << endl;
	}
}

int main(){
	fastio;
	int T = 1;
	cin >> T;
	for(int i = 1; i <= T; i++){
		solve();
	}
	return 0;
}

ll power (ll x, ll y) {
	if(y < 0)
		return 0;
	ll res = 1ll;
	x %= mod;
	if (x == 0)
		return 0;
	while (y > 0) {
		if (y & 1)
			res = (res * x) % mod;
		y = y >> 1ll;
		x = (x * x) % mod;
	}
	return res;
}

bool isPrime (ll x) {
	if (x == 1)
		return false;
	for (ll i = 2ll; i * i <= x; i++) {
		if (x % i == 0)
			return false;
	}
	return true;
}

ll gcd (ll x, ll y) {
	if (!y)
		return x;
	return gcd (y, x % y);
}

/*
	__builtin_popcount
	__builtin_ctz
	__builtin_clz
*/
