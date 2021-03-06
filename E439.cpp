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

int F[300][300][300];
int n,f;
int main()
{
    //freopen("E439.inp","r",stdin);
    freopen("E439.out","w",stdout);
    int n = 100;
    for (int i = 1; i <= n; i++)
    {
        F[i][1][i] = 1;
    }
    for (int i = 1; i <= n; i++)
    for (int j = 1; j <= i; j++)
    {
        for (int k = 1; k <= i; k++)
        {
            if (F[i][j][k] > 0)
            {
                for (int x = 1; x <= n; x++)
                {
                    F[i+x][j+1][__gcd(k,x)] = (F[i+x][j+1][__gcd(k,x)] + F[i][j][k]) % 1000000007;
                    //if (i == 5 && j == 1 && k == 1 && x == 5) cout<<"ABC "<<F[i+x][j+1][__gcd(k,x)]<<endl;
                }
            }
        }
    }
    for (int i = 1; i <= 100; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout<<F[i][j][1]<<' ';
        }
        cout<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

