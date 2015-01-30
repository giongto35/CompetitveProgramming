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
const int maxgh = 10000;
struct kdl
{
    int s;
    int t;
    int idx;
} a[50];
struct tracer
{
    int i,j,k,p1,p2;
}tr[32][32][maxgh+10];
vector<pair<int,int> > kq;
int F[32][32][maxgh+10];
int vt[100000];
int spt,n,m,l,r;

bool mycmp(kdl a,kdl b)
{
    if (a.t==b.t) return a.s<b.s;
    else
        return a.t<b.t;
}

void trace(int i,int j,int k)
{
    if (i==0&&j==0&&k==0) return;
    if (tr[i][j][k].p1!=0&&tr[i][j][k].p2!=0)
    kq.push_back(make_pair(tr[i][j][k].p1,tr[i][j][k].p2));
    trace(tr[i][j][k].i,tr[i][j][k].j,tr[i][j][k].k);
}

tracer make_tracer(int i,int j,int k,int p1,int p2)
{
    tracer temp;
    temp.i=i;temp.j=j;temp.k=k;temp.p1=p1;temp.p2=p2;
    return temp;
}

int main()
{
    freopen("J.inp","r",stdin);
    //freopen("J.out","w",stdout);
    scanf("%d%d",&n,&m);
    FOR(i,1,n)
        scanf("%d%d",&a[i].s,&a[i].t),a[i].idx=i;
    FOR(i,1,m)
    {
        scanf("%d%d",&l,&r);
        FOR(k,l,r-1) vt[++spt]=k;
    }
    sort(vt+1,vt+1+spt,greater<int>() );
    spt=min(spt,n);
    sort(vt+1,vt+1+spt);
    memset(F,0,sizeof(F));
    sort(a+1,a+1+n,mycmp);
    FOR(i,0,n) FOR(j,0,spt) FOR(k,0,maxgh) F[i][j][k]=-10000;
    F[0][0][0]=0;
    FOR(i,0,n)
    FOR(j,0,spt)
    FOR(k,0,maxgh)
    {
        if (F[i][j][k]>=0)
        {
            if (F[i+1][j][k]<F[i][j][k])//ko ghep i+1 voi j+1
            {
                F[i+1][j][k]=F[i][j][k];
                tr[i+1][j][k]=make_tracer(i,j,k,0,0);
            }
            if (F[i][j+1][k]<F[i][j][k])//bo qua j
            {
                F[i][j+1][k]=F[i][j][k];
                tr[i][j+1][k]=make_tracer(i,j,k,0,0);
            }
            if (k+a[i+1].t+1<=vt[j+1]+1&&F[i+1][j+1][k+a[i+1].t+1]<F[i][j][k]+a[i].s)//ghep i+1 voi j+1
            {
                F[i+1][j+1][k+a[i+1].t+1]=F[i][j][k]+a[i+1].s;
                tr[i+1][j+1][k+a[i+1].t+1]=make_tracer(i,j,k,a[i+1].idx,vt[j+1]);
            }
        }
    }
    int res=-1;
    int jj=0;
    FOR(j,0,maxgh)
        if (F[n][spt][j]>res) { res=F[n][spt][j]; jj=j;}
    trace(n,spt,jj);
    cout<<res<<' '<<kq.size()<<endl;
    DOW(i,kq.size()-1,0) cout<<kq[i].first<<' '<<kq[i].second<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

