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

typedef pair<long double, long double> point;

inline int cmp1(const point a, const point b) { return make_pair(a.second, a.first) < make_pair(b.second, b.first); }
inline int cmp2(const point a, const point b) { return make_pair(a.second, a.first) > make_pair(b.second, b.first); }
long double res,l;
const int maxn=100+10;
vector<point> a;
int  n,st;
long double u,v;

inline long double Cross(point p1, point p2, point p3) {
    long double a1 = p2.first-p1.first;
    long double  b1 = p2.second-p1.second;
    long double a2 = p3.first-p2.first;
    long double b2 = p3.second-p2.second;
    return a1*b2 - a2*b1;
}

inline void getCover(vector<point> &a) {
    vector<point> ret; ret.clear();
    sort(a.begin(), a.end(), cmp1);
    ret.push_back(a[0]); ret.push_back(a[1]);
    for(int i = 2; i < a.size(); i++) {
        while (ret.size() > 1 && Cross(ret[ret.size()-2], ret[ret.size()-1], a[i]) < 0) ret.pop_back();
        ret.push_back(a[i]);
    }
    for(int i = a.size()-2; i >= 0; i--) {
        while (ret.size() > 1 && Cross(ret[ret.size()-2], ret[ret.size()-1], a[i]) < 0) ret.pop_back();
        ret.push_back(a[i]);
    }
    a = ret;
}


long double dist(point a,point b)
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
        a.clear();
        FOR(i,1,n)
        {
            cin>>u>>v;
            a.push_back(make_pair(u,v));
        }
        getCover(a);
        //if (j==3)
        //FOR(i,0,a.size()-1) cout<<a[i].first<<' '<<a[i].second<<endl;
        res=0;
        FOR(i,0,a.size()-2)
            res+=dist(a[i],a[i+1]);
        cout<<fixed<<setprecision(5)<<max(l,res)<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
