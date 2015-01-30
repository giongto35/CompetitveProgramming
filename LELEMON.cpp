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
const int maxn = 100000+10;
int n,m,T,u;
int cnt[maxn];
long long res;
int a[200][200],s[maxn];
int main()
{
    //freopen("LELEMON.inp","r",stdin);
    //freopen("LELEMON.out","w",stdout);
    scanf("%d",&T);
    FOR(i,1,T)
    {
        scanf("%d%d",&n,&m);
        memset(cnt,0,sizeof(cnt));
        FOR(i,1,m)
        {
            scanf("%d",&u);
            cnt[u+1]++;
        }
        res=0;
        FOR(i,1,n)
        {
            scanf("%d",&s[i]);
            FOR(j,1,s[i])
            scanf("%d",&a[i][j]);
            sort(a[i]+1,a[i]+1+s[i],greater<int>());
            FOR(j,1,min(s[i],cnt[i]))
            {
                //cout<<a[i][j]<<' ';
                res+=a[i][j];
            }
        }
        cout<<res<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

