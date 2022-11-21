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

void solve(){
	// we can implement MST with prim's algorightm (it's similar to dijkstra but we store edge lengths instead of distances to verticies)
	int n, m;
	cin >> n >> m;
	vii E[n + 1];
	for(int i = 0; i < m; i++){
		int a, b, c;
		cin >> a >> b >> c;
		E[a].pb({b, c});
		E[b].pb({a, c});
	}
	ll ans = 0;
	set<pii> q;
	q.insert({0, 1});
	vector<bool> processed(n + 1, false);
	while(q.size()){
		int u = (*q.begin()).nd;
		int e = (*q.begin()).st;
		q.erase(q.begin());
		if(processed[u]) continue;
		processed[u] = true;
		ans += e;
		for(pii w : E[u]){
			int l = w.nd;
			int v = w.st;
			if(!processed[v]){
				q.insert({l, v});
			}
		}
	}
	for(int i = 1; i <= n; i++){
		if(processed[i] == false){
			cout << "IMPOSSIBLE";
			return;
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