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

double a[200];
vector<double> b;
double res;
int n;

double calc()
{
    if (b.size() == 1) return b[0];
    double temp = 1;
    for (int i = 0; i < b.size(); i++)
        temp = temp * (1 - b[i]);
    double r = 0;
    for (int i = 0; i < b.size(); i++)
    {
        r = r + temp * b[i] / (1 - b[i]);
    }
    return r;
}
int main()
{
    //freopen("B442.inp","r",stdin);
    //freopen("","w",stdout);
    scanf("%d",&n);
    for (int i = 1; i <= n; i++)
        cin>>a[i];
    sort(a+1,a+1+n);
    for (int i = 0; i <= n; i ++)
    for (int j = n+1; j > i; j--)
    {
        b.clear();
        for (int k =1 ; k <= i; k++) b.push_back(a[k]);
        for (int k =j+1 ; k <= n; k++) b.push_back(a[k]);
        res = max(res,calc());
    }
    printf("%.9f",res);
    //cout<<res<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

