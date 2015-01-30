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

const int oo=1000000000;
using namespace std;
const double pi=3.14159265359;
const int maxn=100+10;
struct point
{
    double x;
    double y;
} a[maxn],b[maxn];
double resmin,resmax;
int n;
const double eps=0.000000001;

void rot(double goc)
{
    goc=pi/2;
    //cout<<goc<<' '<<cos(goc)<<' '<<sin(goc)<<endl;
    FOR(j,0,n+1)
        {
            b[j].x=a[j].x*cos(goc)-a[j].y*sin(goc);
            b[j].y=a[j].y*cos(goc)+a[j].x*sin(goc);
            //cout<<a[j].x<<' '<<a[j].y<<' '<<b[j].x<<' '<<b[j].y<<' '<<a[j].x*cos(goc)-a[j].y*sin(goc)<<' '<<a[j].y*cos(goc)+a[j].x*sin(goc)<<endl;
        }
}

double calc(double goc)
{
    double nx,ny;
    double xmin,xmax,ymin,ymax;
    xmin=oo;
    xmax=-oo;
    ymin=oo;
    ymax=-oo;
    //cout<<goc<<endl;
    FOR(j,1,n)
        {
            nx=b[j].x*cos(goc)-b[j].y*sin(goc);
            ny=b[j].y*cos(goc)+b[j].x*sin(goc);
            //cout<<"  "<<setprecision(5)<<a[j].x<<' '<<a[j].y<<' '<<nx<<' '<<ny<<endl;
            xmin=min(xmin,nx);
            xmax=max(xmax,nx);
            ymin=min(ymin,ny);
            ymax=max(ymax,ny);
        }
        //cout<<xmin<<' '<<xmax<<' '<<ymin<<' '<<ymax<<endl;
    return (xmax-xmin)+(ymax-ymin);
}

double calc2(double goc)
{
    double nx,ny;
    double ymin,ymax;
    ymin=oo;
    ymax=-oo;
    //cout<<goc<<endl;
    FOR(j,1,n)
        {
            nx=b[j].x*cos(goc)-b[j].y*sin(goc);
            ny=b[j].y*cos(goc)+b[j].x*sin(goc);
            //cout<<"  "<<setprecision(5)<<a[j].x<<' '<<a[j].y<<' '<<nx<<' '<<ny<<endl;
            ymin=min(ymin,ny);
            ymax=max(ymax,ny);
        }
        //cout<<xmin<<' '<<xmax<<' '<<ymin<<' '<<ymax<<endl;
    return (ymax-ymin);
}

void cmp(double ang)
{
    resmin=min(resmin,ang);
    resmax=max(resmax,ang);
}

double ternarysearch(double left,double right)
{
    double lt,rt;
    double l,r;
        l=left;
        r=right;
        while (l+eps<=r)
        {

          lt=(2*l+r) / 3;
          rt=(l+2*r) / 3;
          if (calc(lt)<calc(rt))
          l=lt;
          else
          r=rt;
        }
    return calc(l);
}

double searchmaxheigh(double left,double right)
{
    double lt,rt;
    double l,r;
        l=left;
        r=right;
        while (l+eps<=r)
        {

          lt=(2*l+r) / 3;
          rt=(l+2*r) / 3;
          if (calc2(lt)<calc2(rt))
          l=lt;
          else
          r=rt;
        }
    return l;
}


int main()
{
    //freopen("1.in","r",stdin);
    //freopen("kppoly.out","w",stdout);
    cin>>n;
    FOR(i,1,n)
        cin>>a[i].x>>a[i].y;
    a[0]=a[n];
    a[n+1]=a[1];
    resmin=oo;
    resmax=-oo;
    FOR(i,1,n)
    {
        double goc=atan2(a[i+1].y-a[i].y,a[i+1].x-a[i].x);
        goc=pi-goc;
        FOR(j,0,n+1) b[j]=a[j];
        cmp(calc(goc));

        rot(goc);
        //cout<<goc<<endl;
        //FOR(j,1,n) cout<<a[j].x<<' '<<a[j].y<<' ';cout<<endl;
        //FOR(j,1,n) cout<<b[j].x<<' '<<b[j].y<<' ';cout<<endl;
        goc=atan2(b[i-1].y-b[i].y,b[i-1].x-b[i].x);
        double sgoc=searchmaxheigh(-goc,0);
        //cout<<i<<' '<<i+1<<' '<<-goc<<' '<<sgoc<<endl;

        cmp(ternarysearch(-goc,sgoc));
        cmp(ternarysearch(sgoc,0));
    }
    cout<<fixed<<setprecision(6)<<resmin<<' '<<resmax<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}


