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

const int maxn = 1000000+10;
map<int,int> d[maxn];
int l[maxn];
int r[maxn];
int l2[maxn];
int r2[maxn];
int p[maxn];
int b[maxn];
int n;
int res;
int cnt;
int seg[maxn];
int lmax[maxn];
int rmax[maxn];
string st;

int sum(int i)
{
    int res=0;
    i++;
    while (i>0)
    {
        res+=b[i];
        i-=i&(-i);
    }
    return res;
}

void update(int i,int gt)
{
    i++;
    while (i<=n)
    {
        b[i]+=gt;
        i+=i&(-i);
    }
}

int getleft(int u)
{
    if (l[u]==u) return u;
    l[u]=getleft(l[u]);
    return l[u];
}

int getright(int u)
{
    if (r[u]==u) return u;
    r[u]=getright(r[u]);
    return r[u];
}

int getleft2(int u)
{
    if (l2[u]==u) return u;
    l2[u]=getleft2(l2[u]);
    return l2[u];
}

int getright2(int u)
{
    if (r2[u]==u) return u;
    r2[u]=getright2(r2[u]);
    return r2[u];
}

bool mycmp(int u,int v)
{
    return (r[u]-l[u]+n)%n<(r[v]-l[v]+n)%n;
}

void xoa(int i)
{
    //cout<<i<<endl;
            if (lmax[i]<rmax[i])
            {
                update(lmax[i],1);
                update(rmax[i]+1,-1);
            }
            else
            {
                update(lmax[i],1);
                update(n,-1);
                update(0,1);
                update(rmax[i]+1,-1);
            }
}

int main()
{
    //freopen("E353.inp","r",stdin);
    //freopen("E353.out","w",stdout);
    getline(cin,st);
    n=st.length();
    FOR(i,0,n-1) r[i]=l[i]=r2[i]=l2[i]=i;
    FOR(i,0,n-1)
    {
        cnt+=(st[i]=='1');
        if (st[i]=='0')
        {
            r[i]=(i+1)%n;
            l2[(i+1)%n]=i;
        }
        else
        {
            l[(i+1)%n]=i;
            r2[i]=(i+1)%n;
        }
    }
    FOR(i,0,n-1)
    {
        l[i]=getleft(l[i]),r[i]=getright(r[i]);
        l2[i]=getleft2(l2[i]),r2[i]=getright2(r2[i]);
        p[i]=i;
    }
    FOR(i,0,n-1)
    {
        if (l[i]==i) lmax[i]=l2[i];else lmax[i]=l[i];
        if (r[i]==i) rmax[i]=r2[i];else rmax[i]=r[i];
    }
    FOR(i,0,n-1)
    {
        //cout<<i<<' '<<l[i]<<' '<<r2[i]<<' '<<' '<<l2[i]<<' '<<r[i]<<endl;
        if (l[i]!=i&&r2[i]!=i&&sum(i)==0) res++,xoa(i);
        if (l2[i]!=i&&r[i]!=i&&sum(i)==0) res++,xoa(i);
    }
    FOR(i,0,n-1)
    {
        if (sum(i)==0) res++,xoa(i);
    }
    /*
    sort(p,p+n,mycmp);
    FOR(i,0,n-1) cout<<p[i]<<' '<<l[p[i]]<<' '<<r[p[i]]<<endl;
    //return 0;
    FOR(i,0,n-1)
    {
        if (sum(p[i])==0)
        {
            res++;
        }
    }
    */
    //FOR(i,0,n-1) if (sum[i]==0) cout<<"SAI"<<endl;
    cout<<res<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

