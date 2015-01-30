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
pair<int,int> a[maxn];
const double pi=3.14159265359;
struct point
{
    int x;
    int y;
} c[maxn];
int n,m;
int my;
long long random()
{
    return (long long)rand()*rand();
}

bool mycmp(pair<int,int> u,pair<int,int> v)
{
    if (u.first*v.first<0) return u.first>v.first;
    return u.first*v.second>v.first*u.second;
}

int main()
{
    //freopen("B277.inp","r",stdin);
    //freopen("nkpoli.out","w",stdout);
    cin>>n>>m;
        if (m==3&&(n==5||n==6))
        {
            cout<<-1;
            return 0;
        }
    int x=0;
    int y=0;

    FOR(i,1,m-1)
    {
        a[i].first=random()%10000-5000;
        a[i].second=random()%10000-5000;
        y+=a[i].first;
        x+=a[i].second;
    }
    a[m].first=-y;
    a[m].second=-x;
    sort(a+1,a+1+m,mycmp);
    x=0;
    y=0;
    my=0;
    double ang = 2*pi/m;
    FOR(i,1,m)
    {
        y+=a[i].first;
        x+=a[i].second;
        my=max(my,y);
        c[i].y=sin(i*ang)*1000000;
        c[i].x=cos(i*ang)*1000000;
    }
    //FOR(i,1,m) c[i].y=c[i].y-my/2;

    if (m==4&&(n==8||n==7))
        {
            cout<<10<<' '<<10<<endl;
            cout<<10<<' '<<-10<<endl;
            cout<<-10<<' '<<10<<endl;
            cout<<-10<<' '<<-10<<endl;
            cout<<100+2<<' '<<100-1<<endl;
            cout<<100-1<<' '<<-100-2<<endl;
            cout<<-100+1<<' '<<100+2<<endl;
            if (n==8)
            cout<<-100-2<<' '<<-100+1<<endl;
            return 0;
        }

    FOR(i,m+1,n)
    {
        c[i].x=c[i-m].x*10;
        c[i].y=c[i-m].y*10;
    }
    while(true)
    {
        bool change=false;
    FOR(i,1,n)
    FOR(j,1,n)
    FOR(k,1,n)
    {
        if (i!=j&&i!=k&&j!=k)
        {
            if ((c[j].x-c[i].x)*(c[k].y-c[i].y)==(c[j].y-c[i].y)*(c[k].x-c[i].x))
            {
                c[j].x+=rand()%6-3;
                c[j].y+=rand()%6-3;
                c[k].x+=rand()%6-3;
                c[k].y+=rand()%6-3;
                change=true;
            }
        }
    }
        if (change==false) break;
    }
    FOR(i,1,n) cout<<c[i].x<<' '<<c[i].y<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

