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
const int nax = 2e5 + 13;
int t = 0;
vi E[nax], tin, tout;
vector<vi> jump;

void dfs(int u, int oj){
	jump[u][0] = oj;
	tin[u] = t++;
	for(int v : E[u]){
		if(v == oj) continue;
		dfs(v, u);
	}
	tout[u] = t++;
}

bool is_ancestor(int a, int b){
	return (tin[a] <= tin[b] and tout[b] <= tout[a]);
}

void solve(){
	int n, m;
    cin >> n >> m;
	jump.resize(n, vi(24, 0));
	tin.resize(n, 0);
	tout.resize(n, 0);
    for(int i = 1; i < n; i++){
		int x;
		cin >> x;
		E[x - 1].pb(i);
		E[i].pb(x - 1);
    }
	dfs(0, 0);
	for(int l = 1; l < 24; l++){
		for(int i = 0; i < n; i++){
			jump[i][l] = jump[jump[i][l - 1]][l - 1];
		}
	}
	for(int i = 0; i < m; i++){
		int a, b;
		cin >> a >> b;
		a--, b--;
		if(is_ancestor(a, b)){
			cout << a + 1 << endl;
		}else if(is_ancestor(b, a)){
			cout << b + 1 << endl;
		}else{
			for(int j = 23; j >= 0; j--){
				if(!is_ancestor(jump[a][j], b)){
					a = jump[a][j];
				}
			}
			cout << jump[a][0] + 1 << endl;
		}
	}
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