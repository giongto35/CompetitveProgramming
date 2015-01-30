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
int a[maxn];
int used[maxn];
int T;
int n,m;
string st[maxn];
int trie[100000][30];
int cnt;
int t[maxn];
int dem;
int res,rescnt;
int cs[maxn];

int createnewtrie()
{
    cnt++;
    for (int i = 0; i <= 'Z'-'A'; i++)
        trie[cnt][i] = 0;
    return cnt;
}

void process()
{
    cnt = 0;
    for (int i = 1; i <= m; i++)
    {
        t[i] = createnewtrie();
        if (used[i] == 0) return;
    }
    dem = m;
    for (int i = 1; i <= n; i++)
    {
        int u = cs[i];
        for (int j = 0; j < st[i].size(); j++)
        {
            int v = st[i][j] - 'A';
            if (trie[u][v] == 0)
            {
                trie[u][v] = createnewtrie();
                dem++;
            }
            u = trie[u][v];
        }
    }
    if (dem > res)
    {
        res = dem;
        rescnt = 1;
    }
    else
    if (dem == res) rescnt++;
}

void rec(int vt)
{
    if (vt == n+1)
    {
        process();
        return;
    }
    for (int i = 1; i <= m; i++)
    {
        cs[vt] = i;
        used[i] ++ ;
        rec(vt+1);
        used[i] -- ;
    }
}

int main()
{
    freopen("D-small-attempt0.in","r",stdin);
    freopen("DCJ2.out","w",stdout);
    scanf("%d",&T);
    for (int sT = 1; sT <= T; sT++)
    {
        scanf("%d%d",&n,&m);
        getline(cin,st[0]);
        for (int i = 1; i <= n; i ++)
            getline(cin,st[i]);
        memset(used,0,sizeof(used));
        memset(trie,0,sizeof(trie));
        res=0;
        rescnt=0;
        rec(1);
        cout<<"Case #"<<sT<<": "<<res<<" "<<rescnt<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

