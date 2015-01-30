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

const int maxn = 2000+10;
char a[maxn][maxn];
int n,m;
string st;
pair<int,int> next[maxn][maxn];
int d[maxn][maxn];
int fr[maxn][maxn];
int c[maxn][maxn];
pair<int,int> lab[maxn][maxn];
int cnt;
bool inf;
int gtmax;
pair<int,int> vtmax;

void vis(int y,int x)
{
    while (true){
        if (a[y][x] == '#')
        {
            lab[y][x] = make_pair(y,x);
            c[y][x] = 0;
            return;
        }
        fr[y][x] = cnt;
        if (a[next[y][x].first][next[y][x].second] == '#')
        {
            c[y][x] = 1;
            lab[y][x] = make_pair(y,x);
            return;
        }
        if (fr[next[y][x].first][next[y][x].second] == cnt)
        {
            inf = true;
            return ;
        }
        if (fr[next[y][x].first][next[y][x].second] == 0)
        {
            y,x = next[y][x].first, next[y][x].second;
            vis(next[y][x].first,next[y][x].second);
        }
        if (inf) return ;
        c[y][x] = c[next[y][x].first][next[y][x].second] + 1;
        lab[y][x] = lab[next[y][x].first][next[y][x].second];
    }
}

int main()
{
    //freopen("D382.inp","r",stdin);
    //freopen("D382.out","w",stdout);
    scanf("%d%d",&n,&m);
    getline(cin,st);
    FOR(i,1,n)
    {
        getline(cin,st);
        FOR(j,1,m) a[i][j] = st[j-1];
    }
    FOR(i,1,n)
    FOR(j,1,m)
    {
        if (a[i][j] == '>') { next[i][j] = make_pair(i,j+1); d[i][j+1] ++;}
        if (a[i][j] == '<') { next[i][j] = make_pair(i,j-1); d[i][j-1] ++;}
        if (a[i][j] == '^') { next[i][j] = make_pair(i-1,j); d[i-1][j] ++;}
        if (a[i][j] == 'v') { next[i][j] = make_pair(i+1,j); d[i+1][j] ++;}
    }
    inf = false;
    FOR(i,1,n)
    FOR(j,1,m)
    {
        if (fr[i][j] == 0 && d[i][j] == 0 && a[i][j]!='#')
        {
            cnt ++;
            vis(i,j);
            if (inf)
            {
                cout<<-1;
                return 0;
            }
        }
    }
    FOR(i,1,n)
    FOR(j,1,m)
    {
        if (fr[i][j] == 0 && a[i][j]!='#')
        {
            cnt ++;
            vis(i,j);
            if (inf)
            {
                cout<<-1;
                return 0;
            }
        }
    }
    gtmax = -1;
    FOR(i,1,n)
    FOR(j,1,m)
    {
        if (gtmax<c[i][j])
        {
            gtmax = c[i][j];
            vtmax = lab[i][j];
        }
    }/*
    FOR(i,1,n)
    {
        FOR(j,1,m) cout<<c[i][j]<<' ';cout<<endl;
    }

    FOR(i,1,n)
    {
        FOR(j,1,m) cout<<lab[i][j].first<<lab[i][j].second<<' ';cout<<endl;
    }*/

    FOR(i,1,n)
    FOR(j,1,m)
    {
        if (c[i][j] == gtmax)
        {
            if (!((lab[i][j].first == vtmax.first)&&(lab[i][j].second == vtmax.second)))

            {
                //cout<<i<<' '<<j<<endl;
                //cout<<vtmax.first<<' '<<vtmax.second<<endl;
                cout<<max(0,2 * gtmax);
                return 0;
            }
        }
    }
    cout<<max(0,gtmax + gtmax - 1);
    fclose(stdin);
    fclose(stdout);
    return 0;
}

