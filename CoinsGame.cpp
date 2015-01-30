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

int n,k,c,T;
int h,x,r,rd,rc,nc,move;
int res;
int main()
{
    freopen("coins_game.txt","r",stdin);
    freopen("coinsgame.out","w",stdout);
    cin>>T;
    FOR(i,1,T)
    {
        res=oo;
        scanf("%d%d%d",&n,&k,&c);
        h = k / n;
        r = k % n;
        if (h * n >= c) res = c; else res = c + (n - r);
        FOR(x,1,n-1)
        {
            h = k / x;
            r = k % x;
            rd = r / (n - x);
            rc = r % (n - x);
            if (rd + (rc > 0) > h) continue;
            nc = c;
            move = rd * n;
            nc -= rd * n;
            if (nc <= 0) { res = c; continue;}
            else
            {
                move += n - x - rc;
                if (rc!=0)
                {
                    if (nc - (rc + x) <= 0)
                    {
                        res = min(res , move + nc );
                        continue;
                    }
                    nc -= (rc + x);
                    move += rc + x + rc;
                }
                res = min(res , move + nc);
            }
        }
        cout<<"Case #"<<i<<": "<<res<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

