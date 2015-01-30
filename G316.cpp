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
#include <cstring>
#include <ctime>
#include <queue>
using namespace std ;

#define FOREACH(it,c) for( __typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define FOR(i,a,b) for( int i=(a),_b=(b);i<=_b;i++)
#define DOW(i,b,a) for( int i=(b),_a=(a);i>=_a;i--)
#define REP(i,n) FOR(i,0,(n)-1)
#define DEP(i,n) DOW(i,(n)-1,0)
#define all(a) (a).begin() , (a).end()
#define push(a,b) (a).push_back((b))

typedef vector<int> VI ;
typedef vector<string> VS ;
template<class T> inline int size(const T&c) { return c.size(); }

using namespace std;

typedef long long ll;

const ll base = 10017;
const int hashmod = 1000003;

char s[2000+10];
int n;
char p[2000+10];
int l[11], r[11];
//map<ll, int> d[11];
//map<ll, bool> daco;
vector<int> daco[hashmod];
vector<int> d[11][hashmod];
int h;
int res;

inline bool search( int u , vector<int> l )
{
    FOR(i,0,l.size()-1) if (l[i]==u) return true;
    return false;
}

inline void insert( int u, vector<int> l)
{
    l.push_back(u);
}

int main() {
	 freopen("G316.inp", "r", stdin);

	scanf("%s", s+1);
	scanf("%d", &n);
	FOR(i,1,n){
		scanf("%s%d%d", p+1, &l[i], &r[i]);
		int m = strlen(p+1);
		int sum=0;
		FOR(j,1,m) {
			ll h = 0;
			FOR(k,j,m) {
				h = h * base + p[k];
				sum++;
				if (sum>=l[i]&&sum<=r[i]) insert(h,d[i][abs(h)%hashmod]);
			}
		}

	}

	int res = 0;

	int m = strlen(s+1);
	FOR(j,1,m) {
		ll h = 0;
		FOR(k,j,m) {
			h = h * base + s[k];
			int vh=abs(h)% hashmod;
			if (search(h,daco[vh])==false) {
                    cout<<h<<endl;
				insert(h,daco[vh]);
				bool ok = 1;
				FOR(i,1,n) {
					//int u = d[i][h];
					//if (u < l[i] || u > r[i]) { ok = 0; break; }
                    if (search(h,d[i][vh])==false&&l[i]>0)
                    {
                        ok=0;
                        break;
                    }
				}
				res += ok;
			}
		}
	}

	printf("%d\n", res);

	return 0;
}
