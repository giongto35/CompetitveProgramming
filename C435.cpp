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
int cury,curx;
const int cmax = 1000000+10;
vector<int> pos[cmax*2];
int gtmin,gtmax,n;
int a[2000];
int main()
{
    //freopen("C435.inp","r",stdin);
    //freopen("C435.out","w",stdout);
    scanf("%d",&n);
    cury = 0;
    curx = 0;
    gtmin = 1000000000;
    gtmax = -1000000000;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d",&a[i]);
            for (int j = 1; j <= a[i]; j++)
            {
                curx++;
                if (i % 2 == 1)
                {
                    gtmin = min(gtmin,cury+cmax);
                    gtmax = max(gtmax,cury+cmax);
                    pos[cury+cmax].push_back(curx * 2);
                    if (j < a[i])
                    cury -= 1;
                }
                else
                {
                    gtmin = min(gtmin,cury+cmax);
                    gtmax = max(gtmax,cury+cmax);
                    pos[cury+cmax].push_back(curx * 2 + 1);
                    if (j < a[i])
                    cury += 1;
                }
            }
    }

    for (int i = gtmin; i <= gtmax; i++)
    {
        int vt = 0;
        for (int j = 0 ; j < pos[i].size(); j++)
        {
            int v = pos[i][j];
            while (vt < v / 2 - 1) printf(" "),vt++;
            if (v % 2 == 0)
                printf("/");
            else
                printf("\\");
            vt = v / 2;
        }
        while (vt < curx) printf(" "),vt++;
        printf("\n");
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

