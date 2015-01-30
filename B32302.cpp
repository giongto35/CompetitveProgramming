#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <set>
using namespace std;
#define FOR(i, a, b) for(int i = a; i <= b; i ++)
#define DOW(i, a, b) for(int i = a; i >= b; i --)
#define FOREACH(it, c) for(typeof(c.begin()) it = c.begin(); it != c.end(); it ++)
#define RESET(c, val) memset(c, val, sizeof(c))
#define MAX_E 300 // this solution will not work with larger instances

int V, E, k, u[MAX_E], v[MAX_E], cover, best_cover;
bool valid;
int test, n;
const int maxn = 500+10;
int x[maxn][5];
int a[maxn][maxn];

void Steven() {
  int i; k = V / 3 * 2;
  best_cover = -1;
  for (cover = 0; cover < (1<<V); cover++) { // cover is a bitmask that describes the vertex cover, this is O(2^V * E) brute force algorithm
    if (__builtin_popcount(cover) != k) continue; // skip this cover if the size of cover is not k, works with C++11 GNU compilers

    valid = true;
    for (i = 0; i < E && valid; i++)
      if (!((cover & (1<<u[i])) | (cover & (1<<v[i])))) // if neither u[i] or v[i] is on in 'cover', this 'cover' is invalid
        valid = false;

    if (valid)
      best_cover = cover;
  }
  if (best_cover == -1) {
    printf("0\n");
  } else {
    printf("1\n");
  }
}
int main() {
	//freopen("A3230.inp", "r", stdin);
	//freopen("test.out", "w", stdout);
	cin >> test;
	cout<<test<<endl;
	while (test --) {
		RESET(a, 0);
		cin >> n;
		E = 0, V = n * 3;
		set<int> se;
		FOR(i, 1, n) FOR(j, 1, 3) scanf("%d", &x[i][j]), se.insert(abs(x[i][j]));
		k = se.size();
		FOR(i1, 1, n) FOR(i2, i1 + 1, n)
		FOR(j1, 1, 3) FOR(j2, 1, 3) {
			int k1 = (i1 - 1) * 3 + j1 - 1;
			int k2 = (i2 - 1) * 3 + j2 - 1;
			a[k1][k2] = (x[i1][j1] + x[i2][j2]) != 0;
		}
		FOR(i, 0, V - 1) FOR(j, i + 1, V - 1)
			if (a[i][j] == 0) {
				E ++;
				u[E - 1] = i;
				v[E - 1] = j;
			}
		//Steven_code();
        cout<<V<<' '<<E<<endl;
        FOR(i,0,E-1) cout<<u[i]<<' '<<v[i]<<endl;
	}
	return 0;
}
