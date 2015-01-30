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
const int maxn = 100000+10;
const double eps = 0.00000001;

#define PI 3.14159265
struct point
{
    int x;
    int y;
} a[maxn];
double b[maxn],goc,res;
int n,m;

bool mycmp(point a,point b)
{
//    return a.x*b.y>a.y*b.x;
    return atan2(a.y,a.x)+eps<atan2(b.y,b.x);
}

bool equalang(point a,point b)
{
//    return a.x*b.y==a.y*b.x;
    if (abs(atan2(a.y,a.x)-atan2(b.y,b.x))<=eps) return true; else return false;
}

double ch(double a,double b)
{
    if (a<b) return a+2*PI-b;
    else return a-b;
}

int main()
{
    //freopen("C257.inp","r",stdin);
    //freopen("C257.out","w",stdout);
    cin>>n;
    FOR (i,1,n)
    scanf("%d%d",&a[i].x,&a[i].y);
//    FOR (i,1,n) cout<<a[i].x<<' '<<a[i].y<<endl;
    sort(a+1,a+n+1,mycmp);
//    FOR (i,1,n) cout<<' '<<a[i].x<<' '<<a[i].y<<endl;
    m=0;
    b[++m]=atan2(a[1].y,a[1].x);
    FOR (i,2,n)
        if (!equalang(a[i],a[i-1])) b[++m]=atan2(a[i].y,a[i].x);
    //FOR (i,1,m) cout<<b[i] * 180/PI<<endl;
    if (m==1) printf("0.0000000000");
    else
    if (m==2)
    {
        goc=ch(b[2],b[1]) * 180/PI;
        if (goc>360-goc) goc=360-goc;
        printf("%.6lf",goc);
    }
    else
    {
        b[++m]=b[1];
        res=1000000;
        FOR(i,1,m-1)
        {
            goc=ch(b[i+1],b[i]) * 180/PI;
            //cout<<goc<<endl;
            res=min(res,360-goc);
        }
        printf("%.6lf",res);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

