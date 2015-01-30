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

const int maxn = 100+10;
int n;
string st;
int res;
pair<int,int> a[maxn],c[maxn];
int cnt[10][10];
int cnt2[10][10];
bool used[maxn];

bool check(int b, int b2)
{
    int dem = 0;
    for (int i = 1; i <= n; i++)
    {
        if ((b >> (a[i].first-1)) & 1) c[i].first = a[i].first;
        if ((b2>> (a[i].second-1)) & 1) c[i].second = a[i].second;
        if (c[i].first == 0 && c[i].second == 0) dem++;
        if (c[i].first != 0 && c[i].second != 0)
        {
            for (int j = 1; j <= n; j++)
                if (used[j] == false && c[i].first == a[j].first && c[i].second == a[j].second)
                    used[j] = true;
        }
    }
    if (dem > 1) return false;

    for (int i = 1; i <= n; i++)
    {
        dem = 0;
        int vt = 0;
        for (int j = 1; j <= n; j++)
            if (used[j] == false &&
                (c[i].first == a[j].first && c[i].second == 0) ||
                (c[i].first == 0 && c[i].second == a[j].second) )
                {
                    vt = j;
                    dem++;
                }
        if (dem > 1) return false;
        used[vt] = true;
    }
    return true;

}
int main()
{
    freopen("A442.inp","r",stdin);
    //freopen("","w",stdout);
    scanf("%d",&n);
    for (int i = 1; i <= n; i++)
    {
        cin>>st;
        if (st[0] == 'R') a[i].first = 1;
        if (st[0] == 'G') a[i].first = 2;
        if (st[0] == 'B') a[i].first = 3;
        if (st[0] == 'Y') a[i].first = 4;
        if (st[0] == 'W') a[i].first = 5;
        a[i].second = st[1] - '0';
        cnt2[a[i].first][a[i].second]++;
    }
    res = 10;
    for (int b = 0; b <= (1<<5)-1; b++)
    for (int b2 = 0; b2 <=(1<<5)-1;b2++)
    {
        memset(c,0,sizeof(c));
        memset(used,false,sizeof(used));
        if (check(b,b2))
            res = min(res, __builtin_popcount(b) + __builtin_popcount(b2));
    }
    cout<<res<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

