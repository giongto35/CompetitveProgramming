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
#include <iomanip>

using namespace std ;

#define FOREACH(it,c) for( __typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define FOR(i,a,b) for( int i=(a),_b=(b);i<=_b;i++)
#define DOW(i,b,a) for( int i=(b),_a=(a);i>=_a;i--)
#define REP(i,n) FOR(i,0,(n)-1)
#define DEP(i,n) DOW(i,(n)-1,0)
#define all(a) (a).begin() , (a).end()
#define mp(a,b) make_pair((a),(b))
#define RESET(c,x) memset (c, x, sizeof (c))
#define oo 1000111000
#define PI acos(-1.0)
#define fi first
#define se second
#define SIZE(c) (c).size()

typedef vector<int> VI ;
typedef vector<string> VS ;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;

template<class T> inline int size(const T&c) { return c.size(); }

using namespace std;
int fastMax(int x, int y) { return (((y-x)>>(32-1))&(x^y))^y; }
int fastMin(int x, int y) { return (((y-x)>>(32-1))&(x^y))^x; }

const int maxn = 200000 + 10;
const int maxm = 1000000 + 10;
int sbd,np,maxt,r,mm,n;
int u,v,cap,ttime;
int dest[maxn];

struct edge{ int x; int y; int c; int f;} e[maxm];
vector<int> ke[maxn];
int q[maxm];
map<int,int> d[maxn];
int tra[maxn];
int las,fir,res,s,t,m,TC,N,T;
int W[maxn],L[maxn],R[maxn];
int sT;
string st[maxn];
int cf(int i) {  return e[i].c - e[i].f;}

void addedge(const int x, const int y, const int c)
{
	e[++m].x = x;
	e[m].y = y;
	e[m].c = c;
	e[m].f = 0;
}

void swap (int &u, int &v)
{
	int tg = u;
	u = v;
	v = tg;
}

bool findF()
{
	memset(tra,0,sizeof(tra));
	fir  = 0; las = 0;
	q[0] = s; tra[s] = -1;
	while (fir <= las){
		int u = q[fir]; fir ++;
		FOREACH(i, ke[u])
		{
			if (tra[e[*i].y] == 0 && cf(*i) > 0){
					tra[e[*i].y] = *i;
					las++;
					q[las] = e[*i].y;
					if (q[las] == t) return true;
			}
		}
	}
	return false;
}

void IncFlow()
{
	int u = t,delta = oo,i;
	while (u!=s){
		i  = tra[u];
		delta = min(delta,cf(i));
		u = e[i].x;
	}
	res += delta;
	u = t;
	while (u!= s){
		i = tra[u];
		e[i].f += delta;
		if (i<=m) e[i+m].f -= delta; else e[i-m].f -=delta;
		u = e[i].x;
	}
}

int RunFlow()
{
	FOR(i,1,m) { e[i+m] = e[i]; swap(e[i+m].x,e[i+m].y);e[i+m].c = d[e[i+m].x][e[i+m].y];}
	FOR(i,0,t) ke[i].clear();
	FOR(i,1,m*2) ke[e[i].x].push_back(i);
	res = 0;
	while (findF()) IncFlow();
	return res;
}

int conv(int i, int j) {
    return i * (maxt + 1) + j;
}

int main()
{
    //freopen("A.inp","r",stdin);
    //freopen("A.out","w",stdout);
    scanf("%d",&T);
    while (T--) {
        scanf("%d",&n);
        scanf("%d%d%d",&sbd,&np,&maxt);
        scanf("%d",&mm);

        for (int i = 1; i <= mm; i++) {
            scanf("%d",&dest[i]);
        }
        scanf("%d",&r);

        m = 0;

        for (int i = 1; i <= r; i++) {
            scanf("%d%d%d%d",&u,&v,&cap,&ttime);
            //cout<<u<<' '<<v<<' '<<cap<<' '<<ttime<<endl;
            for (int j = 0; j + ttime <= maxt; j++) {
                addedge(conv(u, j), conv(v, j + ttime), cap);
            }
        }
        for (int i = 1; i <= mm; i++) {
            for (int j = 0; j <= maxt; j++)
                addedge(conv(dest[i], j), conv(n + 1, 1), oo);
        }

        for (int j = 0; j < maxt; j++) {
            addedge(conv(sbd, j), conv(sbd, j + 1), oo);
        }

        addedge(conv(n + 1, 0), conv(sbd, 0), np);
        s = conv(n + 1, 0);
        t = conv(n + 1, 1);
        printf("%d\n", RunFlow());
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

