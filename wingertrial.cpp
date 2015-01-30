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
const int maxm = 10000;
struct edge{ int x; int y; int c; int f; } e[maxm];
int n,m,s,t;
vector<int> ke[maxn];
int las, fir, res;
pair<int,int> a[maxn];
int q[maxm], tra[maxn];
int u,v,c;
int N,M,TC;
string u1,u2;
map<string,int> CH;
int cf(int i) {return e[i].c-e[i].f;}
int L,W,d;

void addedge(const int x,const int y, const int c)
{
    e[++m].x = x;
    e[m].y = y;
    e[m].c = c;
    e[m].f = 0;
}

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
                    //cout<<u<<' '<<*i<<endl;
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

int RunFlow()
{
	FOR(i,1,m) {e[i+m]=e[i];swap(e[i+m].x,e[i+m].y);e[i+m].c=0;}
	FOR(i,0,t) ke[i].clear();
	FOR(i,1,m*2) ke[e[i].x].push_back(i);
	res=0;
	while (findF()) IncFlow();
	return res;
}

int sqr(int u)
{
    return u * u;
}

int main()
{
    //freopen("wingertrial.inp","r",stdin);
    //freopen("NKFLOW.out","w",stdout);
    int cnt = 0;

    while (true){
        //scanf("%d%d%d%d",&n,&m,&s,&t);
        scanf("%d%d%d%d",&L,&W,&N,&d);
        if (L ==0 && W == 0&& N ==0 && d == 0) break;
        for (int i = 1; i <= N ; i ++)
            scanf("%d%d",&a[i].first,&a[i].second);
        m = 0;//set m to 0
        for (int i = 1; i <= N; i++)
            addedge(i*2-1,i*2,1);
        for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            if ( i != j && sqr(a[i].first-a[j].first) + sqr(a[i].second - a[j].second) <= sqr(2*d))
                addedge(i*2,j*2-1,1);
        //set s and t
        s = 0;
        t = N*2+1;
        FOR(i,1,N)
            if (a[i].second - d <= 0)
                addedge(s,i*2-1,1);
        FOR(i,1,N)
            if (a[i].second + d >= W)
                addedge(i*2,t,1);
        cnt++;
        cout<<"Case "<<cnt<<": ";
        cout<<RunFlow()<<endl;
        TC--;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

