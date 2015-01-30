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

const int maxn = 100000+10;
int se[1000000];
vector< ii > ke[maxn];
int spt;
int KQ[maxn];
int n,m,u,v;

void DFS(int u)
{
    FOR(i,0,ke[u].size()-1)
    {
        ii v=ke[u][i];
        if (se[v.second]>0)
        {
            se[v.second]--;
            DFS(v.first);
        }
    }
    KQ[++spt]=u;
}

int main()
{
    //freopen("NKPOS.inp","r",stdin);
    //freopen("NKPOS.out","w",stdout);
    scanf("%d%d",&n,&m);
    FOR(i,1,n) scanf("%d",&u);
    FOR(i,1,m)
    {
        scanf("%d%d",&u,&v);
        ke[u].push_back(make_pair(v,i));
        ke[v].push_back(make_pair(u,i));
        se[i]++;
    }

    DFS(1);
    cout<<spt-1<<endl;
    FOR(i,1,spt) cout<<KQ[i]<<' ';
    fclose(stdin);
    fclose(stdout);
    return 0;
}

