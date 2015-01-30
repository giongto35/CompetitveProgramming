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

const int maxn = 2000+10;
double res;
double sres;
int L,W,n;
int a[maxn];
int p[maxn];

double calc(int u, int v)
{
    return min(u + sqrt(v * v + W * W), v + sqrt(u * u + W * W));
}

int tinh(int u, int v)
{
    if (u == 1 || v == 1)
    {
        return calc(a[u], a[v]);
    }
    if (u == n || v == n)
    {
        return calc(L - a[u], L - a[v]);
    }
    return sqrt(W * W + (a[u] - a[v]) * (a[u] - a[v]));
}
int main()
{
    freopen("AGYM3.inp","r",stdin);
    //freopen("","w",stdout);
    scanf("%d",&n);
    scanf("%d%d",&L,&W);
    for (int i = 1; i <= n; i++)
        scanf("%d",&a[i]);
    sort(a + 1, a + 1 + n);
    for (int i = 1; i <= n; i+= 2)
    {
        p[i] = i + 1;
        p[i + 1] = i;
    }
    for (int i = 1; i <= n; i += 2)
    {
        if (i == 1)
        {
            res = res + calc(a[1], a[2]);
        }
        else
        if (i == n -1)
        {
            res = res + calc(L - a[n], L - a[n-1]);
        }
        else
        {
            res = res + sqrt(W * W + (a[i+1] - a[i]) * (a[i+1] - a[i]));
        }
    }
    //for (int i = 1; i <= n; i++) cout<<p[i]<<' ';cout<<endl;
    while (true)
    {
        bool found = false;
        for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            if (i != j && p[i] != j)
            {
                if (tinh(i, p[i]) + tinh (j, p[j]) > tinh(i, p[j]) + tinh (j, p[i]))
                {
                    res = res - (tinh(i, p[i]) + tinh (j, p[j])) + tinh(i, p[j]) + tinh (j, p[i]);
                    swap(p[i], p[j]);
                    p[p[i]] = i;
                    p[p[j]] = j;
                    found = true;
                }
            }
        }
        if (found == false) break;
    }
    //for (int i = 1; i <= n; i++) cout<<p[i]<<' ';
    printf("%0.6f",res);
    fclose(stdin);
    fclose(stdout);
    return 0;
}

