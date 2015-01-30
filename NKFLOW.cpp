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
#define fi first
#define se second

typedef vector<int> VI ;
typedef vector<string> VS ;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;

template<class T> inline int size(const T&c) { return c.size(); }

using namespace std;
int fastMax(int x, int y) { return (((y-x)>>(32-1))&(x^y))^y; }
int fastMin(int x, int y) { return (((y-x)>>(32-1))&(x^y))^x; }

const int maxn = 1000+10;
const int oo = 1000000000;
const int maxm = 100000;
struct edge{ int x; int y; int c; int f; } e[maxm*2];
int n,m,s,t;
vector<int> ke[maxn];
int las, fir, res;
int q[maxm*2], tra[maxn];
int u,v,c;
int cf(int i) {return e[i].c-e[i].f;}

void swap(int &u,int &v)
{
    int tg=u;u=v;v=tg;
}
bool findF() {
    //RESET(tra, 0);
    memset(tra,0,sizeof(tra));
    fir=0, las=0;
    q[0]=s; tra[s]=-1;
    while (fir<=las) {
        int u=q[fir]; fir++;
        FOREACH(i, ke[u])
        {
            if (tra[e[*i].y]==0 && cf(*i)>0) {
                tra[e[*i].y]=*i;
                las++, q[las]=e[*i].y;
                if (q[las]==t) return true;
            }
        }
    }
    return false;
}
void IncFlow() {
    int u=t, delta=oo, i;
    while (u!=s) {
        i=tra[u];
        delta=min(delta, cf(i));
        u=e[i].x;
    }
    res+=delta;
    u=t;
    while (u!=s) {
        i=tra[u];
        e[i].f+=delta;
        if (i<=m) e[i+m].f-=delta; else e[i-m].f-=delta;
        u=e[i].x;
    }
}

int main()
{
    //freopen("NKFLOW.inp","r",stdin);
    //freopen("NKFLOW.out","w",stdout);
    scanf("%d%d%d%d",&n,&m,&s,&t);
    FOR(i,1,m)
    {
		scanf("%d%d%d",&u,&v,&c);
		e[i].x=u;
		e[i].y=v;
		e[i].c=c;
		e[i].f=0;

	}
	FOR(i,1,m) {e[i+m]=e[i];swap(e[i+m].x,e[i+m].y);e[i+m].c=0;}
	FOR(i,0,t) ke[i].clear();
	FOR(i,1,m*2) ke[e[i].x].push_back(i);
	res=0;
	while (findF()) IncFlow();
	cout<<res;

    fclose(stdin);
    fclose(stdout);
    return 0;
}
