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
struct query
{
    int l,r,vt;
} temp;
vector<query> q[maxn];
vector<int> vt[maxn];
int res[maxn];
int BIT[maxn];
int l,r,k,sq,n,a[maxn];
void update(int i,int gt)
{
    if (i==0) return;
    while (i<=n)
    {
        BIT[i]=BIT[i]+gt;
        i=i+(i & (-i));
    }
}


int get(int i)
{
    int gt=0;
    while (i>=1)
    {
        gt=BIT[i]+gt;
        i=i-(i & (-i));
    }
    return gt;
}

int main()
{
    //freopen("DIVQUERY.inp","r",stdin);
    //freopen("DIVQUERY.out","w",stdout);
    scanf("%d%d",&n,&sq);
    FOR(i,1,n)
    {
        scanf("%d",&a[i]);
        vt[a[i]].push_back(i);
    }
    FOR(i,1,sq)
    {
        scanf("%d%d%d",&l,&r,&k);
        temp.l=l;
        temp.r=r;
        temp.vt=i;
        q[k].push_back(temp);
    }
    FOR(i,1,100000)
    {
        if (q[i].size()>0)
        {
            //cout<<i<<endl;
            for(int j=0;j<=100000;j=j+i) FOR(k,0,vt[j].size()-1) update(vt[j][k],1);
            FOR(j,0,q[i].size()-1) res[q[i][j].vt]=get(q[i][j].r)-get(q[i][j].l-1);
            for(int j=0;j<=100000;j=j+i) FOR(k,0,vt[j].size()-1) update(vt[j][k],-1);
        }
    }
    FOR(i,1,sq) cout<<res[i]<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

