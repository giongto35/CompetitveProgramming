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

unsigned long long u,v,g;
int T;
int sT;
int res;
int main()
{
    freopen("A-large-practice.in","r",stdin);
    freopen("Asmall.out","w",stdout);
    scanf("%d",&T);
    for (int sT = 1; sT <= T; sT++)
    {
        scanf("%lld/%lld",&u,&v);
        int cnt = 1;
        int res = 0;
        while (!((u == 1 || u == 0) && v == 1) && cnt <= 40)
        {
            //cout<<u<<' '<<v<<endl;
            if (2 * u >= v && res == 0) res = cnt;
            cnt++;
            u *= 2;
            g = __gcd(u,v);
            u/=g;
            v/=g;
            //cout<<u<<' '<<v<<endl;
            if (u > v)
            {
                u -= v;
                g = __gcd(u,v);
                //cout<<"DCM "<<u<<' '<<v<<' '<<g<<endl;
                u/=g;
                v/=g;
            }
        }
        if (cnt == 41) cout<<"Case #"<<sT<<": "<<"impossible"<<endl;else
        cout<<"Case #"<<sT<<": "<<res<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

