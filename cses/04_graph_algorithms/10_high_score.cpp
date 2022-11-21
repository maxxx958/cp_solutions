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
	//bellman-ford

	int n, m;
	cin >> n >> m;
	vector<pair<pii, ll>> e(m);
	for(int i = 0; i < m; i++){
		cin >> e[i].st.st >> e[i].st.nd >> e[i].nd;
		e[i].nd = -e[i].nd;
	}
	// with extra steps
	vi E[2][n + 1];
	for(auto ee : e){
		int a = ee.st.st;
		int b = ee.st.nd;
		E[0][a].pb(b);
		E[1][b].pb(a);
	}
	unordered_set<int> reach[2];
	for(int k = 0; k < 2; k++){
		queue<int> q;
		if(k == 0){
			q.push(1);
			reach[k].insert(1);
		}else{
			q.push(n);
			reach[k].insert(n);
		}
		while(q.size()){
			int u = q.front();
			q.pop();
			for(int v : E[k][u]){
				if(reach[k].find(v) != reach[k].end()) continue;
				reach[k].insert(v);
				q.push(v);
			}
		}
	}
	
	vl d(n + 1, INF);
	d[1] = 0;
	bool ch = false;
	for(int i = 0; i < n; i++){
		ch = false;
		for(auto ee : e){
			int u = ee.st.st;
			int v = ee.st.nd;
			if(reach[0].find(u) == reach[0].end() or reach[1].find(v) == reach[1].end()) continue;
			ll l = ee.nd;
			if(d[u] + l < d[v]){
				ch = true;
				d[v] = d[u] + l;
			}
		}
	}
	if(ch){
		cout << -1 << endl;
		return;
	}
	cout << -d[n] << endl;
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