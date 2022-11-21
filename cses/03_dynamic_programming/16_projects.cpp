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
	int n;
	cin >> n;
	vector<tuple<int,int,ll>> projects; // end, start, cost
	vi tmp(2 * n);
	for(int i = 0; i < n; i++){
		int a, b, p;
		cin >> a >> b >> p;
		tmp[2 * i] = a;
		tmp[2 * i + 1] = b;
		projects.pb({b, a, p});
	}
	sortall(tmp);
	auto e = unique(all(tmp));
	tmp.resize(e - tmp.begin());
	for(int i = 0; i < n; i++){
		get<0>(projects[i]) = lower_bound(all(tmp), get<0>(projects[i])) - tmp.begin() + 1;
		get<1>(projects[i]) = lower_bound(all(tmp), get<1>(projects[i])) - tmp.begin() + 1;
	}
	sortall(projects);
	vl dp(tmp.size() + 1, -INF);
	dp[0] = 0;
	int j = 0;
	for(int i = 1; i <= tmp.size(); i++){
		while(j < n and get<0>(projects[j]) == i){
			dp[i] = max(dp[i], get<2>(projects[j]) + dp[get<1>(projects[j]) - 1]);
			j++;
		}
		dp[i] = max(dp[i], dp[i - 1]);
	}
	cout << dp[tmp.size()];
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