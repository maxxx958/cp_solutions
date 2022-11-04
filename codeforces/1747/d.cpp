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
	int n, q;
	cin >> n >> q;
	vi cnt[30];
	vi zeros = {0};
	for(int i = 0; i < 30; i++){
		cnt[i].pb(0);
	}
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		zeros.pb(zeros.back());
		if(x == 0){
			zeros.back()++;
		}
		for(int j = 0; j < 30; j++){
			cnt[j].pb(cnt[j].back());
			if(x&(1<<j)){
				cnt[j].back()++;
			}
		}
	}
	map<int, int> last[2];
	vi last_same_mask(n + 1, -1);
	for(int i = 1; i <= n; i++){
		// if two indexes have the same bit parity for every power of 2 up to 30
		// then we can delete the whole segment from last[mask] + 1 to i
		int mask = 0;
		for(int j = 0; j < 30; j++){
			mask |= ((cnt[j][i] % 2) << j);
		}
		if(last[i % 2 ^ 1].find(mask) != last[i % 2 ^ 1].end()){
			last_same_mask[i] = last[i % 2 ^ 1][mask] + 1;
		}
		last[i % 2][mask] = i;
	}

	
	while(q--){
		int l, r;
		cin >> l >> r;
		l--;
		if((l - r) % 2){ // odd
			bool cando = true;
			for(int i = 0; i < 30; i++){
				if((cnt[i][r] - cnt[i][l]) % 2 == 1){
					cando = false;
					break;
				}
			}
			if(!cando){
				cout << -1 << endl;
			}else{
				if(zeros[r] - zeros[l] == r - l){
					cout << 0 << endl;
				}else{
					cout << 1 << endl;
				}
			}
		}else{ // even
			bool cando = true;
			for(int i = 0; i < 30; i++){
				if((cnt[i][r] - cnt[i][l]) % 2 == 1){
					cando = false;
					break;
				}
			}
			if(!cando){
				cout << -1 << endl;
			}else{
				if(zeros[r] - zeros[l] == r - l){
					cout << 0 << endl;
				}else{
					if(last_same_mask[r] > l){
						if((zeros[r] - zeros[r - 1]) or (zeros[l + 1] - zeros[l])){
							cout << 1 << endl;
						}else{
							cout << 2 << endl;
						}
					}else{
						cout << -1 << endl;
					}
				}
			}
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