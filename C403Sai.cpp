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
const int maxn = 100+10;
int sk;
struct Matrix{
    int a[maxn][maxn];
    Matrix &operator *= (Matrix Y){
        Matrix X = *this;
        for (int i = 1; i <= sk; i++)
            for (int j = 1; j <= sk; j++)
        {
            a[i][j] = 0;
            for (int k = 1; k <= sk; k++)
                {
                    a[i][j] =  a[i][j] + 1LL * X.a[i][k] * Y.a[k][j];
                    if (a[i][j]> 0) a[i][j]  =1;
                }
        }
        return *this;
    }
}
A,res;
int n;


int main()
{
    freopen("C403.inp","r",stdin);
    freopen("C403.out","w",stdout);
    cin>>sk;
    for (int i = 1; i <= sk; i++)
    for (int j  = 1; j <= sk; j++) cin>>A.a[i][j];
    n = 10000;
    res = A;
    for (int x = 1; x <= n ; x++){
        res *= A;
        for (int i  =1 ; i <= sk; i ++)
        {for (int j  = 1; j <= sk; j++) cout<<res.a[i][j];cout<<endl;}
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

