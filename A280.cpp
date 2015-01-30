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
double w,h,a;
struct point
{
    double x;
    double y;
} p[100];
struct line
{
    point p1;
    point p2;
} l[10];
const double pi = 3.14159265359;
const int eps =0.000000001;
int spt;
double nx,ny;
double res;
int ns;
point s[100];

point mp(double x,double y)
{
    point c;
    c.x=x;
    c.y=y;
    return c;
}

line ml(point p1,point p2)
{
    line l;
    l.p1=p1;
    l.p2=p2;
    return l;
}

point xoay(point p)
{
    point c;
    c.x=p.x*cos( a )-p.y*sin( a );
    c.y=p.x*sin( a )+p.y*cos( a );
    return c;
}


void extract(point p1,point p2,double &a,double &b,double &c)
{
    a=p1.y-p2.y;
    b=p2.x-p1.x;
    c=-(a*p1.x+b*p1.y);
}

bool intersect(double x1,double y1,double x2,double y2,double x3,double y3,double x4,double y4,double &x,double &y)
{
    double a1,b1,c1,a2,b2,c2;
    double D,Dx,Dy;
    extract(mp(x1,y1),mp(x2,y2),a1,b1,c1);
    extract(mp(x3,y3),mp(x4,y4),a2,b2,c2);
    D =a1*b2-a2*b1;
    Dx=b1*c2-b2*c1;
    Dy=c1*a2-c2*a1;
    if (D==0) return false;
    y=Dy/D;
    x=Dx/D;
    if (min(y3,y4)-eps<=y&&y<=max(y3,y4)+eps&&min(x3,x4)-eps<=x&&x<=max(x3,x4)+eps) return true; else return false;
}

bool mycmp(point u,point v)
{
    if (u.y*v.y<0) return u.y>v.y;
    return u.x*v.y>v.x*u.y;
}

double calc()
{
    s[++ns]=s[1];
    double ret=0;
    //FOR(i,1,ns-1) cout<<s[i].x<<' '<<s[i].y<<endl;
    //cout<<endl;
    FOR(i,2,ns) ret += (s[i].x-s[i-1].x) * (s[i].y + s[i-1].y);
    return abs(ret/2);
}

int main()
{
    //freopen("A280.inp","r",stdin);
    //freopen("A280.out","w",stdout);
    cin>>w>>h>>a;
    if (a<=eps||abs(a-180)==0)
    {
        printf("%0.6f",w*h);
        return 0;
    }
    a=a*pi/180;
    p[0]=mp(-w/2,h/2);
    p[1]=mp(w/2,h/2);
    p[2]=mp(w/2,-h/2);
    p[3]=mp(-w/2,-h/2);
    p[4]=xoay(p[0]);
    p[5]=xoay(p[1]);
    p[6]=xoay(p[2]);
    p[7]=xoay(p[3]);
    //cout<<p[4].x<<' '<<p[4].y<<endl;
    //cout<<p[5].x<<' '<<p[5].y<<endl;
    //cout<<p[6].x<<' '<<p[6].y<<endl;
    //cout<<p[7].x<<' '<<p[7].y<<endl;
    //return 0;

    l[0]=ml(p[0],p[1]);
    l[1]=ml(p[1],p[2]);
    l[2]=ml(p[2],p[3]);
    l[3]=ml(p[3],p[0]);

    l[4]=ml(p[4],p[5]);
    l[5]=ml(p[5],p[6]);
    l[6]=ml(p[6],p[7]);
    l[7]=ml(p[7],p[4]);
    spt=7;
    FOR(i,0,3)
    FOR(j,4,7)
    {
        if (intersect(l[i].p1.x,l[i].p1.y,l[i].p2.x,l[i].p2.y,l[j].p1.x,l[j].p1.y,l[j].p2.x,l[j ].p2.y,nx,ny))
        {
            p[++spt]=mp(nx,ny);
        }
    }
    sort(p,p+spt+1,mycmp);
    //FOR(i,0,spt) cout<<p[i].x<<' '<<p[i].y<<endl;
    //cout<<endl;
        res=1000000000100;
    if (spt==11)
    {
        ns=0;
        s[++ns]=p[1];
        s[++ns]=p[4];
        s[++ns]=p[7];
        s[++ns]=p[10];
        res=min(res,calc());
        ns=0;
        s[++ns]=p[2];
        s[++ns]=p[5];
        s[++ns]=p[8];
        s[++ns]=p[11];
        res=min(res,calc());
        ns=0;
        s[++ns]=p[0];
        s[++ns]=p[3];
        s[++ns]=p[6];
        s[++ns]=p[9];
        res=min(res,calc());
    }
    else
    {
        ns=0;
        s[++ns]=p[1];
        s[++ns]=p[3];
        s[++ns]=p[5];
        s[++ns]=p[7];
        s[++ns]=p[9];
        s[++ns]=p[11];
        s[++ns]=p[13];
        s[++ns]=p[15];
        res=min(res,calc());
        ns=0;
        s[++ns]=p[0];
        s[++ns]=p[2];
        s[++ns]=p[4];
        s[++ns]=p[6];
        s[++ns]=p[8];
        s[++ns]=p[10];
        s[++ns]=p[12];
        s[++ns]=p[14];
        res=min(res,calc());

    }
        printf("%0.6f",res);
    fclose(stdin);
    fclose(stdout);
    return 0;
}

