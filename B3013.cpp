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
using namespace std ;

#define FOREACH(it,c) for( __typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define FOR(i,a,b) for( int i=(a),_b=(b);i<=_b;i++)
#define DOW(i,b,a) for( int i=(b),_a=(a);i>=_a;i--)
#define REP(i,n) FOR(i,0,(n)-1)
#define DEP(i,n) DOW(i,(n)-1,0)
#define all(a) (a).begin() , (a).end()
#define push(a,b) (a).push_back((b))

typedef vector<int> VI ;
typedef vector<string> VS ;
template<class T> inline int size(const T&c) { return c.size(); }

using namespace std;
const int maxn=200+10;
int n,d;
int a[maxn];
struct point
{
    int x;
    int y;
    int c;
    int t;
}p[maxn],tg;
int F[maxn],spt;
bool used[maxn];
int tr[maxn];
const int oo=1000000000;

void trace(int i)
{
    cout<<i<<' '<<p[i].x<<' '<<p[i].y<<' '<<p[i].c<<endl;
    if (i==1) return;
    trace(tr[i]);
}
void dijkstra()
{
    FOR(i,1,n) F[i]=oo;
    F[1]=0;
    FOR(i,1,n) used[i]=true;
    //cout<<n<<endl;
    while(true)
    {
        int u=0;
        FOR(i,1,n)
        {
            if (used[i]==true)
            {
                if (u==0||F[u]>F[i])
                    u=i;
            }
        }
        //cout<<u<<endl;
        used[u]=false;
        if (u==n||u==0) break;
        FOR(v,1,n)
        {
            if (used[v]==true&&F[v]>F[u]+(abs(p[u].x-p[v].x)+abs(p[u].y-p[v].y))*d-p[v].c)

                {
                    F[v]=F[u]+(abs(p[u].x-p[v].x)+abs(p[u].y-p[v].y))*d-p[v].c;
                    tr[v]=u;
                }
        }
        //cout<<u<<endl;
        //FOR(i,1,n) cout<<F[i]<<' ';
        //cout<<endl;
    }
    cout<<F[n]<<endl;
    trace(n);
}
int main()
{
    freopen("B301.inp","r",stdin);
    //freopen("B301.out","w",stdout);
    cin>>n>>d;
    FOR(i,2,n-1) cin>>a[i];
    FOR(i,1,n)
    {
        cin>>p[i].x>>p[i].y;
        p[i].c=a[i];
    }
    dijkstra();
    fclose(stdin);
    fclose(stdout);
    return 0;
}


