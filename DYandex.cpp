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
int maxso;
int BIT[maxn];
int n;
int w[maxn];
int h[maxn];

void update(int i,int gt)//change long long
{
    while (i<=maxso)
    {
        BIT[i]=min(BIT[i],gt);
        i=i+(i & (-i));
    }
}


int get(int i)
{
    int gt=1000000000;//change long long
    while (i>=1)
    {
        gt=min(BIT[i],gt);
        i=i-(i & (-i));
    }
    return gt;
}

void roirachoa()
{
    vector<int> b(w+1,w+n+1);
    sort(b.begin(),b.end());
    vector<int>::iterator it = unique(b.begin(),b.end());
    b.resize(distance(b.begin(),it));
    maxso = b.size();
    for (int i = 1; i <= n; i++)
        w[i] = lower_bound(b.begin(),b.end(),w[i]) - b.begin() + 1;
}

int main()
{
    //freopen("Dyandex.inp","r",stdin);
    //freopen("Dyandex.out","w",stdout);
    scanf("%d",&n);

    for (int i = 1; i <= n; i++)
    {
        scanf("%d%d",&w[i],&h[i]);
    }
    roirachoa();
    for (int i = 1; i <= maxso; i++)
    BIT[i] = 1000000000+10;
    for (int i = 1; i <= n; i++)
    {
        if (get(w[i]) <= h[i])
        {
            cout<<"Invisible paper detected"<<endl;
            return 0;
        }
        update(w[i],h[i]);
    }
    cout<<"Well done"<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

