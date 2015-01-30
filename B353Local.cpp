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
const int maxn = 200+10;
int n;
int b[maxn];
int bb[maxn];
int c[maxn];
int d[maxn*maxn];
int a[maxn];
int kq[maxn];
int spt,spt2,dem,res;
int calc()
{
        spt=0;
    FOR(i,1,n/2)
    FOR(j,1,n/2)
    {
        d[++spt]=a[b[i]]*100+a[c[j]];
    }
    sort(d+1,d+1+spt);
    d[0]=-12321;
    res=0;
    FOR(i,1,spt)
    if (d[i]!=d[i-1]) res++;
    return res;
}
int main()
{
    freopen("B353.inp","r",stdin);
    //freopen("B353.out","w",stdout);
    cin>>n;n*=2;
    FOR(i,1,n)
    {
        cin>>a[i];
    }
    FOR(i,1,n/2) b[i]=i,kq[i]=1;
    FOR(i,n/2+1,n) c[i]=i,kq[i]=2;
    while(true)
    {
        bool ok=false;
        FOR(i,1,n/2)
        FOR(j,1,n/2)
        {
            int temp=calc();
            int tg=b[i];b[i]=c[j];c[j]=tg;
            if (calc()<=temp)
            {
                int tg=b[i];b[i]=c[j];c[j]=tg;
            }
            else
                kq[b[i]]=1,kq[c[i]]=2,ok=true;
        }
        if (ok==false) break;
    }
    cout<<calc()<<endl;
    FOR(i,1,n) cout<<kq[i]<<' ';
    fclose(stdin);
    fclose(stdout);
    return 0;
}
