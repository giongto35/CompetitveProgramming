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

map<int, int> dodai; // mang danh dau dodai[i] la do duong di ngan nhat den i
int q[1000000 + 10];
int fr,re;
int T,n,a,b,k;

int main()
{
    freopen("ROBOT.inp","r",stdin);
    freopen("ROBOT.out","w",stdout);
    scanf("%d",&T);
    for (;T > 0; T--)
    {

        scanf("%d%d%d%d",&n,&a,&b,&k);
        fr = 0;
        re = 1;
        dodai.clear();// buoc chuan bi
        q[1] = 0;
        dodai[0] = 0;//bat dau tai 0,
        while (fr < re)
        {
            fr++;
            int u = q[fr];
            if (dodai[u] == k) break; // so buoc di = k thi ngung
            if (u + a <= n && dodai.count(u + a) == 0) // neu u + a <= n va u + a chua duyet den
            {
                q[++re] = u + a; // duyet tiep vi tri u + a
                dodai[u + a] = dodai[u] + 1; // so buoc di = so buoc di cua u + 1
            }
            if (u - b >= 1 && dodai.count(u - b) == 0) // neu u - b >= 1 va u - b chua duyet den
            {
                q[++re] = u - b; // duyet tiep vi tri u - b
                dodai[u - b] = dodai[u] + 1; // so buoc di = so buoc di den u + 1
            }
        }
        printf("%d\n",n + 1 - dodai.size()); // ket qua =  n + 1 - so o di den duoc
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
