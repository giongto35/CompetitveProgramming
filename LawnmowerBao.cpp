
#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <map>
#include <cstring>
#include <queue>

using namespace std;

int test, n, m;
int a[110][110];
int mr[110], mc[110];

int main() {
	freopen("lawnmower.inp", "r", stdin);
	// freopen("LAWNMOWER.inp", "r", stdin);
	//freopen("LAWNMOWER2.out", "w", stdout);

	scanf("%d", &test);
	for(int tcase = 1; tcase <= test; tcase++) {
		printf("Case #%d: ", tcase);
		scanf("%d%d", &n, &m);
		memset(mr, 0, sizeof mr);
		memset(mc, 0, sizeof mc);
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= m; j++) {
				scanf("%d", &a[i][j]);
				mr[i] = max(mr[i], a[i][j]);
				mc[j] = max(mc[j], a[i][j]);
			}
		bool ok = 1;
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= m; j++)
				if (a[i][j] < min(mr[i], mc[j])) ok = 0;
		printf("%s\n", ok ? "YES" : "NO");
	}
	return 0;
}
