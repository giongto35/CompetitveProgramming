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

const int cmod = 1000000007;
const int maxn = 100;
int k;
long  long n;
int sk;
int CH[maxn][maxn];

struct Matrix{
    int a[maxn][maxn];
    Matrix &operator *= (Matrix Y){
        Matrix X = *this;
        for (int i = 1; i <= sk; i++)
            for (int j = 1; j <= sk; j++)
        {
            a[i][j] = 0;
            for (int k = 1; k <= sk; k++)
                a[i][j] =  (a[i][j] + 1LL * X.a[i][k] * Y.a[k][j]) % cmod;
        }
        return *this;
    }
}
A,S,C,res;

void InitMat()
{
    sk = 2*k + 3;
    for(int i = 0; i <= sk; i ++)
    {
        CH[i][0] = 1;
        for (int j = 1; j <= i; j++)
        {
            CH[i][j] = (CH[i-1][j] + CH[i-1][j-1])% cmod;
        }
    }
    int d = k;
    A.a[1][1] = 1;
    for(int i = 2; i <= k + 2; i++)
        A.a[1][i] = CH[k][d--];
    d = k ;
    for(int i = k + 3; i <= sk; i++)
        A.a[1][i] = CH[k][d--];
    int d1 =k;
    for(int i = 2; i <= k + 2; i++)
    {
        d = d1;
        for(int j = i; j <= k + 2; j++)
        {
            A.a[i][j] = CH[d1][d];
            A.a[i+k+1][j] = CH[d1][d--];
        }

        d = d1;
        for(int j = k + i + 1; j <= sk; j++)
            A.a[i][j] = CH[d1][d--];

        d1--;
    }
}

void process()
{

    for (int i = 1; i <= sk ; i++) S.a[i][1] = 1;
    for (int i = 1; i <= sk; i++) res.a[i][i] = 1;

    n -= 1;

    while (n > 0)
    {
        if (n & 1) { res *= A;}
        A *= A;
        n /= 2;
    }

    res *= S;
    cout<< res.a[1][1]<<endl;
}

int main()
{
    //freopen("C392.inp","r",stdin);
    //freopen("C392.out","w",stdout);
    scanf("%I64d%d",&n,&k);
    InitMat();
    process();
    fclose(stdin);
    fclose(stdout);
    return 0;
}
