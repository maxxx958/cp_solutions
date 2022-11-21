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

void dijkstra(int st, vl &dist, vector<bool> &processed, vector<pair<int, ll>> E[]){
	set<pair<ll, int>> q;
	q.insert({0, st});
	dist[st] = 0;
	while(q.size()){
		int u = (*q.begin()).nd;
		q.erase(q.begin());
		if(processed[u]) continue;
		processed[u] = true;
		for(auto e : E[u]){
			int v = e.st;
			ll l = e.nd;
			if(dist[v] <= dist[u] + l) continue;
			dist[v] = dist[u] + l;
			q.insert({dist[v], v});
		}
	}
}

void solve(){
	int n, m;
	cin >> n >> m;
	vector<pair<int, ll>> E[n + 1];
	vector<pair<int, ll>> R[n + 1];
	for(int i = 0; i < m; i++){
		int a, b, c;
		cin >> a >> b >> c;
		E[a].pb({b, c});
		R[b].pb({a, c});
	}
	vl dist[2] = {vl(n + 1, INF), vl(n + 1, INF)};
	vector<bool> processed(n + 1, false);
	dijkstra(1, dist[0], processed, E);
	processed = vector<bool>(n + 1, false);
	dijkstra(n, dist[1], processed, R);
	// debv(dist[0]);
	// debv(dist[1]);
	ll ans = INF;
	for(int u = 1; u <= n; u++){
		for(auto e : E[u]){
			int v = e.st;
			ll l = e.nd;
			ans = min(ans, dist[0][u] + dist[1][v] + l / 2ll);
		}
	}
	cout << ans << endl;
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