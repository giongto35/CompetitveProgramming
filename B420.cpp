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
const int maxn = 300000;
const int c = 149000;
int a[maxn];
char com;
int u;
bool t[maxn];
int ok[maxn];
int bf;
int cnt;
set<int> s;
int n,m;
vector<int> res;
int sumtime;
int ti[maxn];
int bd;

int main()
{
    //freopen("B420.inp","r",stdin);
    //freopen("B420.out","w",stdout);
    scanf("%d%d\n",&n,&m);
    bf = c+1;
    for (int i = 1; i <= m; i++)
    {
        scanf("%c%d\n",&com,&u);
        //cout<<com<<' '
        if (com == '-'){
            if (t[u]==false)
            {
                a[--bf] = +u;
            }
            a[c + i] = -u;
            t[u] = false;
        }
        else
        {
            a[c + i] = u;
            t[u] = true;
        }
    }
    for (int i = 1; i <= n; i++)
        ok[i] = 0;
    for (int i = bf; i <= c + m; i++)
    {
        if (a[i] > 0)
        {
            if (s.size() > 0) ok[abs(a[i])] = 2;
            else
            {
                bd = abs(a[i]);
                ok[bd] = 1;
            }
            s.insert(abs(a[i]));
        }
        else
        {
            s.erase(abs(a[i]));
            if (s.size() > 0) ok[abs(a[i])] = 2;
        }
        if (s.size() > 0)
        {
            sumtime ++;
            ti[bd] ++;
        }
    }

    for (int i = 1; i <= n; i++)
        if (ok[i] == 0 || (ok[i] == 1 && ti[i] == sumtime)) res.push_back(i);
    cout<<res.size()<<endl;
    FOREACH(it,res)
        printf("%d ",(*it));

    fclose(stdin);
    fclose(stdout);
    return 0;
}

