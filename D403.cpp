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
const int maxn = 1000 + 10;
const int maxk = 50 + 10;
int F[2][maxn][maxn],s[2][maxn][maxn];
int C[maxn][maxn];
int res[maxn][maxn],GT[maxn],kk,t,n,k;
int main()
{
    //freopen("D403.inp","r",stdin);
    //freopen("D403.out","w",stdout);
    F[0][0][0] = 1;
    s[0][0][0] = 1;
    for (int kk = 0; kk <= 50; kk++)
    {
        int k = kk % 2;
        for (int i = 0; i <= 1000; i++)
        {
            for (int j = 0; j <= 1000; j++)
            {
                if (i == 0 && j == 0 && kk == 0) continue;
                F[k][i][j] = 0;
                if (i >= 1)
                F[k][i][j] = (F[k][i][j] + F[k][i-1][j]) % cmod;
                if (i >= j && j >= 1 && kk >= 1)
                {
                    //cout<<" + "<<1-k<<' '<<i-j<<' '<<j-1<<' '<<s[1-k][i-j][j-1]<<endl;
                    F[k][i][j] = (F[k][i][j] + ((long long)s[1-k][i-j][j-1] * kk )% cmod ) % cmod;
                }
                if (j == 0) s[k][i][j] = F[k][i][j]; else
                s[k][i][j] = (s[k][i][j-1] + F[k][i][j]) % cmod;
                //cout<<s[k][i][j]<<' ';
                //cout<<kk<<' '<<i<<' '<<j<<' '<<F[k][i][j];//<<' '<<F[k][i-1][j]<<' '<<F[1-k][i-j][j-2]<<' '<<F[1-k][i-j][j-1]<<' '<<kk<<' '<<(((long long)s[1-k][i-j][j-1]) * kk )<<endl;
            }
            //cout<<endl;
            //cout<<i<<' '<<k<<' '<<F[k][i][i]<<endl;

            res[i][kk] = s[k][i][i];
        }
        //cout<<endl;
    }
    cin>>t;
    while (t>0)
    {
        cin>>n>>k;
        printf("%d\n",res[n][k]);
        t--;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

