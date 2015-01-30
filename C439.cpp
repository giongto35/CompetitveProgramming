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
vector<int> odd;
vector<int> even;
vector<int> res[maxn];
int n,k,p;

int main()
{
    //freopen("C439.inp","r",stdin);
    //freopen("","w",stdout);
    scanf("%d%d%d",&n,&k,&p);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d",&a[i]);
        if (a[i] % 2 == 0) even.push_back(i);
        else odd.push_back(i);
    }
    for (int i = 1; i <= k; i++)
    {
        if (i <= k - p)
        {
            if (odd.size() > 0)
            {
                res[i].push_back(odd.back());
                odd.pop_back();
            }
            else
            {
                cout<<"NO";
                return 0;
            }
        }
        if (i > k - p)
        {
            if (even.size() > 0)
            {
                res[i].push_back(even.back());
                even.pop_back();
            }
            else
            {
                if (odd.size() > 1)
                {
                    res[i].push_back(odd.back());
                    odd.pop_back();
                    res[i].push_back(odd.back());
                    odd.pop_back();
                }
                else
                {
                    cout<<"NO";
                    return 0;
                }
            }
        }
    }
    if (odd.size() % 2 == 1)
    {
        cout<<"NO";
        return 0;
    }
    cout<<"YES"<<endl;
    for (int i = 0; i < even.size(); i++) res[1].push_back(even[i]);
    for (int i = 0; i < odd.size(); i++) res[1].push_back(odd[i]);
    for (int i = 1; i <= k; i++)
    {
        printf("%d ",res[i].size());
        for (int j = 0; j < res[i].size(); j++)
            printf("%d ",a[res[i][j]]);
        printf("\n");
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

