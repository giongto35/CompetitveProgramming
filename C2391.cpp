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

const int maxn = 200000+10;
pair<int,int> a[maxn];
int n,k;
long long res;
vector<pair<int,int> > c;
vector<pair<int,int> > b;
long long s1[maxn];
long long s2[maxn];

bool mycmp(pair<int,int> p1, pair<int,int> p2)
{
    return p1.second < p2.second;
}

long long calc(int v)
{
    if (v > n) return 1000000000000000000ll;
    c.clear();
    b.clear();
    int currank = 0;
    FOR(i,1,n)
    {
        if (a[i].first == v || a[i].first == v-1)
            c.push_back(a[i]);
        else
            b.push_back(a[i]);
        if (a[i].first < v - 1) currank++;
    }
    sort(c.begin(),c.end(),mycmp);
    sort(b.begin(),b.end(),mycmp);
    s1[0] = 0;
    FOR(i,1,(int)c.size())
        s1[i] = s1[i-1] + c[i-1].second;
    FOR(i,c.size()+1,n+1) s1[i] = 1000000000000000000ll;
    s2[0] = 0;
    FOR(i,1,(int)b.size())
        s2[i] = s2[i-1] + b[i-1].second;
    FOR(i,b.size()+1,n+1) s2[i] = 1000000000000000000ll;
/*    cout<<currank<<endl;
    cout<<k - currank<<' '<<currank<<endl;
    cout<<s1[k-currank]<<endl;*/
    long long res = 1000000000000000000ll;
    FOR(j,k,n+1) if (j >= currank && v - ( j -currank) >= 0) res=min(res,s1[j-currank] + s2[v - (j - currank)]);
    return res;
}

int main()
{
    //freopen("C1.inp","r",stdin);
    //freopen("C1.out","w",stdout);
    scanf("%d%d",&n,&k);
    k = (n + 1) - k;
    FOR(i,1,n)
    {
        scanf("%d%d",&a[i].first,&a[i].second);
    }
    sort(a+1,a+1+n);

    res = 1000000000000000000ll;
/*    FOR(i,1,n)
    {
        res = min(res,calc(a[i].first));
        if (a[i].first - 1 >= 0)
        res = min(res,calc(a[i].first - 1));
        res = min(res,calc(a[i].first + 1));
    }
    */
    /*int l = 0;
    int r = n;
    while (l<=r)
    {
        int mid = (l + r) / 2;

    }
      FOR(i,0,n)
    {
        cout<<calc(i)<<endl;
        res = min(res,calc(i));
    }*/
    FOR(x,0,10)
    {
        if (a[k].first + x - 5 >= 0)
        res = min(res,calc(a[k].first+x-5));
        //res = min(res,calc(a[k].first+x));
        //res = min(res,calc(a[k].first+x+1));
    }
    if (res == 1000000000000000000ll) cout<<-1; else
    cout<<res<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

