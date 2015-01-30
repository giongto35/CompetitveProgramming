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
pair<int,int> a[maxn];
vector<pair<int,int> > res;
int n;
bool ok;

bool mygreater(pair<int,int> u, pair<int,int> v)
{
    if (u.first == v.first)
    {
        return u.second > v.second;
    }
    else
    return u.first > v.first;
}
int main()
{
    //freopen("Cyandex.inp","r",stdin);
    //freopen("Cyandex.out","w",stdout);
    scanf("%d",&n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d%d",&a[i].first,&a[i].second);
        if (a[i].first<a[i].second)
        {
            swap(a[i].first,a[i].second);
        }
    }
    sort(a+1,a+1+n,mygreater);
    ok = true;
    res.clear();
    for (int i = 1; i <= n; i++)
    {
        if (i > 1 && a[i].first == a[i-1].first && a[i].second == a[i-1].second)
        {
            swap(a[i].first,a[i].second);
            ok = false;
        }
        else
            res.push_back(make_pair(a[i].first,a[i].second));
    }
    if (ok == true)
    {
        for (int i = 0 ; i < res.size(); i++)
            printf("%d %d\n",res[i].first,res[i].second);
    }
    else
    {
        res.clear();
        sort(a+1,a+1+n,mygreater);
        for (int i = 1; i <= n; i++)
        {
            if (i > 1 && a[i].first == a[i-1].first && a[i].second == a[i-1].second)
            {
                cout<<"Chaos";
                return 0;
            }
            else
                res.push_back(make_pair(a[i].first,a[i].second));
        }
        for (int i = 0 ; i < res.size(); i++)
            printf("%d %d\n",res[i].first,res[i].second);

    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

