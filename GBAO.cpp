#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <queue>
#include <cstring>
#include <string>

using namespace std;

typedef long long ll;

const ll base = 1000003;

char s[2222];
int n;
char p[2222];
int l[11], r[11];
map<ll, int> f[11];
map<ll, bool> considered;

int main() {
	 freopen("G316.inp", "r", stdin);

	scanf("%s", s+1);
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		scanf("%s%d%d", p+1, &l[i], &r[i]);
		f[i].clear();
		int m = strlen(p+1);
		for(int j = 1; j <= m; j++) {
			ll hash = 0;
			for(int k = j; k <= m; k++) {
				hash = hash * base + p[k];
				f[i][hash]++;
			}
		}
	}

	int ret = 0;
	considered.clear();
	int m = strlen(s+1);
	for(int j = 1; j <= m; j++) {
		ll hash = 0;
		for(int k = j; k <= m; k++) {
			hash = hash * base + s[k];
			if (!considered[hash]) {
				considered[hash] = 1;
				bool ok = 1;
				for(int i = 1; i <= n; i++) {
					int occurs = f[i][hash];
					if (occurs < l[i] || occurs > r[i]) {
						ok = 0;
						break;
					}
				}
				ret += ok;
			}
		}
	}

	printf("%d\n", ret);

	return 0;
}
