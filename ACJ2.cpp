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

const int maxn = 10000+10;
int n;
bool used[maxn];
int res;
int T,X;
int a[maxn];
int main()
{
    freopen("A-large.in","r",stdin);
    freopen("ACJ22.out","w",stdout);
    scanf("%d",&T);
    for (int sT = 1; sT <= T; sT++)
    {
        scanf("%d%d",&n,&X);
        for (int i = 1; i <= n; i++)
            scanf("%d",&a[i]);
        sort(a+1,a+1+n,greater<int>());
        memset(used,false,sizeof(used));
        res = 0;
        for (int i = 1; i <= n; i++)
        {
            if (used[i] == true) continue;
            for (int j = i+1; j <= n; j++)
            {
                if (used[i] == false && used[j] == false && a[i] + a[j] <= X)
                {
                    used[i] = true;
                    used[j] = true;

                    res ++;
                    break;
                }
            }
            if (used[i] == false)
            {
                used[i] = true;
                res++;
            }
        }
        cout<<"Case #"<<sT<<": "<<res<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

