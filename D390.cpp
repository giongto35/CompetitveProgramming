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
const int maxn = 50*50+10;
//priority_queue<pair<int, pair<int,int> > q;
const int dy[4] = {-1,0,1,0};
const int dx[4] = {0,-1,0,1};
priority_queue<pair<int, pair<int,int> > > q;
int n,m,k;
int spt;
int fr,re;
bool used[50+10][50+10];
//vector<pair<int,int> > res[maxn];
pair<int,int> kq[maxn];
int res;
int main()
{
    //freopen("D390.inp","r",stdin);
    //freopen("D390.out","w",stdout);
    scanf("%d%d%d",&n,&m,&k);
    used[1][1] = true;
    q.push(make_pair(-2,make_pair(1,1)));
    FOR(i,1,k)
    {
        pair<int, pair<int,int> > p = q.top();q.pop();
        res += p.second.first + p.second.second - 1;
        kq[i] = make_pair(p.second.first,p.second.second);
        FOR(d,0,3)
        {
            int y = p.second.first + dy[d];
            int x = p.second.second + dx[d];
            if (y >= 1 && y <= n && x >= 1 && x <= m && used[y][x] == false)
            {
                q.push(make_pair(-y-x,make_pair(y,x)));
                used[y][x] = true;
            }
        }
    }
    cout<<res<<endl;
    DOW(i,k,1)
    {
        FOR(y,1,kq[i].first) printf("(%d,1) ",y);
        FOR(x,2,kq[i].second) printf("(%d,%d) ",kq[i].first,x);
        printf("\n");
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

