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
const int maxn = 1000+10;
pair<int,int> a[maxn];
int c[maxn*maxn];
vector<int> b[2];
int kq[maxn];
int n,res;
int sl[maxn];

bool mycmp(pair<int,int> u,pair<int,int> v)
{
    if (sl[u.first]%2==sl[v.first]%2)
    {
        return u.first<v.first;
    }
    else
        return sl[u.first]%2>sl[v.first]%2;
}

int main()
{
    //freopen("B353.inp","r",stdin);
    //freopen("B353.out","w",stdout);
    cin>>n;
    n*=2;
    FOR(i,1,n) cin>>a[i].first,a[i].second=i,sl[a[i].first]++;
    sort(a+1,a+1+n,mycmp);
    FOR(i,1,n)
    {
        kq[a[i].second]=i%2+1;
        b[i%2].push_back(a[i].first);
    }
    int spt=0;
    FOR(i,0,b[0].size()-1)
    FOR(j,0,b[1].size()-1)
    {
        c[++spt]=b[0][i]*100+b[1][j];
    }
    sort(c+1,c+1+spt);
    c[0]=-123123;
    FOR(i,1,spt) if (c[i]!=c[i-1]) res++;
    cout<<res<<endl;
    FOR(i,1,n) cout<<kq[i]<<' ';
    fclose(stdin);
    fclose(stdout);
    return 0;
}
