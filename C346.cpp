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
pair<int,int> b[maxn];
int n,a[maxn],c[maxn];
int x,y;
int res;
int sum;

bool mycmp(pair<int,int>a, pair<int,int>b)
{
    return a.second<b.second;
}
int main()
{
    freopen("C346.inp","r",stdin);
    //sfreopen("C346.out","w",stdout);
    cin>>n;
    FOR(i,1,n) scanf("%d",&c[i]);
    sort(c+1,c+1+n);
    c[0]=-123123;
    int spt=0;
    FOR(i,1,n)
    if (c[i]!=c[i-1]) a[++spt]=c[i];
    //FOR(i,1,spt) cout<<a[i]]
    scanf("%d%d",&x,&y);
    int sl=spt;
    FOR(i,1,spt) b[i].first=i,b[i].second=x/a[i]*a[i];
            int sl2=0;
            FOR(i,1,sl)
            {
                ++sl2;
                b[sl2].second=x/a[b[i].first]*a[b[i].first];
                b[sl2].first=b[i].first;
                if (b[sl2].second<y) sl2--;
            }
            sl=sl2;
    res=x-y;
    sum=0;
    b[0].second=-123123;
    while (x>=y)
    {
        //cout<<x<<' '<<y<<endl;
        sort(b+1,b+1+sl,mycmp);
        //FOR(i,1,sl) cout<<b[i].second<<' ';cout<<endl;
        x=b[1].second;
        sum++;
        if (sl==1) break;
        if (x<y) break;
        int sl2=0;
        FOR(i,1,sl)
        {
            ++sl2;
            b[sl2].second=x/a[b[i].first]*a[b[i].first];
            b[sl2].first=b[i].first;
            if (b[sl2].second<y) sl2--;
        }
        sl=sl2;
        res=min(res,sum+x-y);
        bool check=false;
        FOR(i,2,sl) if (b[i].second!=b[i-1].second) check=true;
        if (check==false)
        {
            x--;
            if (x<y) break;
            sum++;
            int sl2=0;
            FOR(i,1,sl)
            {
                ++sl2;
                b[sl2].second=x/a[b[i].first]*a[b[i].first];
                b[sl2].first=b[i].first;
                if (b[sl2].second<y) sl2--;
            }
            sl=sl2;
            res=min(res,sum+x-y);
        }
    }
    if (x>=y) res=min(res,sum+x-y);
    cout<<res<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

