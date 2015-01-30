#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>

#define sz(v) v.size()
#define pb push_back
#define int64 long long
#define pll pair<long, long>
#define fi first
#define se second
#define mp make_pair
#define FOR(i, a, b) for(i = a; i <= b; i++)
#define DOWN(i, a, b) for(i = a; i >= b; i--)
#define REP(i, a) for(i = 0; i < a; i++)
#define getBit(x, i) ((x >> i) & 1)
#define onBit(x, i) (x | (1LL << i))
#define offBit(x, i) (x & (~(1LL << i)))
#define all(v) v.begin(),v.end()

using namespace std;

typedef pair<int, int> pii;

int n, m, res; 
vector<int> X[111];
int mX[111], mY[111];
bool mark[111];

int find(int x) {
	if (x == 0) return 1; 
	if (mark[x]) return 0;
	mark[x] = 1;
	int i; 
	REP(i, sz(X[x])) {
		int y = X[x][i];
		if (find(mY[y])) {
			mX[x] = y; mY[y] = x;
			return 1; 
		}
	}
	return 0;
}

int main() {

	//freopen("match1.inp", "r", stdin);
	//freopen("match1.out", "w", stdout);

	scanf("%d%d", &n, &m);
	int u, v; 
	while (scanf("%d%d", &u, &v) != EOF) X[u].pb(v); 

	int i; 
	FOR(i, 1, n) 
		if (mX[i] == 0) {
			memset(mark, 0, sizeof mark);
			res += find(i);
		}
	printf("%d\n", res);
	FOR(i, 1, n) 
		if (mX[i] != 0) 
			printf("%d %d\n", i, mX[i]);

}
