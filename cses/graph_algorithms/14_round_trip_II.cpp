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

int n, m, ans1 = 0, ans2 = -1, t = 0;
vi ttin, ttout;

void dfs(int u, vi &oj, vi* E){
	ttin[u] = t++;
	for(int v : E[u]){
		if(oj[v]){
			if(!ans1 and ttin[v] < ttin[u] and ttout[v] == -1){
				ans1 = u;
				ans2 = v;
			}
			continue;
		}
		oj[v] = u;
		dfs(v, oj, E);
	}
	ttout[u] = t++;
}

void solve(){
	// need to look for back-edges in dfs-tree
	cin >> n >> m;
	vi E[n + 1];
	ttin.resize(n + 1, inf);
	ttout.resize(n + 1, -1);
	for(int i = 0; i < m; i++){
		int a, b;
		cin >> a >> b;
		E[a].pb(b);
	}
	vi oj(n + 1, 0);
	for(int i = 1; i <= n; i++){
		if(oj[i]) continue;
		oj[i] = -1;
		dfs(i, oj, E);
	}
	if(ans1 == 0){
		cout << "IMPOSSIBLE" << endl;
		return;
	}
	vi ans = {ans1};
	ans1 = oj[ans1];
	while(ans1 != ans2){
		ans.pb(ans1);
		ans1 = oj[ans1];
	}
	ans.pb(ans2);
	ans.pb(ans[0]);
	cout << ans.size() << endl;
	for(int i = ans.size() - 1; i >= 0; i--){
		cout << ans[i] << ' ';
	}
	cout << endl;
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