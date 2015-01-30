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

const int maxn  = 1000;
int n,x;
map<int,int> F;
int NIM;
int S,E,T;
const int c = 5;

int rec(int y,int x)
{
    //if (F[y][x]!=0) return F[y][x];
    if (y < x) return rec(x, y);
    if (y == x) return 0;
    if (y - x <= x)
    {
        int v = rec(x, y - x);
        if (v == 0) return 1; else return 0;
    }
    else
    if (y - c * x <= x)
    {

        pair<int,int> g[100];
        FOR(k,1,c)
        if ( y - k * x > 0)
            g[rec(x, y - k * x)] = make_pair(y,x);
        int k = 0;
        while (g[k].first == y && g[k].second == x) k++;
        return k;
        /*if (v == 0) return 1; else return 0;
        return 2;*/
    }
    else
    return rec(y % x + c * x, x) + y / x - c;

}

int main()
{
    freopen("GAMEAAM.inp","r",stdin);
    freopen("GAMEAAM2.out","w",stdout);
    scanf("%d",&T);
    FOR(i,1,100)
    {
        FOR(j,1,100) cout<<rec(i,j)<<' ';cout<<endl;
    }
    FOR(i,1,T)
    {
        scanf("%d",&n);
        NIM = 0;
        FOR(i,1,n)
        {
            scanf("%d%d",&S,&E);
            NIM = NIM ^ rec(S,E);
        }
        if (NIM == 0) cout<<"NO"<<endl; else cout<<"YES"<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

