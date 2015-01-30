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
const int maxn = 300000+10;
int a[maxn];
int c[maxn];
int vt[maxn];
int d[maxn];
int p,x,y,n,q;
int BIT[maxn];

void update(int i,int gt)
{
    if (i==0) return;
    while (i<=n)
    {
        BIT[i]=BIT[i]+gt;
        i=i+(i & (-i));
    }
}

int get(int i)
{
    int gt=0;
    while (i>=1)
    {
        gt=BIT[i]+gt;
        i=i-(i & (-i));
    }
    return gt;
}

void swap(int &a,int &b)
{
    int tg;tg=a;a=b;b=tg;
}

int main()
{
    //freopen("B331.inp","r",stdin);
    //freopen("B331.out","w",stdout);
    scanf("%d",&n);
    FOR(i,1,n)
    {
        scanf("%d",&a[i]);
        c[a[i]]=i;
        vt[i]=a[i];
    }
    FOR(i,1,n)
    {
        d[i]=((c[i]-c[i-1])<0);
        update(i,d[i]);
    }

    scanf("%d",&q);
    FOR(i,1,q)
    {
        //FOR(i,1,n) cout<<c[i]<<' ';cout<<endl;
        //FOR(i,1,n) cout<<d[i]<<' ';cout<<endl;
        //FOR(i,1,n) cout<<get(i)-get(i-1)<<' ';cout<<endl;
        scanf("%d%d%d",&p,&x,&y);
        //cout<<p<<' '<<x<<' '<<y<<endl;
        if (p==1)
        {
            int res=0;
            FOR(j,x+1,y) res=res+d[j];
            cout<<get(y)-get(x)+1<<endl;
        }
        else
        {

            int u=vt[x];
            int v=vt[y];
            //cout<<"DIT"<<endl;
            //cout<<"CHANGE "<<p<<' '<<u<<' '<<v<<endl;
            //cout<<u<<' '<<v<<' '<<d[u]<<' '<<d[v]<<endl;
            update(u  ,-d[u]);
            update(u+1,-d[u+1]);
            if (v!=u+1)
            update(v  ,-d[v]);
            if (v+1!=u)
            update(v+1,-d[v+1]);
            swap(c[u],c[v]);
            vt[c[u]]=u;
            vt[c[v]]=v;
            d[u  ]=((c[u]-c[u-1])<0);
            d[u+1]=((c[u+1]-c[u])<0);
            d[v  ]=((c[v]-c[v-1])<0);
            d[v+1]=((c[v+1]-c[v])<0);
            update(u,d[u]);
            update(u+1,d[u+1]);
            if (v!=u+1)
            update(v,d[v]);
            if (v+1!=u)
            update(v+1,d[v+1]);
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

