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
const int maxn = 500+10;
const int dy[4] = {0,1,0,-1};
const int dx[4] = {-1,0,1,0};
string st;
int prime[maxn],T;
int l[maxn][maxn],r[maxn][maxn],t[maxn][maxn],b[maxn][maxn];
char a[maxn][maxn];
int c[maxn][maxn];
int res,n,m;
int main()
{
    //freopen("CAOS1.inp","r",stdin);
    //freopen("CAOS1.out","w",stdout);
    prime[1]=0;;
    FOR(i,2,maxn-5)
    {
        prime[i]=prime[i-1]+1;
        for(int j=2;j*j<=i;j++)
            if (i%j==0) prime[i]=prime[i-1];
    }
    scanf("%d",&T);
    FOR(i,1,T)
    {
        scanf("%d%d",&n,&m);getline(cin,st);
        FOR(i,1,n)
        {
            getline(cin,st);
            FOR(j,1,m)
            a[i][j]=st[j-1];
        }
        res=0;
        RESET(l,0);
        RESET(t,0);
        RESET(r,0);
        RESET(b,0);
        FOR(i,1,n)
        FOR(j,1,m)
        {
            l[i][j]=l[i][j-1]*(a[i][j]=='^')+(a[i][j]=='^');
            t[i][j]=t[i-1][j]*(a[i][j]=='^')+(a[i][j]=='^');
        }
        DOW(i,n,1)
        DOW(j,m,1)
        {
            r[i][j]=r[i][j+1]*(a[i][j]=='^')+(a[i][j]=='^');
            b[i][j]=b[i+1][j]*(a[i][j]=='^')+(a[i][j]=='^');
        }
        FOR(i,1,n)
        {
            FOR(j,1,m)
            {
                if (a[i][j]=='^')
                {
                    int gtmin=min(min(l[i][j],r[i][j]),min(b[i][j],t[i][j]));
                    res+=prime[gtmin-1];
                }
            }
        }
        cout<<res<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

