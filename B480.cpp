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
map<int,bool> ma;
map<int,bool> ma1;
map<int,bool> ma2;
int l,x,y,n;
bool ok1,ok2;

int main()
{
    freopen("B480.inp","r",stdin);
    //freopen("","w",stdout);
    scanf("%d%d%d%d",&n,&l,&x,&y);
    ma.clear();
    for (int i = 1; i <= n; i++)
    {
        scanf("%d",&a[i]);
        if (a[i] >= x && ma[a[i] - x])
            ok1 = true;
        if (a[i] >= y && ma[a[i] - y])
            ok2 = true;
        ma[a[i]]= true;
        if (a[i] >= x)
            ma1[a[i] - x] = true;
        if (a[i] + x <= l)
            ma1[a[i] + x] = true;
        if (a[i] >= y)
            ma2[a[i] - y] = true;
        if (a[i] + y <= l)
            ma2[a[i] + y] = true;

    }
    if (ok1 && ok2)
    {
        cout<<0;
    }
    else
    if (ok1 || ok2)
    {
        if (ok1)
        {
            cout<<1<<endl;
            cout<<y;
        }
        if (ok2)
        {
            cout<<1<<endl;
            cout<<x<<endl;
        }
    }
    else
    {
        FOREACH(it, ma2)
        {
            //cout<<(*it).first<<' '<<(*it).second<<endl;
            int u = (*it).first;
            if (ma1[u] && ma2[u])
            {
                cout<<1<<endl;
                cout<<u<<endl;
                return 0;
            }
        }
        cout<<2<<endl;
        cout<<x<<' '<<y<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

