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

const int maxn = 100000;
int a[maxn],n;
long long res;
long long sum;
vector<int> b;
vector<int> s;

int main()
{
    //freopen("B440.inp","r",stdin);
    //freopen("","w",stdout);
    scanf("%d",&n);
    for (int i = 1;  i <= n; i++)
    {
        scanf("%d",&a[i]);
        sum+=a[i];
    }
    sum /= n;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] > sum) b.push_back(i);
        if (a[i] < sum) s.push_back(i);
    }
    int j = 0;
    for (int i = 0; i < b.size(); i++)
    {
        while (a[s[j]] < sum)
        {
            int v = min(a[b[i]] - sum, sum - a[s[j]]);
            res += (long long)v*(abs(b[i] - s[j]));
            a[b[i]] -= v;
            a[s[j]] += v;
            if (a[s[j]] == sum) j++;
            else break;
            if (a[b[i]] == sum) break;
        }
    }
    cout<<res<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

