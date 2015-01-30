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
#define push(a,b) (a).push_back((b))

typedef vector<int> VI ;
typedef vector<string> VS ;
template<class T> inline int size(const T&c) { return c.size(); }

using namespace std;
const int maxn=1000+10;
const double pi=3.14159265359;
const int oo =1000000000;
struct point
{
    int x;
    int y;
} a[maxn],b[maxn];
int T,n,m;
const double eps=0.00000001;

bool check(point a[maxn],point b[maxn],int n,int m)
{
    double nx,ny;
    double xmin1,xmax1,xmin2,xmax2;
    a[n+1]=a[1];
    FOR(i,1,n)
    {
        //cout<<a[i+1].x<<' '<<a[i+1].y<<' '<<a[i].x<<' '<<a[i].y<<endl;
        double goc=atan2(a[i+1].y-a[i].y,a[i+1].x-a[i].x);
        //cout<<goc<<endl;
        goc=pi/2-goc;
        xmin1=oo;
        xmax1=-oo;
        xmin2=oo;
        xmax2=-oo;
        FOR(j,1,n)
        {
            nx=a[j].x*cos(goc)-a[j].y*sin(goc);
            ny=a[j].y*cos(goc)+a[j].x*sin(goc);
            //cout<<setprecision(5)<<a[j].x<<' '<<a[j].y<<' '<<nx<<' '<<ny<<endl;
            xmin1=min(xmin1,nx);
            xmax1=max(xmax1,nx);
        }

        FOR(j,1,m)
        {
            nx=b[j].x*cos(goc)-b[j].y*sin(goc);
            ny=b[j].y*cos(goc)+b[j].x*sin(goc);
            //cout<<setprecision(5)<<b[j].x<<' '<<b[j].y<<' '<<nx<<' '<<ny<<endl;
            xmin2=min(xmin2,nx);
            xmax2=max(xmax2,nx);
        }
        //cout<<xmin1<<' '<<xmax1<<' '<<xmin2<<' '<<xmax2<<endl;
        double l=max(xmin1,xmin2);
        double r=min(xmax1,xmax2);
        //cout<<l<<' '<<r<<endl;
        if (l-r>=eps) return true;
        //cout<<endl;
    }
    return false;
}
int main()
{
    //freopen("NKLAND.inp","r",stdin);
    //freopen("NKLAND.out","w",stdout);
    cin>>T;
    //cout<<atan2(13,0)<<endl;
    FOR(i,1,T)
    {
        cin>>n;
        FOR(i,1,n) cin>>a[i].x>>a[i].y;
        cin>>m;
        FOR(i,1,m) cin>>b[i].x>>b[i].y;
        if (check(a,b,n,m))//||check(b,a,m,n))
            cout<<"NO"<<endl;
        else
            cout<<"YES"<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

