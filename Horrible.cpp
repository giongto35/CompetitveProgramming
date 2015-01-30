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
int T;
int N,C;
long long B1[maxn];
long long B2[maxn];
int com,u,v,gt;

void update(long long B[], int u, long long gt)
{
    if ( u <= 0) return;
    for( int i = u; i <= N; i += (i & (-i))) B[i] = B[i] + gt;
}

long long sum(long long B[], int u)
{
    long long res = 0;
    for( int i = u; i >= 1; i -= (i & (-i))) res += B[i];
    return res;
}

long long get(int u)
{
    return sum(B1,u) * u - sum(B2,u);
}

long long get_range(int u,int v)
{
    return get(v) - get(u - 1);
}

void update_range(int u,int v,int gt)
{
    update(B1,u,gt);
    update(B1,v+1,-gt);
    update(B2,u,(long long)gt*(u-1));
    update(B2,v + 1,(-(long long)gt) * v);
}

int main()
{
    //freopen("Horrible.inp","r",stdin);
    //freopen("Horrible.out","w",stdout);
    scanf("%d",&T);
    FOR(sT,1,T)
    {
        scanf("%d%d",&N,&C);
        memset(B1,0,sizeof(B1));
        memset(B2,0,sizeof(B2));

        FOR(i,1,C){
            scanf("%d",&com);
            if (com == 0)
            {
                scanf("%d%d%d",&u,&v,&gt);
                update_range(u,v,gt);
            }
            else
            {
                scanf("%d%d",&u,&v);
                printf("%lld\n",get_range(u,v));
            }
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

