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

pii moves[] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
string moveS = "DURL";


void solve(){
	int n, m;
	cin >> n >> m;
	vector<string> grid(n);
	for(int i = 0; i < n; i++){
		cin >> grid[i];
	}
	queue<pair<int, pii>> monsters;
	queue<pair<int, pii>> A;
	//first the monsters take a step, then me and we block each other out
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(grid[i][j] == 'M'){
				monsters.push({0, {i, j}});
				grid[i][j] = '#';
			}
			if(grid[i][j] == 'A'){
				A.push({0, {i, j}});
			}
		}
	}
	int d = 0;
	while(A.size()){
		//monsters move
		while(monsters.size() and monsters.front().st == d){
			pii pos = monsters.front().nd;
			monsters.pop();
			for(int i = 0; i < 4; i++){
				pii np = {pos.st + moves[i].st, pos.nd + moves[i].nd};
				if(np.st < 0 or n <= np.st or np.nd < 0 or m <= np.nd) continue;
				if(grid[np.st][np.nd] == '.'){
					grid[np.st][np.nd] = '#';
					monsters.push({d + 1, np});
				}
			}
		}
		while(A.size() and A.front().st == d){
			pii pos = A.front().nd;
			A.pop();
			for(int i = 0; i < 4; i++){
				pii np = {pos.st + moves[i].st, pos.nd + moves[i].nd};
				if(np.st < 0 or n <= np.st or np.nd < 0 or m <= np.nd) continue;
				if(grid[np.st][np.nd] == '.'){
					grid[np.st][np.nd] = moveS[i];
					A.push({d + 1, np});
				}
			}
		}
		d++;
	}
	pii start = {-1, -1};
	for(int i = 0; i < n; i++){
		if(grid[i][0] != '.' and grid[i][0] != '#'){
			start = {i, 0};
			break;
		}
		if(grid[i][m - 1] != '.' and grid[i][m - 1] != '#'){
			start = {i, m - 1};
			break;
		}
	}
	for(int i = 0; i < m; i++){
		if(grid[0][i] != '.' and grid[0][i] != '#'){
			start = {0, i};
			break;
		}
		if(grid[n - 1][i] != '.' and grid[n - 1][i] != '#'){
			start = {n - 1, i};
			break;
		}
	}
	
	if(start.st == -1){
		cout << "NO" << endl;
		return;
	}
	cout << "YES" << endl;
	string ans = "";
	while(grid[start.st][start.nd] != 'A'){
		ans += grid[start.st][start.nd];
		for(int i = 0; i < 4; i++){
			if(grid[start.st][start.nd] != moveS[i]) continue;
			start.st -= moves[i].st;
			start.nd -= moves[i].nd;
			break;
		}
	}
	cout << ans.size() << endl;
	for(int i = ans.size() - 1; i >= 0; i--){
		cout << ans[i];
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