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

int n, k;
long long a[100010];
map<long long, bool> f;

int main() {
	scanf("%d%d", &n, &k);
	for(int i = 1; i <= n; i++) scanf("%I64d", a+i);
	sort(a+1, a+1+n);
	int ret = 0;
	for(int i = 1; i <= n; i++) {
		if (!f[a[i]]) {
			ret++;
			f[a[i]*k] = 1;
		}
	}
	printf("%d", ret);
	return 0;
}