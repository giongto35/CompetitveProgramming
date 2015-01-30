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
const int maxs = 100;
int A[maxs][maxs];
int ms;
int n,k;
int C[maxs][maxs];
int S[maxs][maxs];

typedef vector<vector<int> > mat;

struct matrix{
    int m[maxs][maxs];
    maxtrix(int diag = 0)
    {
        for (int i = 0; i < D; i++)
            for (int j  =0 ; j < D; j++)
                m[i][j] = (i = j) * diag;
    }
    matrix operator *(const matrix&b) const{
        matrix c;
        for (int i = 0; i < D; i++)
            for (int j = 0; j < D; j++)
                for (int l = 0; l < D; l++)
                c.m[i][j] = (c.m[i][j] +(long long)m[i][l] * m[l][j] % cmod) % cmod;
    }
};

void InitMatrix()
{
    int d = 0;
    A[1][1] = 1;
    FOR(i,2,k+1) A[1][i] = C[k][++d],A[2][i] = C[k][d];
    d = 0;
    FOR(i,k+2,n) A[1][i] = C[k][++d],A[2][i] = C[k][d];
    d = 1;
    FOR(i,3,k+1) {++d;A[i][d] = 1;A[i][d+k] = 1;}
    d = 0;
    FOR(i,2,k+1)
        A[k+2][i] = C[k][++d];
    d = 1;
    FOR(i,k+3,ms)
        A[i][++d] = 1;
    S[1][1] = 1;
    FOR(i,2,k+1) S[i][1] = 1;
}

int main()
{
    freopen("","r",stdin);
    freopen("","w",stdout);
    cin>>n>>k;
    ms = k * 2 + 1;
    C[0][0] = 1;
    FOR(i,1,k)
    {
        C[i][0] = 1;
        FOR(j,1,i)
        {
            C[i][j] = (C[i-1][j] + C[i-1][j-1]) % cmod;
        }
    }
    InitMatrix();
    n = n-1;
    while (n){
        if (n & 1) r = r * a;
        n >>= 1; a = a * a;
    }
    FOR(i,2,k+1)
    fclose(stdin);
    fclose(stdout);
    return 0;
}


