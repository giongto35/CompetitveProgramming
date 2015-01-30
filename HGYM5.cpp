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
#define mp(a,b) make_pair((a),(b))
#define RESET(c,x) memset (c, x, sizeof (c))
#define oo 1000111000
#define PI acos(-1.0)
#define fi first
#define se second
#define SIZE(c) (c).size()

typedef vector<int> VI ;
typedef vector<string> VS ;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;

template<class T> inline int size(const T&c) { return c.size(); }

using namespace std;
int fastMax(int x, int y) { return (((y-x)>>(32-1))&(x^y))^y; }
int fastMin(int x, int y) { return (((y-x)>>(32-1))&(x^y))^x; }

double s;
int m;
double p;

bool check(double s, double x)
{
    for (int i = 1; i <= m; i++)
    {
        double a = s * p;
        double b = x - a;
        //cout<<a<<' '<<b<<endl;
        if (b < 0) return false;
        s = s - b;
        if (s <= 0) return true;
    }
    if (s <= 0) return true; else return false;
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    cin>>s>>m>>p;
    p /= 100;
    double l = 0;
    double r = 1000000000;
    for (int i = 1; i <= 10000; i++)
    {
        double mid = (l + r) / 2;
        //cout<<l<<' '<<r<<endl;
        if (check(s,mid))
        {
            r = mid;
        }
        else
            l = mid;
    }
    printf("%.6f",l);
    fclose(stdin);
    fclose(stdout);
    return 0;
}

