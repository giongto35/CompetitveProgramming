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

string st;
int F[1<<22];
int n,T;
int cnt;
int a[22];

int rec(int b)
{
    if (b == 0) return 2;
    if (F[b] != 0) return F[b];
    int cur = __builtin_popcount(b);
    F[b] = 2;
    for (int i = 0; i < cnt; i++)
    {

        if ((b >> i) & 1){
            int nb = b;
            int x = 0;
            nb ^= (1 << i);
            for (x = 0; x < cnt;  x++)
            if (a[x] <= cnt - cur)
            {
                nb &= ~(1 << x);
            }
            if (rec(nb) == 2)
            {
                F[b] = 1;
                break;
            }
        }
    }
    return F[b];
}
int main()
{
    freopen("G1IPSC.inp","r",stdin);
    //freopen("G1IPSC2.out","w",stdout);
    scanf("%d",&T);
    for (;T>0;T--)
    {
        scanf("%d",&n);
        cin>>st;
        cnt = 0;
        for (int i = 0 ; i < st.length(); i++)
        {
            if (st[i] == '1')
            {
                a[cnt++] = i;
            }
        }
        memset(F,0,sizeof(F));
        if (rec((1<<cnt) - 1) == 1)
            cout<<"Adam"<<endl;
        else
            cout<<"Betka"<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

