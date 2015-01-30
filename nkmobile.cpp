#include <bits/stdc++.h>

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
const int maxn=2002;
int b[maxn][maxn];
int yy1,x1,y2,x2,y,x,a;
int n,com;


void add(int y, int xx, int gt)
{
        int x;
        while (y <= n){
            x = xx;
            while (x <= n)
            {
                b[y][x] = b[y][x] + gt;
                x += x & (-x);
            }
            y += y and (-y);
        }
}

int s(int y,int xx)
{
    int res = 0;
    while (y >= 1)
    {
        x = xx;
        while (x >= 1)
        {
            res += b[y][x];
            x -= x & (-x);
        }
        y -= y & (-y);
    }
    return res;
}

int get(int yy1,int x1,int y2,int x2)
{
    return s(y2,x2) - s(y2,x1-1) - s(yy1 - 1,x2) + s (yy1 - 1, x1 -1);
}

int main()
{
    freopen("nkmobile.inp","r",stdin);
    //freopen("nkmobile.out","w",stdout);
    int com;
    while (true)
    {
        scanf("%d",&com);
        if (com == 3) break;
        if (com == 0) scanf("%d",&n);
        if (com == 1) {scanf("%d%d%d",&x,&y,&a); add(y+1,x+1,a); }
        if (com == 2) {scanf("%d%d%d%d",&x1,&yy1,&x2,&y2); printf("%d\n",get(yy1+1,x1+1,y2+1,x2+1));}
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

