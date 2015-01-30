#include "iostream"
#include "cstdio"
#include "cstdlib"
#include "cstring"
#include "map"
#include "queue"
#include "algorithm"
using namespace std;

typedef pair<int,int> pii;
#define fi first
#define se second
#define mp make_pair

const int N = 505;

int n, t, res;
int a[N];
map<pii,int> m;
queue<pii> Q;
pii now;

int gcd(int a, int b){
	return b == 0 ? a : gcd(b, a % b);
}

int Solve(){
	for(int i = 1; i <= n; i++) if (a[i] == 1) return 1;
	for(int i = 1; i <= n; i++)
		if (m[mp(1,a[i])] == 0){
			Q.push(mp(1, a[i]));
			m[mp(1,a[i])] = 1;
		}
	while (!Q.empty()){
		now = Q.front(); Q.pop();
		// cout << now.fi << " " << now.se << endl;
		for(int i = 1; i <= n; i++){
			t = gcd(now.se, a[i]);
			if (t == now.se || m[mp(now.fi+1, t)] != 0) continue;
			if (t == 1) return now.fi+1;
			Q.push(mp(now.fi+1, t));
			m[mp(now.fi+1, t)] = 1;
		}
	}
	return n+n;
}

int main(){
	freopen("DIVISOR.inp", "r", stdin);
	freopen("DIVISOR.out", "w", stdout);

	cin >> n;
	for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
	sort(a+1, a+n+1);
	int nn = 0;
	for(int i = 1; i <= n; i++){
		if (a[i] != a[i-1]) nn++;
		a[nn] = a[i];
	}
	n = nn;
	
	res = Solve();
	if (res > n) cout << "NO" << endl;
	else cout << res << endl;

	return 0;
}