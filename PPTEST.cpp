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

const int maxn =100+10;
int C[maxn],P[maxn],T[maxn];
int F[maxn][maxn];
int n,w,t;

int main()
{
    //freopen("PPTEST.inp","r",stdin);
    //freopen("PPTEST.out","w",stdout);
    scanf("%d",&t);
    FOR(i,1,t)
    {
        scanf("%d%d",&n,&w);

        FOR(i,1,n)
        {
            scanf("%d%d%d",&C[i],&P[i],&T[i]);
            C[i]=P[i]*C[i];
        }
        memset(F,0,sizeof(F));
        F[0][0]=0;
        FOR(i,1,n)
        {
            FOR(j,0,w)
            {
                if (j>0) F[i][j]=F[i][j-1];
                if (j-T[i]>=0)
                F[i][j]=max(F[i-1][j],F[i-1][j-T[i]]+C[i]);
                else
                F[i][j]=F[i-1][j];
            }
        }
        cout<<F[n][w]<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

