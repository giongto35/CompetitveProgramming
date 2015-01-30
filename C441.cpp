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
#include <conio.h>
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

int n,m,k;
bool r[400][400];
pair<int,int> p;
vector<pair<int,int> > res[400*400];

pair<int,int> next(int y, int x)
{
    if (r[y][x-1] == false && r[y][x+1] == false)
        return (make_pair(y+1,x));
    else
    if (r[y][x-1] == true)
        return (make_pair(y,x-1));
    else
    if (r[y][x+1] == true)
        return (make_pair(y,x+1));
}
int main()
{
    //freopen("C441.inp","r",stdin);
    //freopen("C441.out","w",stdout);
    scanf("%d%d%d",&n,&m,&k);
    for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) r[i][j] = true;
    int y = 1;
    int x = 1;
    int cnt = 0;
    for (int i = 1; i <= k; i++)
    {
        r[y][x] = false;
        res[i].push_back(make_pair(y,x));
        p = next(y,x);
        y = p.first;
        x = p.second;
        r[y][x] = false;
        res[i].push_back(make_pair(y,x));
        p = next(y,x);
        y = p.first;
        x = p.second;
        cnt+=2;
    }
    while (cnt<n*m)
    {
        cnt++;
        r[y][x] = false;
        res[k].push_back(make_pair(y,x));
        p = next(y,x);
        y = p.first;
        x = p.second;
    }
    for (int i = 1; i <= k; i++)
    {
        printf("%d ",res[i].size() );
        for (int j = 0 ; j < res[i].size(); j++)
        {
            printf("%d %d ",res[i][j].first,res[i][j].second);
        }
        printf("\n");
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

