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

const int maxn = 3000+10;
int a[maxn][maxn];
int l[maxn][maxn];
int r[maxn][maxn];
int gl[maxn][maxn];
int gr[maxn][maxn];
int rl[maxn][maxn];
int rr[maxn][maxn];
int rg[maxn][maxn];
int h[maxn][maxn];
int vtl[maxn];
int vtr[maxn];
int st[maxn];
int top;
int res;
int n,m,T;

int calcl(int i, int j, int r)
{
    if (j == 1) return 1;
    if (j == m) return 1;
    int res = oo;
    for (int k = 0; k <= 1; k++)
    {
        if (a[i-k][j-1] - a[i-k][j] == a[i-k][j] - a[i-k][j+1]) {
            res = min(res, gl[i-k][j]);
        } else res = 1;
    }
    return res;
}

int calcr(int i, int j, int r)
{
    if (j == 1) return 1;
    if (j == m) return 1;
    int res = oo;
    for (int k = 0; k <= 1; k++)
    {
        if (a[i-k][j-1] - a[i-k][j] == a[i-k][j] - a[i-k][j+1]) {
            res = min(res, gr[i-k][j]);
        } else res = 1;
    }
    return res;
}

void process() {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
                cout<<a[i][j]<<' ';
            cout<<endl;
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
               if (j == 1) l[i][j] = 1;
               else
               if (j == 2) l[i][j] = 2;
               else
               {
                   if (a[i][j] - a[i][j-1] == a[i][j-1] - a[i][j-2]) {
                        l[i][j] = l[i][j-1] + 1;
                   } else l[i][j] = 2;
               }
            }
            for (int j = m; j >= 1; j--)
            {
               if (j == m) r[i][j] = 1;
               else
               if (j == m-1) r[i][j] = 2;
               else
               {
                   if (a[i][j] - a[i][j+1] == a[i][j+1] - a[i][j+2]) {
                        r[i][j] = r[i][j+1] + 1;
                   } else r[i][j] = 2;
               }
            }
        }

        top = 0;
        st[0] = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (i == 1) h[i][j] = 1, rl[i][j] = l[i][j], rr[i][j] = r[i][j], gl[i][j] = calcl(i,j,1), gr[i][j] = calcr(i,j,1);
                else
                if (i == 2) h[i][j] = 2, rl[i][j] = min(l[i-1][j], l[i][j]), rr[i][j] = min(r[i-1][j], r[i][j]), gl[i][j] = calcl(i,j,2), gr[i][j] = calcr(i,j,2);
                else
                {
                    if (a[i][j] - a[i-1][j] == a[i-1][j] - a[i-2][j]) {
                        h[i][j] = h[i-1][j] + 1;
                        rr[i][j] = min(rr[i-1][j], r[i][j]);
                        rl[i][j] = min(rl[i-1][j], l[i][j]);

                        gl[i][j] = min(gl[i-1][j], calcl(i,j,1));
                        gr[i][j] = min(gr[i-1][j], calcr(i,j,1));

                    } else {
                        h[i][j] = 2;
                        rr[i][j] = min(r[i-1][j], r[i][j]);
                        rl[i][j] = min(l[i-1][j], l[i][j]);
                        gl[i][j] = calcl(i,j,2);
                        gr[i][j] = calcr(i,j,2);
                    }
                }

                while (top > 0 && h[i][st[top]] >= h[i][j]) top--;
                vtl[j] = st[top] + 1;
                st[++top] = j;

            }

            top = 0;
            st[0] = m + 1;
            for (int j = m; j >= 1; j--)
            {
                while (top > 0 && h[i][st[top]] >= h[i][j]) top--;
                vtr[j] = st[top] - 1;
                st[++top] = j;

                res = max(res, h[i][j] * min(rl[i][j], j - vtl[j] + 1));
                res = max(res, h[i][j] * min(rr[i][j], vtr[j] - j + 1));
                if (j > 1 && j < m) {
                    if (a[i][j] - a[i][j-1] == a[i][j+1] - a[i][j]) {
                        res = max(res, h[i][j] * (min(gl[i][j], j - vtl[j] + 1) + min(gr[i][j], vtr[j] - j + 1) - 1));
                    }
                }
            }
        }
        cout<<"h"<<endl;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
                cout<<h[i][j]<<' ';
            cout<<endl;
        }
        cout<<"l"<<endl;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
                cout<<l[i][j]<<' ';
            cout<<endl;
        }
        cout<<"rl"<<endl;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
                cout<<rl[i][j]<<' ';
            cout<<endl;
        }
        cout<<"r"<<endl;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
                cout<<r[i][j]<<' ';
            cout<<endl;
        }
        cout<<"rr"<<endl;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
                cout<<rr[i][j]<<' ';
            cout<<endl;
        }
}

void rot() {
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            swap(a[i][j], a[j][i]);
        }
    }
}

int main()
{
    //freopen("ARY.inp","r",stdin);
    //  freopen("","w",stdout);
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&m);
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            scanf("%d",&a[i][j]);
        }
        res = 0;
        process();
        //rot();
        //process();
        printf("%d\n",res);
        break;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

