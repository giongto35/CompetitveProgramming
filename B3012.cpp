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
const int maxn=200+10;
int n,d;
int a[maxn];
struct point
{
    int x;
    int y;
    int c;
    int t;
}p[maxn],tg;
int F[maxn],spt;
const int oo=1000000000;

bool mycmp( point a, point b)
{
    return (a.y<b.y||(a.y==b.y&&a.x<b.x));
}
int main()
{
    freopen("B301.inp","r",stdin);
    //freopen("B301.out","w",stdout);
    cin>>n>>d;
    FOR(i,2,n-1) cin>>a[i];
    FOR(i,1,n)
    {
        cin>>p[i].x>>p[i].y;
        p[i].c=a[i];
    }
    if (p[1].y>p[n].y) FOR(i,1,n) p[i].y=-p[i].y;
    if (p[1].x>p[n].x) FOR(i,1,n) p[i].x=-p[i].x;
/*    spt=0;
    FOR(i,1,n)
        if (p[i].y>=p[1].y&&p[i].y<=p[n].y&&p[i].x>=p[1].x&&p[i].x<=p[n].x)
            c[++spt]=p[i];
    n=spt;
    sort(c+1,c+1+n,mycmp);
    */
    //cout<<c[1].x<<' '<<c[1].y<<endl;
    //cout<<c[spt].x<<' '<<c[spt].y<<endl;
    p[1].t=1;
    p[n].t=n;
    sort(p+1,p+1+n,mycmp);
    int s,t;
    FOR(i,1,n)
    {
        if (p[i].t==1) s=i;
        if (p[i].t==n) t=i;
    }
    FOR(i,1,n)
    cout<<p[i].x<<' '<<p[i].y<<' '<<p[i].c<<endl;
    cout<<endl;
    cout<<p[s].x<<' '<<p[s].y<<endl;
    cout<<p[t].x<<' '<<p[t].y<<endl;

    FOR(i,1,n) F[i]=-oo;
    F[s]=0;
    cout<<s<<' '<<t<<' '<<n<<endl;
    FOR(i,2,n)
    {
        FOR(j,1,i-1)
        {
            if (p[j].x<=p[i].x&&p[j].y<=p[i].y)
                F[i]=max(F[i],F[j]+p[i].c);
        }
    }
    cout<<F[t]<<endl;
    //cout<<p[s]<<' '<<p[t]<<end;
    cout<<(abs(p[t].y-p[s].y)+abs(p[t].x-p[s].x))*d-F[t];
    fclose(stdin);
    fclose(stdout);
    return 0;
}


