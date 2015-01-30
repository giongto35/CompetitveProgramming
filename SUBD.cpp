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
const int maxn=100000+10;
struct tri
{
    int c;
    int t;
    int cs;
};
struct pack
{
    long long sc;
    long long st;
    int cs;
    vector<tri> rep;
} a[maxn];
int n,cnt;

bool cmp(pack a,pack b)
{
    if ((long long)a.sc*b.st==(long long)b.sc*a.st) return a.cs<b.cs;
    return (long long)a.sc*b.st>(long long)b.sc*a.st;
}

bool cmp2(tri a,tri b)
{
    if ((long long)a.c*b.t==(long long)b.c*a.t) return a.cs<b.cs;
    return (long long)a.c*b.t>(long long)b.c*a.t;
}
long long res;
long long st;

int main()
{
    //freopen("SUBD.inp","r",stdin);
    //freopen("SUBD.out","w",stdout);
    cin>>n;
    FOR(i,1,n)
    {
        scanf("%d",&cnt);
        a[i].cs=i;
        a[i].rep.resize(cnt);
        FOR (j,0,cnt-1)
        {
            a[i].rep[j].cs=j;
            scanf("%d",&a[i].rep[j].t);
            a[i].st+=a[i].rep[j].t;
        }
        FOR (j,0,cnt-1)
        {
            scanf("%d",&a[i].rep[j].c);
            a[i].sc+=a[i].rep[j].c;
        }
    }
    sort(a+1,a+1+n,cmp);
    st=0;
    FOR(i,1,n)
    {
        sort(a[i].rep.begin(),a[i].rep.end(),cmp2);
        FOR(j,0,a[i].rep.size()-1)
        {
            st=st+a[i].rep[j].t;
            res+=st*(a[i].rep[j].c);
        }
    }
    printf("%lld\n",res);
    FOR(i,1,n)
    {
        printf("%d\n",a[i].cs);
        FOR(j,0,a[i].rep.size()-1)
        printf("%d ",a[i].rep[j].cs+1);
        printf("\n");
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
