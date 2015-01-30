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

int c[8];
int s;
int res;
int T,n,m,k;

int calc()
{
    return c[0] + c[1] + c[2] + c[3] + c[4] + c[5] + c[6] + c[7] - 8;
}
int main()
{
    freopen("CCJ1C.inp","r",stdin);
    //freopen("CCJ1c.out","w",stdout);
    scanf("%d",&T);
    for (int st = 1; st <= T; st++)
    {
        scanf("%d%d%d",&n,&m,&k);
        if (k == 1)
        {
            cout<<"Case #"<<st<<": "<<1<<endl;
            continue;
        }

        if (k == 2)
        {
            cout<<"Case #"<<st<<": "<<2<<endl;
            continue;
        }

        if (k == 3)
        {
            cout<<"Case #"<<st<<": "<<3<<endl;
            continue;
        }

        if (k == 4)
        {
            cout<<"Case #"<<st<<": "<<4<<endl;
            continue;
        }

        if (k == 5)
        {
            cout<<"Case #"<<st<<": "<<4<<endl;
            continue;
        }


        c[0] = 1;
        c[1] = m;
        c[2] = 1;
        c[3] = n;
        c[4] = 1;
        c[5] = m;
        c[6] = 1;
        c[7] = n;
        s = n * m;
        res = calc();
        cout<<res<<endl;
        while (s > k)
        {
            int vt = -1;
            s -= c[vt];
            if (s < k) break;
            c[vt]++;
            c[(vt + 1) % 8]--;
            c[(vt + 7) % 8]--;
            if (c[(vt + 1) % 8] == 0)
            {
                c[vt] --;
                c[(vt + 1) % 8] = 2;
                c[(vt + 2) % 8] --;
                if (c[(vt + 2) % 8] == 1)
                {
                    c[(vt + 1) % 8] --;
                    c[(vt + 3) % 8] --;
                    c[(vt + 2) % 8] ++;
                }
            }
            if (c[(vt + 7) % 8] == 0)
            {
                c[vt] --;
                c[(vt + 7) % 8] = 2;
                c[(vt + 6) % 8] --;
                if (c[(vt - 2 + 8) % 8] == 1)
                {
                    c[(vt - 1 + 8) % 8] --;
                    c[(vt - 3 + 8) % 8] --;
                    c[(vt - 2 + 8) % 8] ++;
                }
            }
            res = calc();
        }
        cout<<"Case #"<<st<<": "<<res<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

