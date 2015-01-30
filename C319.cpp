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
const int maxn=100000+10;
struct line
{
    long long a,b;
}G[maxn];
long long a[maxn],b[maxn];
 long long  F[maxn],n,top,bot;


double Giao(line l1,line l2)
{
    //cout<<l1.a<<' '<<l1.b<<' '<<l2.a<<' '<<l2.b<<endl;
    //cout<<(l2.b-l1.b+0.0)/(l1.a-l2.a+0.0)<<endl;
     return (l2.b-l1.b+0.0)/(l1.a-l2.a+0.0);
}

line ml(long long a,long long b)
{
    line x;
    x.a=a;
    x.b=b;
    return x;
}

int main()
{
    //freopen("C319.inp","r",stdin);
    //freopen("C319.out","w",stdout);
    scanf("%d",&n);
    FOR(i,1,n)
        scanf("%d",&a[i]);
    FOR(i,1,n)
        scanf("%d",&b[i]);
    bot=1;top=1;
    F[1]=a[1]*b[1];
    G[bot]=ml(b[1],0);
    //cout<<G[bot].a<<' '<<G[bot].b<<endl;
    FOR(i,2,n)
    {
        while (top>=bot+1&&Giao(G[bot],G[bot+1])<=a[i])
            bot++;
        F[i]=G[bot].a*a[i]+G[bot].b;
        line l=ml(b[i],F[i]);
        while (top>=bot+1&&Giao(G[top-1],l)<=Giao(G[top-1],G[top])) top--;
        top++;
        G[top]=l;
    }
    cout<<F[n];
    fclose(stdin);
    fclose(stdout);
    return 0;
}

