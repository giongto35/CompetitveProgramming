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
int top;
int a[maxn];
int c[maxn];
int tr[maxn];
int F[maxn];
int o[maxn];
int n;
vector<int> res;

void trace(int u)
{
    if (u == 0) return;
    trace(tr[u]);
    res.push_back(u);
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    scanf("%d",&n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d",&a[i]);
    }

    top = 0;a[top]=-123123;
    for (int i = 1; i <= n; i++)
    {
        if (a[i]!=a[top])
        {
            a[++top] = a[i];
            c[top] = 1;
        }
        else
        {
            c[top] = c[top] + 1;
        }
    }
    n = top;
    for (int i = 1; i <= n + 1; i++)
    {
        F[i] = oo;
    }
    a[0] = -12312412;
    a[n+1] = 52363463;
    F[0] = 0;
    for (int i = 1; i <= n+1; i++)
    {
        int sum = 0;
        for (int k = 1; k <= 50; k++)
        {
            if (i - k >= 0 && abs(a[i] - a[i-k]) != 1 && F[i-k] < oo)
            {/*
                if (i == 4)
                {
                    cout<<i<<' '<<i-k<<' '<<sum<<' '<<F[i-k]<<endl;
                }*/
                if (F[i] > F[i-k] + sum)
                {
                    F[i] = F[i-k] + sum;
                    tr[i] = i - k;
                }
            }
            sum += c[i-k];
        }
    }
    printf("%d\n", F[n+1]);
    trace(n+1);
    for (int i = 0; i < res.size(); i++)
    {
        //cout<<i<<' '<<res[i]<<endl;
        for (int j = 0; j < c[res[i]]; j++)
        printf("%d ", a[res[i]]);
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}

