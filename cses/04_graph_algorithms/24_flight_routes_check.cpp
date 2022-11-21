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

const ll mod = 1e9 + 7;                /// 1 000 000 007
const ll mod2 = 119 << 23 | 1;           /// 998244353
const ll mod3 = 467093870598391;        /// big prime
int inf = 1e9 + 7;
ll INF = 1e16 + 9;



ll power (ll x, ll y);
ll inv (ll x);
bool isPrime (ll x);
ll gcd (ll x, ll y);

//==============================================================================

// Kosaraju's algorithm
const int nax = 1e5 + 13;
vi E[nax], R[nax], T, comp;
vector<bool> vis;

void dfs1(int u){
	vis[u] = true;
	for(int v : E[u]){
		if(vis[v]) continue;
		dfs1(v);
	}
	T.pb(u);
}

void dfs2(int u, int t){
	comp[u] = t;
	for(int v : R[u]){
		if(comp[v] != 0) continue;
		dfs2(v, t);
	}
}

void solve(){
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		int a, b;
		cin >> a >> b;
		E[a].pb(b);
		R[b].pb(a);
	}
	vis.resize(n + 1, false);
	for(int i = 1; i <= n; i++)
		if(!vis[i])
			dfs1(i);
	reverse(all(T));
	comp.resize(n + 1, 0);
	int t = 1;
	for(int i = 0; i < n; i++){
		if(comp[T[i]]) continue;
		dfs2(T[i], t++);
	}
	for(int i = 1; i < n; i++){
		if(comp[T[i]] == 2){
			cout << "NO\n" << T[i] << ' ' << T[0] << '\n';
			return;
		}
	}
	cout << "YES\n";
}

int main(){
	fastio;
	int T = 1;
	//cin >> T;
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