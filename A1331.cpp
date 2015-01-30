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

template<class T> inline long long size(const T&c) { return c.size(); }

using namespace std;
long long fastMax(long long x, long long y) { return (((y-x)>>(32-1))&(x^y))^y; }
long long fastMin(long long x, long long y) { return (((y-x)>>(32-1))&(x^y))^x; }
const long long maxn=3*100000+10;
const long long oo=1000000000000000000ll;
long long n;
long long a[maxn],s[maxn],res;
vector<int> del;
map<int,int> f;
long long l,r;
int main()
{
    //freopen("A331.inp","r",stdin);
    //freopen("A1331.out","w",stdout);
    scanf("%d",&n);
    FOR(i,1,n) cin>>a[i];
    res=-oo;
    FOR(i,1,n)
    {
        if (a[i]>0)
        s[i]=s[i-1]+a[i];
        else
        s[i]=s[i-1];
        if (f[a[i]]==0)
        f[a[i]]=i;
        else
        {
            long long vt=f[a[i]];
            if (res<a[i]*2+max(0ll,s[i-1]-s[vt]))
            {
                res=a[i]*2+max(0ll,s[i-1]-s[vt]);
                l=vt;
                r=i;
            }
        }
    }
    FOR(i,1,l-1) del.push_back(i);
    FOR(i,l+1,r-1) if (a[i]<=0) del.push_back(i);
    FOR(i,r+1,n) del.push_back(i);
    cout<<res<<' '<<del.size()<<endl;

    FOR(i,0,del.size()-1) cout<<del[i]<<' ';
    fclose(stdin);
    fclose(stdout);
    return 0;
}

