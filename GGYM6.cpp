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
int T,h,w;
char a[maxn][maxn];
double F[maxn][maxn];
string st;
double res;
double sres;

void process(int col)
{
    memset(F,0,sizeof(F));
    F[0][col] = 1;
    for (int i = 0; i < h; i++)
    {
        for (int j = 1; j <= w; j++)
        {
            if (F[i][j] == 0) continue;
            //cout<<i<<' '<<j<<endl;
            if (a[i][j] >= '0' && a[i][j] <= '9')
                continue;
            if (a[i+1][j] == '.' || (a[i + 1][j] >= '0' && a[i + 1][j] <= '9') )
            {

                F[i + 1][j] = F[i+1][j] + F[i][j];
            }
            else
            if (a[i+1][j] == '*')
            {
                F[i + 1][j - 1] = F[i + 1][j - 1] + F[i][j] / 2;
                F[i + 1][j + 1] = F[i + 1][j + 1] + F[i][j] / 2;
            }
        }
    }
    double res = 0;
    for (int i = 1; i <= h; i++)
    {
        for (int j = 1; j <= w; j++)
        {
            if (a[i][j] >= '0' && a[i][j] <= '9')
                res = res + F[i][j] * (a[i][j] - '0');
        }
    }
    //cout<<col<<' '<<res<<endl;
    sres = max(sres,res);
}
int main()
{
    //freopen("GGYM6.inp","r",stdin);
    //freopen("","w",stdout);
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&h,&w);
        getline(cin,st);
        for (int i = 1; i<= h; i++)
        {
            getline(cin,st);
            for (int j = 1; j <= w; j++)
            {
                a[i][j] = st[j-1];
            }
        }
        sres = 0;

        for (int j = 1; j <= w; j++)
        {
            process(j);
        }
        printf("%0.6f\n",sres);
/*        process(2);
        for(int i = 1; i <= h; i++){
            for (int j = 1; j <= w; j++)
            cout<<F[i][j]<<' ';
        cout<<endl;
        }*/

    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

