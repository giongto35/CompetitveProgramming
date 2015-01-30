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

const int maxn = 3000+10;
int a[maxn];
int b[maxn];
bool c[maxn];
int lab[maxn];
int cnt,n,m,res,com;
int cur;
set<int> s[maxn];
vector<pair<int,int> > r;

int getroot(int u)
{
    if (lab[u] == 0) return u;
    lab[u] = getroot(lab[u]);
    return lab[u];
}

void rec(int u)
{
    int r1 = getroot(u);
    int r2 = getroot(a[u]);
    s[com].insert(u);
    c[u] = true;
    cnt++;
    if (r1 == r2) return;
    else
    {
        lab[r2] =r1;
        rec(a[u]);
    }
}

int main()
{
    //freopen("D441.inp","r",stdin);
    //freopen("D441.out","w",stdout);
    scanf("%d",&n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d",&a[i]);
        b[a[i]] = i;
    }
    scanf("%d",&m);
    com = 0;
    memset(c,false,sizeof(c));
    for (int i = 1; i <= n; i++)
        if (c[i] == false)
        {
            com++;
            cnt = 0;
            rec(i);
            res += cnt - 1;
        }
    if (res < m)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = i+1; j <= n; j++)
            {
                int r1 = getroot(i);
                int r2 = getroot(j);
                if (r1 != r2)
                {
                    lab[r2] = r1;
                    r.push_back(make_pair(i,j));
                    res++;
                    if (res == m) break;
                }
            }
            if (res == m) break;
        }
    }
    else
    {
        for (int cc = res; cc > m; cc--)
        {
            com = 0;
            memset(c,false,sizeof(c));
            memset(lab,0,sizeof(lab));
            for (int i = 1; i <= n; i++)
                if (c[i] == false)
                {
                    com++;
                    cnt = 0;
                    s[com].clear();
                    rec(i);
                    res += cnt - 1;
                }
            pair<int,int> tz = make_pair(n+1,n+1);
            for (int i = 1; i <= com; i++)
            {
                if (s[i].size()>=2)
                {
                    set<int>::iterator it = s[i].begin();
                    int u = *it;
                    it++;
                    int v = *it;
                    pair<int,int> p(min(u,v),max(u,v));
                    if (tz > p)
                        tz = p;
                }
            }
            r.push_back(tz);
            swap(a[tz.first],a[tz.second]);
        }
    }
    cout<<r.size()<<endl;
    for (int i = 0 ; i < r.size(); i++)
    {
        printf("%d %d ",min(r[i].first,r[i].second),max(r[i].first,r[i].second));
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
