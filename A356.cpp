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
const int maxn = 3*100000+10;
int r[maxn];
int res[maxn];
int u,v,x,n,m;
int main()
{
    //freopen("A356.inp","r",stdin);
    //freopen("A356.out","w",stdout);
    cin>>n>>m;
    FOR(i,1,n) r[i]=i+1;
    FOR(i,1,m)
    {
        cin>>u>>v>>x;
        while (u<x)
        {
            //if (u==1&&v==4) cout<<u<<' '<<r[u]<<endl;
            if (res[u]==0&&u!=x)
            res[u]=x;
            int temp=r[u];
            r[u]=x;
            u=temp;
        }
        u=r[x];
        while (u<=v)
        {
            if (res[u]==0)
            res[u]=x;
            int temp=r[u];
            r[u]=r[v];
            u=temp;
        }
        //FOR(i,1,n) cout<<res[i]<<' ';cout<<endl;
    }
    FOR(i,1,n) cout<<res[i]<<' ';


    fclose(stdin);
    fclose(stdout);
    return 0;
}
