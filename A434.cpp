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

const int maxn = 100000+10;
int a[maxn];
vector<int> c[maxn];
long long sum;
long long res;
int n,m;

int main()
{
    freopen("A434.inp","r",stdin);
    //freopen("A434.out","w",stdout);
    scanf("%d%d",&n,&m);
    for (int i = 1; i <= m; i++)
    {
        scanf("%d",&a[i]);
        if (i > 1)
        {
            c[a[i]].push_back(a[i-1]);
            c[a[i-1]].push_back(a[i]);
            sum += abs((long long)a[i] - a[i-1]);
        }
    }
    res = sum;
    for (int i = 1; i <= n; i++)
    {
        if (c[i].size()>0){
        sort(c[i].begin(),c[i].end());
        long long old = 0;
        long long news = 0;
        long long median = c[i][c[i].size() /2];
        for (int j = 0; j < c[i].size(); j++)
            old += abs(i - c[i][j]);
        for (int j = 0; j < c[i].size(); j++)
            news += abs(median - c[i][j]);
        res = min(res, sum - old + news);
        }
    }
    cout<<res<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

