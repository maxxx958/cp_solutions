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

ll a, b, c, d;

bool inside(ll x, ll y){
	if(a < x and x <= c and b < y and y <= d){
		cout << x << ' ' << y << endl;
		return true;
	}
	if(a < y and y <= c and b < x and x <= d){
		cout << y << ' ' << x << endl;
		return true;
	}
	return false;
}

void solve(){
	cin >> a >> b >> c >> d;
	vl diva, divb;
	// find all divisors of a and b
	// iterate over all possible gcd of x and a*b -> some diva * divb
	// for each such gcd we can find some multiple of it inside <a+1, c>
	// and multiple of what else is needed (a*b/gcd) in <b, d>
	// ez gains
	for(ll i = 1; i * i <= a; i++){
		if(a % i) continue;
		diva.pb(i);
		diva.pb(a / i);
	}
	for(ll i = 1; i * i <= b; i++){
		if(b % i) continue;
		divb.pb(i);
		divb.pb(b / i);
	}
	for(ll g1 : diva){
		for(ll g2 : divb){
			ll g = g1 * g2;
			ll s = a * b / g;
			ll x = c / g * g;
			ll y = d / s * s;
			if(inside(x, y)){
				return;
			}
		}
	}
	cout << "-1 -1" << endl;
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
