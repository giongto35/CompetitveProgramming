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

const int maxn=1000+10;
int a[maxn];
pair<int,int> c[maxn],p[maxn];
int d[maxn];
int main()
{
    freopen("E339.inp","r",stdin);
    freopen("E339.out","w",stdout);
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d",&a[i]);
    while (i<=n;)
    {
        int j=i;
        if (a[j]+1==a[j+1])
        {
            while (j<n&&a[j]+1==a[j+1]) j++;
        }
        else
        {
            while (j<n&&a[j]-1==a[j+1]) j++;
        }
        c[++spt].fi=a[i];
        c[spt].se=i;
        d[spt]=a[i];
        c[++spt].fi=a[j];
        c[spt].se=j;
        d[spt]=a[j];
        i=j+1;
        i++;
    }
    sort(d+1,d+1+spt);
    FOR(i,1,spt) cs[d[i]]=i;
    FOR(i,1,spt) c[i]=cs[c[i]];
    for(int i1=1;i1<=spt;i1+=2)for(int j1=2;j1<=spt;j1+=2)
    for(int i2=1;i2<=spt;i2+=2)for(int j2=2;j2<=spt;j2+=2)
    for(int i3=1;i3<=spt;i3+=2)for(int j3=2;j3<=spt;j3+=2)
    {
        for (k,1,spt) p[k]=c[k];
        reverse(p+i1+1,p+j1+1);
        reverse(p+i2+1,p+j2+1);
        reverse(p+i3+1,p+j3+1);
        bool ok=true;
        FOR(i,1,spt) if (p[i].fi!=i) {ok=false;break;}
        if (ok)
        {
            cout<<3;
            FOR(
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

