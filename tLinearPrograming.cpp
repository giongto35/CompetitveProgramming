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

int main()
{
    //freopen("","r",stdin);
    freopen("LPTEST.in","w",stdout);
    cout<<10<<endl;
    for (int t = 1; t <= 10; t++)
    {
        int m = rand() % 150 + 1;
        int n = rand() % 150 + 1;
        if (m < n) swap(m,n);
        printf("%d %d\n",m,n);
            for (int j = 1; j <= n; j++)
            printf("%.2f ",(rand()+0.0) / 100);
            printf("\n");
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n+1; j++)
            printf("%.2f ",(rand()+0.0) / 100);
            printf("\n");
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

