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
    double l;
    double ang;
}c[maxn];
double res;
double l,r,m,n;
int con;
double d[maxn/2][maxn/2];
struct cmp
{
  bool operator()(const p2 u, const p2 v) const
  {
    return (u.l>v.l)||(u.l==v.l&&u.ang<v.ang);
  }
};

multiset<p2,cmp> s;

double dist(point u,point v)
{
    return sqrt((u.x-v.x)*(u.x-v.x)+(u.y-v.y)*(u.y-v.y));
}

inline bool mycmp(p2 a,p2 b)
{
    //return a.y*b.x<a.x*b.y;
    return a.ang<b.ang;
}

void process()
{
    //cout<<pi/3<<endl;
    FOR(i,1,n)
    {
        //cout<<i<<endl;
        int spt=0;
        FOR(j,1,n) if (j!=i)
        {
            spt++;
            c[spt].ang=atan2(a[j].y-a[i].y,a[j].x-a[i].x),c[spt].l=d[i][j];
            if (c[spt].ang<0) c[spt].ang+=2*pi;
        }
        sort(c+1,c+1+spt,mycmp);
        FOR(j,spt+1,spt+spt)
        {
            c[j]=c[j-spt];
            c[j].ang=c[j].ang+2*pi;
        }
        int k=1;
        int bd=1;
        //s.clear();
        while (bd<=spt&&c[bd].ang-c[k].ang<pi/3) bd++;
        FOR(j,bd,spt+spt)
        {
            while (k<=j-1&&c[j].ang-c[k].ang>=pi/3)
            {
                s.insert(c[k]);
                k++;
            }
            double l;
            while (s.size()>0&&c[j].ang-(*s.begin()).ang>pi) s.erase(s.begin());

            if (s.size()>0) res=max(res,min((*s.begin()).l,c[j].l));
            s.erase(c[j]);
            if (k>spt) break;
        }
    }
}

int main()
{
    freopen("E333.inp","r",stdin);
    //freopen("E333.out","w",stdout);
    cin>>n;
    FOR(i,1,n)
    //cin>>a[i].x>>a[i].y;
    {
        scanf("%d%d",&a[i].x,&a[i].y);
    }
    FOR(i,1,n) FOR(j,1,n) d[i][j]=dist(a[i],a[j]);
    process();
    cout<<fixed<<setprecision(6)<<res/2<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

