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
}p[maxn],c[maxn],tg;
int F[maxn],spt;
const int oo=1000000000;

bool mycmp( point a, point b)
{
    if (p[1].x<p[n].x)
    {
        return (a.y<b.y||(a.y==b.y&&a.x<b.x));
    }
    else
    {
        return (a.y<b.y||(a.y==b.y&&a.x>b.x));
    }
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
    if (p[1].y>p[n].y)
    {
        tg=p[1];
        p[1]=p[n];
        p[n]=tg;
    }
    spt=0;
    FOR(i,1,n)
    {
        if (p[1].x<=p[n].x)
        {
            if (p[i].y>=p[1].y&&p[i].y<=p[n].y&&p[i].x>=p[1].x&&p[i].x<=p[n].x)
                c[++spt]=p[i];
        }
        else
        {
            if (p[i].y>=p[1].y&&p[i].y<=p[n].y&&p[i].x<=p[1].x&&p[i].x>=p[n].x)
                c[++spt]=p[i];
        }
    }
    //cout<<p[1].x<<' '<<p[1].y<<endl;
    //cout<<p[n].x<<' '<<p[n].y<<endl;
    //cout<<c[1].x<<' '<<c[1].y<<endl;
    //cout<<c[spt].x<<' '<<c[spt].y<<endl;
    n=spt;
    FOR(i,1,n) F[i]=-oo;
    F[1]=0;
    sort(c+1,c+1+n,mycmp);
    //cout<<c[1].x<<' '<<c[1].y<<endl;
    //cout<<c[spt].x<<' '<<c[spt].y<<endl;
    FOR(i,2,n)
    {
        FOR(j,1,i-1)
        {
            if (c[j].y>c[i].y) continue;
            if (c[1].x<=c[n].x)
            {
                if (c[j].x<=c[i].x)
                    F[i]=max(F[i],F[j]+c[i].c);
            }
            else
            {
                if (c[j].x>=c[i].x)
                    F[i]=max(F[i],F[j]+c[i].c);
            }
        }
    }
    //cout<<F[n]<<endl;
    cout<<(abs(c[n].y-c[1].y)+abs(c[n].x-c[1].x))*d-F[n];
    fclose(stdin);
    fclose(stdout);
    return 0;
}


