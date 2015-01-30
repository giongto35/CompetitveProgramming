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
const int maxn=50000+10;
int lab[maxn];
int res,n,m,k;
int stest;
int sres;
struct edge
{
    int c;
    int u;
    int v;
    int t;
} E[maxn*2];
int sum;

bool mycmp(edge a,edge b)
{
    return (a.c<b.c||(a.c==b.c&&a.t<b.t));
}

int getroot(int u)
{
    if (lab[u]==-1) return u;
    else
        return lab[u]=getroot(lab[u]);
}

bool check(int w)
{
    FOR(i,0,n-1) lab[i]=-1;
    FOR(i,1,m) if (E[i].t==0) E[i].c+=w;
    sort(E+1,E+1+m,mycmp);
    int sl=0;
    sum=0;
    FOR(i,1,m)
    {
        int u=getroot(E[i].u);
        int v=getroot(E[i].v);
        if (u!=v)
        {
            lab[u]=v;
            sum+=E[i].c;
            if (E[i].t==0) sl++;
        }
    }
    FOR(i,1,m) if (E[i].t==0) E[i].c-=w;
    if (sl>=k) return true; else return false;
}
int main()
{
    freopen("tree.in","r",stdin);
    freopen("companys.out","w",stdout);
    while(scanf("%d%d%d",&n,&m,&k)==3)
    {
        FOR(i,1,m) scanf("%d%d%d%d",&E[i].u,&E[i].v,&E[i].c,&E[i].t);
        stest++;
        int l=-100;
        int r=100;
        int res;
        while(l<=r)
        {
            int m=(l+r)/2;
            if (check(m))
            {
                res=m;
                l=m+1;
            }
            else r=m-1;
        }
        check(res);
        cout<<"Case "<<stest<<": "<<sum-res*k<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

