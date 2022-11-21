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

vi T;
int lc = 1;

void update(int k, ll v){
	k += lc;
	T[k] = v;
	k >>= 1;
	while(k){
		T[k] = min(T[2 * k], T[2 * k + 1]);
		k >>= 1;
	}
}

int query(int l, int r, int L, int R, int akt){
	if(l == L and r == R) return T[akt];
	int mid = (l + r) / 2;
	if(R <= mid){
		return query(l, mid, L, R, akt * 2);
	}
	if(L > mid){
		return query(mid + 1, r, L, R, akt * 2 + 1);
	}
	return min(query(l, mid, L, mid, akt * 2), query(mid + 1, r, mid + 1, R, akt * 2 + 1));
}

void solve(){
	int n, m;
	cin >> n >> m;
	while(lc < n){
		lc <<= 1;
	}
	T.resize(2 * lc);
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		update(i, x);
	}
	for(int i = 0; i < m; i++){
		int c, x, y;
		cin >> c >> x >> y;
		if(c == 1){
			update(x - 1, y);
		}else{
			cout << query(0, lc - 1, x - 1, y - 1, 1) << '\n';
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