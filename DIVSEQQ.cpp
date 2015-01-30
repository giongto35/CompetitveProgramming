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
#define fi first
#define se second

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
int l[maxn][20],n,m,q,x,u,v;
long long s[maxn];
int main()
{
    //freopen("DIVSEQQ.inp","r",stdin);
    //freopen("DIVSEQQ.out","w",stdout);
    scanf("%d%d%d",&n,&q,&m);
    FOR(i,1,n)
    {
        scanf("%d",&a[i]);
        s[i]=s[i-1]+a[i];
    }
    x=1;
    FOR(i,1,n)
    {
        while (s[i]-s[x-1]>m) x++;
        l[i][0]=x-1;
    }
    FOR(i,1,n)
        FOR(j,1,log2(i))
            l[i][j]=l[l[i][j-1]][j-1];

    FOR(i,1,q)
    {
        scanf("%d%d",&u,&v);
        DOW(j,log2(n),0)
            if (v>=(1<<j)) {v-=(1<<j);u=l[u][j];}
        printf("%d\n",u+1);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

