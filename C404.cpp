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
int n,k,m,sk;
vector<int> p[maxn];
int d[maxn];
vector<pair<int,int> > E;
int main()
{
    //freopen("C404.inp","r",stdin);
    //freopen("C404.out","w",stdout);
    cin>>n>>sk;
    m = 0;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d",&d[i]);
        m = max (m , d[i]);
        p[d[i]].push_back(i);
    }
    int cnt = 0;
    if (p[0].size () != 1)
        {
            cout<<-1<<endl;
            return 0;
        }
    for (int i = 0; i <= m; i++)
    {
        cnt += p[i].size();
        if (i <= 1) k = sk; else k = sk - 1;
        if (p[i].size() == 0)
        {
            cout<<-1<<endl;
            return 0;
        }
        if (i > 0 && ((long long)p[i].size() > (long long)p[i-1].size() * k))
        {
            cout<<-1<<endl;
            return 0;
        }
        if (i > 0)
        for (int j = 0; j < p[i].size(); j++)
        {
            int v = p[i][j];
            if (j / k + 1 > p[i-1].size() )
            {
                cout<<-1<<endl;
                return 0;
            }
            int u = p[i-1][j / k];
            E.push_back(make_pair(u,v));
        }
    }
    cout<<E.size()<<endl;
    FOREACH(it,E)
    cout<<(*it).first<<' '<<(*it).second<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

