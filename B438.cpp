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
pair<int,int> c[maxn];
vector<int> a[maxn];
int lab[maxn];
long long res;
bool used[maxn];
int n,m,u,v;

int getroot(int u)
{
    if (lab[u] < 0) return u;
    else
    {
        lab[u] = getroot(lab[u]);
        return lab[u];
    }
}

int main()
{
    //freopen("B438.inp","r",stdin);
    //freopen("","w",stdout);
    scanf("%d%d",&n,&m);
    for (int i =1 ; i <= n; i++)
    {
        scanf("%d",&c[i].first);
        c[i].second = i;
    }
    for (int i = 1; i <= m; i++)
    {
        scanf("%d%d",&u,&v);
        a[u].push_back(v);
        a[v].push_back(u);
    }
    sort(c+1,c+1+n,greater<pair<int,int> >()) ;
    for (int i = 1; i <= n; i++) lab[i] = -1;
    for (int i = 1; i <= n; i++)
    {
        int u = c[i].second;
        used[u] = true;
        long long sum = 0;
        for (int j = 0; j < a[u].size(); j++)
        {
            int v = a[u][j];
            if (used[v] == false) continue;
            int r1 = getroot(u);
            int r2 = getroot(v);
            if (r1 != r2)
            {
                //cout<<u<<' '<<v<<' '<<(-lab[r1])<<' '<<c[i].first<<endl;
                res = res + (long long)(-lab[r1]) * (-lab[r2]) * c[i].first;
                lab[r1] += lab[r2];
                lab[r2] = r1;
            }
        }
    }
    double r = res;
    r = r / ((long long)n * (n-1));
    printf("%0.4f",r*2);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
