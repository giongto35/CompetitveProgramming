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

const int maxn = 2000+10;
const int eps = 0.000001;
double a[maxn];
double res;
int n;
int p[maxn];

double calc(int u,int v)
{
    if (u>v)
    {
        int tg=u;u=v;v=tg;
    }
    double gt1=a[u];
    double gt2=a[v];
    if (abs((int)gt1-gt1)>eps) gt1 = (int)gt1+1;else gt1=(int) gt1;
    gt2=(int)gt2;
    return a[u]+a[v]-gt1-gt2;
}
int main()
{
    freopen("A351.inp","r",stdin);
    //freopen("A351.out","w",stdout);
    cin>>n;
    n=n*2;
    FOR(i,1,n) cin>>a[i];
    sort(a+1,a+1+n);
    int spt=0;
    FOR(i,1,n/2) { p[++spt]=spt+1;p[++spt]=spt-1;res=res+calc(spt-1,spt);}
    //p[1]=4;p[4]=1;p[2]=3;p[3]=2;
    p[1]=3;p[3]=1;p[2]=4;p[4]=2;
    while (true)
    {
        bool ok=false;
        FOR(i,1,n)
        FOR(j,1,n)
        {
            if (i==j) continue;
            cout<<i<<' '<<p[i]<<' '<<j<<' '<<p[j]<<' '<<calc(i,p[i])+calc(j,p[j])<<' '<<calc(i,j)+calc(p[i],p[j])<<endl;
            if (abs(res)>abs(res-calc(i,p[i])-calc(j,p[j])+calc(i,j)+calc(p[i],p[j])))
                {
                    ok=true;
                    res=res-calc(i,p[i])-calc(j,p[j])+calc(i,j)+calc(p[i],p[j]);
                    int u=p[i];
                    int v=p[j];
                    p[i]=j;
                    p[j]=i;
                    p[u]=v;
                    p[v]=u;
                }
        }
        if (ok==false) break;
    }
    cout<<fixed<<setprecision(3)<<abs(res)<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

