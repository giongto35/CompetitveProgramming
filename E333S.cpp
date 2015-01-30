#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <iomanip>
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
const double pi = atan(1)*4;
const int maxn=6000+10;
const double eps =0.0000001;
struct point
{
    int y,x,idx;
    double ang;
}a[maxn];
struct p2
{
    int idx;
    double ang;
}c[maxn];
double res;
double l,r,m,n;
int con;
double d[maxn/2][maxn/2];

double dist(point u,point v)
{
    return sqrt((u.x-v.x)*(u.x-v.x)+(u.y-v.y)*(u.y-v.y));
}

//bool mycmp(point a,point b)
//{
//    return a.y*b.x<a.x*b.y;
//}
inline bool mycmp(p2 a,p2 b)
{
    //return a.y*b.x<a.x*b.y;
    return a.ang<b.ang;
}

bool check(double v)
{
    FOR(i,1,n)
    {
        int spt=0;
        FOR(j,1,n) if (j!=i&&d[i][j]>=v*2)
        {
            spt++;
            //c[spt].y=a[j].y-a[i].y,c[spt].x=a[j].x-a[i].x;
            c[spt].ang=atan2(a[j].y-a[i].y,a[j].x-a[i].x),c[spt].idx=j;
            if (c[spt].ang<0) c[spt].ang+=2*pi;
        }
        //cout<<spt<<endl;
        sort(c+1,c+1+spt,mycmp);
        FOR(j,spt+1,spt+spt)
        {
            c[j]=c[j-spt];
            c[j].ang=c[j].ang+2*pi;
        }
        //FOR(j,1,spt+spt) cout<<j<<' '<<c[j].y<<' '<<c[j].x<<' '<<c[j].ang<<endl;
        int k=1;

        FOR(j,2,spt+spt)
        {
            while (k<j-1&&c[j].ang-c[k].ang>pi) k++;
            //cout<<j<<' '<<k<<endl;
            FOR(l,max(1,k-3),min(j-1,k+3))
            {
                //cout<<c[l].idx<<' '<<c[j].idx<<' '<<d[c[l].idx][c[j].idx]<<endl;
                if (d[c[l].idx][c[j].idx]>=v*2) return true;
            }
        }
    }
    return false;
}

int main()
{
    //freopen("E333.inp","r",stdin);
    //freopen("E333.out","w",stdout);
    cin>>n;
    FOR(i,1,n)
    //cin>>a[i].x>>a[i].y;
    {
        scanf("%d%d",&a[i].x,&a[i].y);
    }
    FOR(i,1,n) FOR(j,1,n) d[i][j]=dist(a[i],a[j]);
    l=0;r=10000;
    //while (l+eps<=r)
    FOR(i,1,40)
    {
        double m=(l+r)/2;
        //cout<<l<<' '<<m<<' '<<r<<endl;
        if (check(m))
        {
            res=m;
            l=m;
        }
        else
            r=m;
    }
    cout<<fixed<<setprecision(6)<<res<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

