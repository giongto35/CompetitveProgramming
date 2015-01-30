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
int a[maxn];
int com;
int l,r,n,q;
int lleft, rright;
int BIT[maxn];
int rev;

void update(int i,int gt)//change long long
{
    while (i<=n)
    {
        BIT[i]=BIT[i] + gt;
        i=i+(i & (-i));
    }
}


int get(int i)//change long long
{
    int gt=0;//change long long
    while (i>=1)
    {
        gt=BIT[i] + gt;
        i=i-(i & (-i));
    }
    return gt;
}

int get2(int l, int r)
{
    return get(r) - get(l);
}

int main()
{
    //freopen("C461.inp","r",stdin);
    //8freopen("C461.out","w",stdout);
    scanf("%d%d",&n,&q);
    memset(BIT,0,sizeof(BIT));
    rev = 0;
    lleft = 1;
    rright = n;
    for (int i = 1; i <= n; i++)
    {
        a[i] = 1;
        update(i,1);
    }
    for (int i = 1; i <= q; i++)
    {
        scanf("%d", &com);
        if (com == 1)
        {
            scanf("%d",&l);
            if (l * 2 > rright-lleft + 1)
            {
                rev = 1 - rev;
                l = rright - lleft + 1 - l;
            }
            if (rev == 0)
            {
                int cen = lleft + l - 1;
                for (int j = 1; j <= l; j++)
                {
                    a[j+cen] += a[cen-j+1];
                    update(j + cen,a[cen-j+1]);
                }
                lleft = cen + 1;
            }
            else
            {
                int cen = rright - l + 1;
                for (int j = 1; j <= l; j++)
                {
                    a[cen-j] += a[j+cen-1];
                    update(cen - j, a[j+cen-1]);
                }
                rright = cen - 1;
            }
            //for (int i = lleft; i <= rright; i++) cout<<a[i]<<' ';
            //cout<<endl;
        }
        else
        if (com == 2)
        {
            scanf("%d %d",&l,&r);
            if (rev == 0)
            {
                l = lleft + l - 1;
                r = lleft + r - 1;
            }
            else
            {
                l = rright - l;
                r = rright - r;
                swap(l,r);
            }
            //for (int k = 1; k <= n; k++) cout<<a[k]<<' ';cout<<endl;
            //cout<<n<<' '<<l<<' '<<r<<' '<<n - r <<' '<<n - l<<endl;
            //cout<<lleft<<' '<<rright<<' '<<rev<<' '<<l<<' '<<r<<endl;
            cout<<get2(l,r)<<endl;
        }
    }
    //cout<<get(n)<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

