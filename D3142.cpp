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
const int maxn=100000+10;
const int oo=1000000000+10;
int xmin,xmax,ymin,ymax;
struct point
{
    int x;
    int y;
} a[maxn];
int n;
int res;

void rot(int &x,int &y)
{
    //int nx=x*cos(goc)-y*sin(goc);
    //int ny=y*cos(goc)+x*sin(goc);
    //x=nx;
    //y=ny;
    int nx=x-y;
    int ny=x+y;
    x=nx;
    y=ny;
}

bool mycmp(point a,point b)
{
    return (a.x<b.x)||((a.x==b.x)&&(a.y<b.y));
}

multiset<int> smin;
multiset<int> smax;

bool check(int v)
{
    smin.clear();
    smax.clear();
    FOR(i,1,n)
    {
        smin.insert(a[i].y);
        smax.insert(-a[i].y);
    }
    int j=1;
    FOR(i,1,n)
    {
        smin.erase(smin.find(a[i].y));
        smax.erase(smax.find(-a[i].y));
        while (a[j].x<(long long)a[i].x-v*2)
        {
            smin.insert(a[j].y);
            smax.insert(-a[j].y);
            j++;
        }
        long long ymax=-*(smax.begin());
        long long ymin=*(smin.begin());
        //cout<<ymax<<' '<<ymin<<' '<<v<<endl;
        if (ymax-ymin<=v*2) return true;
    }
    return false;
}

int main()
{
    //freopen("D314.inp","r",stdin);
    //freopen("D314.out","w",stdout);
    cin>>n;
    ymin=oo;
    ymax=-oo;
    xmin=oo;
    xmax=-oo;
    FOR(i,1,n)
    {
        cin>>a[i].x>>a[i].y;
        rot(a[i].x,a[i].y);
        //a[i].x*=2;
        //a[i].y*=2;
    }
    sort(a+1,a+1+n,mycmp);
    int l=0;
    int r=1000000000;
    while (l<=r)
    {
        int mid = (l+r)/2;
        if (check(mid))
        {
            res=mid;
            r=mid-1;
        }
        else
        {
            l=mid+1;
        }
    }
    cout<<fixed<<setprecision(5)<<res<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

