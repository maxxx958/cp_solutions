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
	int n, x;
	cin >> n;
	vi pos(n + 1, -1);
	for(int i = 0; i < n; i++){
		cin >> x;
		pos[x] = i;
	}
	int l = n + 1, r = -1;
	ll ans = 0;
	for(int mex = 1; mex <= n; mex++){
		l = min(l, pos[mex - 1]);
		r = max(r, pos[mex - 1]);
		int p = pos[mex];
		if(l <= p and p <= r)
			continue; // there are no segments with such mex
		int possibL = l + 1;
		if(p < l)
			possibL = l - p;
		int possibR = n - r;
		if(p > r)
			possibR = p - r;
		int maxlen = 2 * mex;
		if(p < l){
			for(int i = p + 1; i <= l; i++){
				int most_right_end = min(i + maxlen - 1, n - 1);
				if(most_right_end < r) continue;
				ans += ll(most_right_end - r + 1);
			}
		}else{
			for(int i = p - 1; i >= r; i--){
				int most_left_end = max(i - maxlen + 1, 0);
				if(most_left_end > l) continue;
				ans += ll(l - most_left_end + 1);
			}
		}
	}
	cout << ans << endl;
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
