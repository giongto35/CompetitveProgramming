#include "cstdio"
#include "iostream"
#include "vector"
#include "algorithm"
#include "cstring"

using namespace std;

int n, m;
bool a[110][110];
int my[110];
bool visited[110];

bool go(int u) {
	if (u == 0) return true;
	if (!visited[u]) return false;
	visited[u] = false;
	for(int v = 1; v <= m; v++)
		if (a[u][v] && go(my[v])) {
			my[v] = u;
			return true;
		}
	return false;
}

int main() {
	// freopen("in", "r", stdin);
	scanf("%d%d", &n, &m);
	memset(a, false, sizeof a);
	int u, v;
	while (scanf("%d%d", &u, &v) != EOF)
		a[u][v] = true;
	memset(my, 0, sizeof my);
	int ret = 0;
	for(u = 1; u <= n; u++) {
		memset(visited, true, sizeof visited);
		if (go(u)) ret++;
	}
	printf("%d\n", ret);
	for(int v = 1; v <= m; v++)
		if (my[v]) printf("%d %d\n", my[v], v);
	return 0;
}