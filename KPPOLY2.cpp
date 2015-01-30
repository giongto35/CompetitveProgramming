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
    int x;
    int y;
} a[maxn];
double resmin,resmax;
int n;
void process(double goc)
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
            nx=a[j].x*cos(goc)-a[j].y*sin(goc);
            ny=a[j].y*cos(goc)+a[j].x*sin(goc);
            //cout<<"  "<<setprecision(5)<<a[j].x<<' '<<a[j].y<<' '<<nx<<' '<<ny<<endl;
            xmin=min(xmin,nx);
            xmax=max(xmax,nx);
            ymin=min(ymin,ny);
            ymax=max(ymax,ny);
        }
        //cout<<xmin<<' '<<xmax<<' '<<ymin<<' '<<ymax<<endl;
    resmin=min(resmin,(xmax-xmin)+(ymax-ymin));
    resmax=max(resmax,(xmax-xmin)+(ymax-ymin));
}

int main()
{
    freopen("2.in","r",stdin);
    //freopen("kppoly.out","w",stdout);
    cin>>n;
    FOR(i,1,n)
        cin>>a[i].x>>a[i].y;
    a[n+1]=a[1];
    resmin=oo;
    resmax=-oo;
    FOR(i,1,n)
    {
        double goc=atan2(a[i+1].y-a[i].y,a[i+1].x-a[i].x);
        goc=0-goc;
        process(goc);
    }
    FOR(i,1,n)
    FOR(j,1,n)
    {
        if (i==j) continue;
        double goc=atan2(a[i].y-a[j].y,a[i].x-a[j].x);
        process(0-goc);
        process(pi/2-goc);
        process(pi-goc);
        process(2*pi/3-goc);
    }
    cout<<fixed<<setprecision(6)<<resmin<<' '<<resmax<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

