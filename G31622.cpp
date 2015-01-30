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

typedef int ll;

const ll base = 10007;
const int hashmod = 123453;

char s[2000+10];
int n;
char p[2000+10];
int l[11], r[11];
//map<ll, int> d[11];
//map<ll, bool> daco;
vector<int> daco[hashmod];
vector<int> d[11][hashmod],t[11][hashmod];
int g[4000000+10];
int res;

inline bool search( int &u , vector<int> &l )
{
    FOR(i,0,l.size()-1) if (l[i]==u) return true;
    return false;
}

inline void insert( int &u, vector<int> &l)
{
    l.push_back(u);
}

int main() {
	 //freopen("G316.inp", "r", stdin);

	scanf("%s", s+1);
	scanf("%d", &n);
	FOR(i,1,n){
		scanf("%s%d%d", p+1, &l[i], &r[i]);
		int m = strlen(p+1);
		//int sum=0;
        int sl=0;
		FOR(j,1,m) {
			ll h = 0;
			FOR(k,j,m) {
				h = h * base + p[k];
				g[++sl]=h;
				//sum++;
				//if (sum>=l[i]&&sum<=r[i]) insert(h,d[i][abs(h)%hashmod]);
			}
		}
			sort(g+1,g+1+sl);
			g[sl+1]=-12312125;
			int cnt=0;
			FOR(j,1,sl+1)
			{
			    if (j!=1&&g[j]!=g[j-1])
                {
                    if (cnt>=l[i]&&cnt<=r[i])
                        {
                            //cout<<i<<' '<<g[j-1]<<endl;
                            insert(g[j-1],d[i][abs(g[j-1])%hashmod]);
                        }
                    insert(g[j-1],t[i][abs(g[j-1])%hashmod]);
                    cnt=0;
                }
                cnt++;
			}

	}
	//cout<<endl;

	int res = 0;

	int m = strlen(s+1);
	FOR(j,1,m) {
		ll h = 0;
		FOR(k,j,m) {
			h = h * base + s[k];
			int vh=abs(h)% hashmod;
			if (search(h,daco[vh])==false) {
                //cout<<h<<endl;
				insert(h,daco[vh]);
				bool ok = 1;
				FOR(i,1,n) {
					//int u = d[i][h];
					//if (u < l[i] || u > r[i]) { ok = 0; break; }
					//cout<<search(h,d[i][vh])<<endl;
					if (search(h,t[i][vh])==false)
                    {
                        if (l[i]==0) continue; else
                        {
                            ok=0;
                            break;
                        }
                    }
					else
                    if (search(h,d[i][vh])==false)
                    {
                        ok=0;
                        break;
                    }
				}
				//if (ok) cout<<j<<' '<<k<<' '<<h<<endl;
				res += ok;
			}
		}
	}

	printf("%d\n", res);

	return 0;
}
