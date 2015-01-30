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
#include <iomanip>
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
const int oo=1000000000;
const long double pi=acos((long double)-1.0);
const int maxn=50+10;
const double eps=0.000001;
int n;
double res,sres;

struct point
{
    double x,y;
    point(){x=y=0.0;}
    point(double x,double y) : x(x),y(y){}
    point rotate(double alpha)
    {
        double cosa=cos(alpha),sina=sin(alpha);
        return point(x*cosa-y*sina,x*sina+y*cosa);
    }
}a[maxn],b[maxn],c[maxn];
double S;
const int nalpha=50;
const int nturn=35;
int spt;

void extract(point p1,point p2,double &a, double &b, double &c)
{
    a=p1.y-p2.y;
    b=p2.x-p1.x;
    c=-(a*p1.x+b*p1.y);
}

bool intersect(double x1,double y1,double x2,double y2,double x3,double y3,double x4,double y4,double &x,double &y)
{
    double a1,b1,c1,a2,b2,c2;
    extract(point(x1,y1),point(x2,y2),a1,b1,c1);
    extract(point(x3,y3),point(x4,y4),a2,b2,c2);
    double D=a1*b2-a2*b1;
    double Dx=b1*c2-b2*c1;
    double Dy=c1*a2-c2*a1;
    if (D==0) return false;
    y=Dy/D;
    x=Dx/D;
    if (abs(x3-x)<=eps&&abs(y3-y)<=eps) return false;
    if (abs(x4-x)<=eps&&abs(y4-y)<=eps) return false;
    if ((min(y3,y4)<=y)&&(y<=max(y3,y4))&&(min(x3,x4)<=x)&&(x<=max(x3,x4))) return true; else return false;

}

double area()
{
    c[spt+1]=c[1];
    double S=0;
    FOR(i,1,spt)
        S+=c[i].y*c[i+1].x-c[i].x*c[i+1].y;
    S=abs(S)/2;
    return S;
}

double calc(double splity)
{
    double x1=oo;
    double x2=-oo;
    spt=0;
    FOR(i,1,n)
    {
        double x;
        double y;
        if (intersect(0,splity,1,splity,b[i].x,b[i].y,b[i+1].x,b[i+1].y,x,y))
        {
            if (b[i].y>splity) c[++spt]=b[i],c[++spt]=point(x,y);
            else
            if (b[i].y<splity) c[++spt]=point(x,y);
        }
        else
        if (b[i].y+eps>splity)
            c[++spt]=b[i];
    }
    //cout<<"   "<<x1<<' '<<x2<<' '<<splity<<endl;
    //cout<<"   "<<spt<<endl;
    //cout<<spt<<' ';
    //c[1]=point(x2,splity);
    //c[++spt]=point(x1,splity);
    FOR(i,1,spt)
    {
        if (abs(c[i].y-splity)<=eps)
        {
            x1=min(x1,c[i].x);
            x2=max(x2,c[i].x);
        }
    }
    res=x2-x1;
    return area();
}

double solve(double ang)
{
        double miny=oo;
        double maxy=-oo;
        FOR(k,1,n)
        {
            b[k]=a[k].rotate(ang);
            miny=min(miny,b[k].y);
            maxy=max(maxy,b[k].y);
        }
        b[n+1]=b[1];
        double l=miny;
        double r=maxy;
        FOR(k,1,nturn)
        {
            double m=(l+r)/2;
            if (calc(m)*2<S)
                r=m;
            else
                l=m;
        }
        calc(l);
        return res;
}

int main()
{
    //freopen("chocolate.inp.c","r",stdin);
    //freopen("chocolate.out","w",stdout);
    cin>>n;
    FOR(i,1,n)
        cin>>a[i].x>>a[i].y;
    FOR(i,1,n) c[i]=a[i];
    spt=n;
    S=area();
    sres=oo;/*
    FOR(i,1,n)
    FOR(j,1,n)

    {
        if (i==j) continue;
        double ang=-atan2(a[j].y-a[i].y,a[j].x-a[i].x);
        sres=min(sres,solve(ang));
    }*/
    FOR(i,1,nalpha)
    {
        double l=pi/nalpha*i;double r=pi/nalpha*(i+1);
        sres = min(sres, min(solve(l), solve(r)));
        FOR(j,1,nturn)
        {
                double x1 = (l*2 + r) / 3.0;
                double x2 = (l + r*2) / 3.0;
                double y1 = solve(x1), y2 = solve(x2);
                sres = min(sres, min(y1, y2));
                if (y1 > y2) r = x2;
                else l = x1;
            }


        l=pi/nalpha*i; r=pi/nalpha*(i+1);
        sres = min(sres, min(solve(l), solve(r)));
        FOR(j,1,nturn)
        {
                double x1 = (l*2 + r) / 3.0;
                double x2 = (l + r*2) / 3.0;
                double y1 = solve(x1), y2 = solve(x2);
                sres = min(sres, min(y1, y2));
                if (y1 < y2) r = x2;
                else l = x1;
            }
    }
    cout<<fixed<<setprecision(6)<<sres;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

