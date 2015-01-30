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

const int maxn = 300;
const int base = 150;
const int dy[4] = {1,0,-1,0};
const int dx[4] = {0,1,0,-1};
string st;

char a[maxn][maxn];
int y,x,T;
int miny,maxy,minx,maxx;
int dir;
int main()
{
    //freopen("J.inp","r",stdin);
    //freopen("J.out","w",stdout);
    scanf("%d",&T);
    printf("%d\n",T);
    while (T--) {
        cin>>st;
        y = base;
        x = base;
        dir = 1;
        miny = base;
        minx = base;
        maxy = base;
        maxx = base;
        a[y][x] = '.';
        for (int i = 0; i <= 299; i++)
            for (int j = 0; j <= 299; j++)
                a[i][j] = ' ';
        for (int i = 0; i < st.length(); i++){
                //cout<<y<<' '<<x<<' '<<' '<<dir<<st[i]<<endl;

            if (st[i] == 'R') {
                y += dy[(dir + 3) % 4];
                x += dx[(dir + 3) % 4];
                dir = (dir + 3) % 4;
            } else
            if (st[i] == 'F') {
                a[y + dy[(dir + 3) % 4]][x + dx[(dir + 3) % 4]] = '#';
                y += dy[dir];
                x += dx[dir];
            } else
            if (st[i] == 'L') {
                a[y + dy[(dir + 3) % 4]][x + dx[(dir + 3) % 4]] = '#';
                a[y + dy[dir]][x + dx[dir]] = '#';
                y += dy[(dir + 1) % 4];
                x += dx[(dir + 1) % 4];
                dir = (dir + 1) % 4;
            } else
            if (st[i] == 'B') {
                a[y + dy[(dir + 3) % 4]][x + dx[(dir + 3) % 4]] = '#';
                a[y + dy[dir]][x + dx[dir]] = '#';
                a[y + dy[(dir + 1) % 4]][x + dx[(dir + 1) % 4]] = '#';
                y += dy[(dir + 2) % 4];
                x += dx[(dir + 2) % 4];
                dir = (dir + 2) % 4;
            }
            a[y][x] = '.';
            miny = min(miny, y);
            minx = min(minx, x);
            maxy = max(maxy, y);
            maxx = max(maxx, x);
        }
        printf("%d %d\n",maxy - miny + 1 + 2, maxx - minx + 1 + 1);
        for ( int i = miny-1 ; i <= maxy + 1; i++) {
            for (int j = minx; j <= maxx + 1; j++) {
                if (a[i][j] == ' ') printf("#"); else
                printf("%c",a[i][j]);
            }
            printf("\n");
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

