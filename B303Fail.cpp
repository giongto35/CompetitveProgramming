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
int n,m,x,y,a,b,spx,spy;
double rx1,rx2,ry1,ry2,sa,sb;
long long dist(int x1,int y1,int x2,int y2)
{
    return (long long)(y1-y2)*(y1-y2)+(long long)(x1-x2)*(x1-x2);
}

int chia (int x,double y)
{
    int so=(int)(x+0.0)/y;
    if (so*y>(int)(so*y)) so-=1;
    return so;
}

void calc(double x,double y)
{
    int tx1;
    int ty1;
    int tx2;
    int ty2;
    double t=min(min(chia((n-x),sa),chia(x,sa)),min(chia((m-y),sb),chia(y,sb)));
    tx1=x-t*sa;
    tx2=x+t*sa;
    ty1=y-t*sb;
    ty2=y+t*sb;
    cout<<t<<' '<<x<<' '<<y<<' '<<sa<<' '<<sb<<' '<<tx1<<' '<<ty1<<' '<<tx2<<' '<<ty2<<endl;
    if (tx1-(int)tx1>0) tx1-=0.5,tx2-=0.5;
    if (ty1-(int)ty1>0) ty1+=0.5,ty2-=0.5;
    if (dist((rx1+rx2)/2,(ry1+ry2)/2,spx,spy)==dist((tx1+tx2)/2,(ty1+ty2)/2,spx,spy))
    {
        if (rx1>tx1||(rx1==tx1&&ry1>ty1))
        {
            rx1=tx1;rx2=tx2;ry1=ty1;ry2=ty2;
        }
    }
    else
    if (dist((rx1+rx2)/2,(ry1+ry2)/2,spx,spy)>dist((tx1+tx2)/2,(ty1+ty2)/2,spx,spy))
    {
        rx1=tx1;rx2=tx2;ry1=ty1;ry2=ty2;
    }
}

int main()
{
    freopen("B303.inp","r",stdin);
    //freopen("B303.out","w",stdout);
    cin>>n>>m>>x>>y>>a>>b;
    spx=x;
    spy=y;
    sa=(a+0.0)/2;
    sb=(b+0.0)/2;
    if (a%2==1) x=max(x,a/2+1);else x=max(x,a/2);
    if (b%2==1) y=max(y,b/2+1);else y=max(y,b/2);
    rx1=n;
    ry1=m;
    for(int i=-1;i<=1;i++)
    for(int j=-1;j<=1;j++)
    {
        if (x+i*(0.5)>=0&&x+i*(0.5)<=n&&y+j*(0.5)>=0&&y+j*(0.5)<=m)
        calc(x+i*(0.5),y+j*(0.5));
    }

    cout<<(int)rx1<<' '<<(int)ry1<<' '<<(int)rx2<<' '<<(int)ry2<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

