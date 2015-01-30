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
#include <fstream>

using namespace std;

// Garbled Email

string dict[11][521196];
int cdict[11];
string s;
int test, n;
int f[55][55];

int main() {

	freopen("garbled_email_dictionary.txt", "r", stdin);
	memset(cdict, 0, sizeof cdict);
	for(int i = 0; i < 521196; i++) {
		getline(cin, s);
		dict[s.length()][cdict[s.length()]++] = s;
	}	
	fclose(stdin);

	freopen("C-small.inp", "r", stdin);
	freopen("C.out", "w", stdout);

	scanf("%d\n", &test);
	for(int ttest = 1; ttest <= test; ttest++) {
		getline(cin, s);
		
		s = "@" + s;
		memset(f, 63, sizeof f);
		f[0][0] = 0;
		for(int i = 1; i < s.length(); i++) {
			for(int k = max(0, i-10); k < i; k++) {
				for(int j = 0; j <= k; j++) {
					for(int id = 0; id < cdict[i-k]; id++) {
						int last = j, diff = 0;
						for(int idx = 0; idx < i-k; idx++) 
							if (dict[i-k][id][idx] != s[k+1+idx]) {
								if (last && k+1+idx-last < 5) {
									last = -1;
									break;
								}
								last = k+1+idx;
								diff++;
							}
						if (last != -1) f[i][last] = min(f[i][last], f[k][j] + diff);
					}					
				}
			}
		}
		int ret = 1e9;
		for(int j = 0; j < s.length(); j++) 
			ret = min(ret, f[s.length()-1][j]);
		printf("Case #%d: %d\n", ttest, ret);
	}

	return 0;
}