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

typedef pair<double, double> point;

inline int cmp1(const point a, const point b) { return make_pair(a.second, a.first) < make_pair(b.second, b.first); }
inline int cmp2(const point a, const point b) { return make_pair(a.second, a.first) > make_pair(b.second, b.first); }
double res,l;
const int maxn=100+10;
point a[maxn];
vector<point> p;
int  n,u,v,st;

bool cpr(point a,point b)
{
    return (a.second<b.second)||((a.second==b.second)&&(a.first<b.first));
}

double multi(point p0,point p1,point p2)
{
    return (p1.first-p0.first)*(p2.second-p0.second)-(p2.first-p0.first)*(p1.second-p0.second);
}

bool check(int i)
{
    if (multi(p[p.size()-2],p[p.size()-1],a[i])>0) return true; else return false;
}

void ConvexHull()
{
    int i,lim;
    double RS;
    p.clear();
    sort(a+1,a+1+n,cpr);
    lim=0;

    FOR(i,1,n)
    {
        //cout<<a[i].first<<' '<<a[i].second<<' '<<p.size()<<' '<<lim<<' '<<p.size()-1<<' '<<lim<<endl;
        while ((int)p.size()-1>lim&&(!check(i))) p.pop_back();

        p.push_back(a[i]);
    }
    lim=p.size()-1;
    DOW(i,n,1)
    {
        while((int)p.size()-1>lim&&(!check(i))) p.pop_back();
        p.push_back(a[i]);
    }
}

double dist(point a,point b)
{
    return sqrt((a.first-b.first)*(a.first-b.first)+(a.second-b.second)*(a.second-b.second));
}

int main()
{
    //freopen("Amini10.inp.c","r",stdin);
    //freopen("Amini10.out","w",stdout);
    cin>>st;
    FOR(j,1,st)
    {
        cin>>l>>n;
        FOR(i,1,n)
        {
            cin>>a[i].first>>a[i].second;
        }
        ConvexHull();
        res=0;
        //cout<<p.size()<<endl;
        //FOR(i,0,p.size()-1)
        FOR(i,0,p.size()-2)
        {
            //cout<<" "<<p[i].first<<' '<<p[i].second<<endl;
            //cout<<res<<endl;
            res+=dist(p[i],p[i+1]);
        }
        cout<<fixed<<setprecision(5)<<max(l,res)<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

