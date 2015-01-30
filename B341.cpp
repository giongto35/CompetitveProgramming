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
int F[maxn];
int res;
int n;
int BIT[maxn];

void update(int i,int gt)
{
    if (i==0) return ;
    while (i<=n)
    {
        BIT[i]=max(BIT[i],gt);
        i=i+(i & (-i));
    }
}


int get(int i)
{
    int gt=0;
    while (i>=1)
    {
        gt=max(BIT[i],gt);
        i=i-(i & (-i));
    }
    return gt;
}

int main()
{
    //freopen("B341.inp","r",stdin);
    //freopen("B341.out","w",stdout);
    scanf("%d",&n);
    FOR(i,1,n)
    cin>>a[i];
    FOR(i,1,n)
    {
        F[i]=get(a[i]-1)+1;
        update(a[i],F[i]);
        res=max(res,F[i]);
    }
    cout<<res<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

