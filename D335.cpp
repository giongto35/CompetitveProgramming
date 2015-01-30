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
#define fi first
#define se second

typedef vector<int> VI ;
typedef vector<string> VS ;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;

template<class T> inline int size(const T&c) { return c.size(); }

using namespace std;
int fastMax(int x, int y) { return (((y-x)>>(32-1))&(x^y))^y; }
int fastMin(int x, int y) { return (((y-x)>>(32-1))&(x^y))^x; }
struct rect
{
    int x1,y1,x2,y2;
} r[110000];
const int maxn=3000+10;
const int si  =3000;
int a[maxn][maxn];
int b[maxn][maxn],s[maxn][maxn];
int g[maxn][maxn][4];
vector<int> res;
int n,x,y,x2,y2;

int calc(int y1,int x1,int y2,int x2,int c)
{
    return g[y2][x2][c]-g[y2][x1-1][c]-g[y1-1][x2][c]+g[y1-1][x1-1][c];
}

int main()
{
    //freopen("D335.inp","r",stdin);
    //freopen("D335.out","w",stdout);
    scanf("%d",&n);
    FOR(i,1,n)
    {
        scanf("%d%d%d%d",&x,&y,&x2,&y2);
        r[i].x1=x+1;
        r[i].y1=y+1;
        r[i].x2=x2;
        r[i].y2=y2;
        FOR(i,y+1,y2)
        {
            a[i][x+1]++;
            a[i][x2+1]--;
            //b[i][x+1]&=1;
            //b[i][x2]&=4;
            g[i][x+1][0]++;
            g[i][x2 ][2]++;
        }
        FOR(i,x+1,x2)
        {
            g[y2 ][i][1]++;
            g[y+1][i][3]++;
            //b[y+1][i]&=2;
            //b[y2][i]&=8;
        }
    }
    FOR(i,1,si)
    {
        FOR(j,1,si)
        {
            a[i][j]=a[i][j-1]+a[i][j];
            s[i][j]=s[i][j-1]+s[i-1][j]-s[i-1][j-1]+a[i][j];
            FOR(k,0,3)
            {
                g[i][j][k]=g[i-1][j][k]+g[i][j-1][k]-g[i-1][j-1][k]+g[i][j][k];
            }
        }
        //cout<<endl;
    }

    FOR(i,1,si)
    FOR(j,1,si)
    {
        int y=i;
        int x=j;
        while (y>=1&&x>=1)
        {
            if (s[i][j]-s[y-1][j]-s[i][x-1]+s[y-1][x-1]==(i-y+1)*(j-x+1)
              &&calc(y,j,i,j,2)==(i-y+1)
              &&calc(i,x,i,j,1)==(j-x+1))
            {
                if (calc(y,x,y,j,3)==(j-x+1)
                  &&calc(y,x,i,x,0)==(i-y+1))
                {
                    cout<<"YES ";
                    res.clear();

                    FOR(k,1,n)
                        if (r[k].y1>=y&&r[k].x1>=x&&r[k].y2<=i&&r[k].x2<=j) res.push_back(k);
                    cout<<res.size()<<endl;
                    FOR(i,0,res.size()-1)
                    cout<<res[i]<<' ';
                    return 0;
                }
                y--;
                x--;
            }
            else break;
        }
    }
    cout<<"NO";
    fclose(stdin);
    fclose(stdout);
    return 0;
}


