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


const int maxn = 2000+10;
int a[maxn];
int b[maxn];
int res[maxn];
int T,n,sT;
set<long long int> lower[maxn];
int main()
{
    freopen("C-large-practice.in","r",stdin);
    freopen("CCJ2013.out","w",stdout);
    scanf("%d",&T);
    for (int sT = 1; sT <= T; sT++)
    {
        scanf("%d",&n);
        for (int i = 1; i <= n; i++) scanf("%d",&a[i]);
        for (int i = 1; i <= n; i++) scanf("%d",&b[i]);
        for (int i = 1; i <= n; i++) lower[i].clear();
        for (int i = 1; i <= n; i++)
        {
            for (int j = i - 1; j >= 1; j--)
            {
                if (a[i] == a[j])
                {
                    lower[j].insert(i);
                    break;
                }
            }
            for (int j = i - 1; j >= 1; j--)
            {
                if (a[i] == a[j] + 1)
                {
                    lower[i].insert(j);
                    break;
                }
            }
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = i + 1; j <= n; j++)
            {
                if (b[i] == b[j])
                {
                    lower[j].insert(i);
                    break;
                }
            }
            for (int j = i + 1; j <= n; j++)
            {
                if (b[i] == b[j] + 1)
                {
                    lower[i].insert(j);
                    break;
                }
            }
        }
        memset(res,-1,sizeof(res));
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (res[j] == -1 && lower[j].size() == 0)
                {
                    res[j] = i;
                    for(int k = 1; k <= n; k++)
                        lower[k].erase(j);
                    break;
                }
            }
        }
        cout<<"Case #"<<sT<<": ";
        for (int i = 1; i <= n; i++)
            cout<<res[i]<<' ';
        cout<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
