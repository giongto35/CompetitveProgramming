
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
const int maxn=2000+10;
const int maxso = 200000+10;
int n;
int a[maxn];
int c[maxn];
int res;
/*int BIT[100000*3];
void update(int i,int gt)
{
    i+=100010;
    while (i<=maxso)
    {
        BIT[i]+=gt;
        i=i+(i & (-i));
    }
}


int get(int i,int k)
{
    int gt=0;
    i+=100010;
    while (i>=1)
    {
        gt+=BIT[i];
        i=i-(i & (-i));
    }
    return gt;
}
*/

int calc(int u)
{
    int res=0;
    FOR(i,1,u-1) if (a[i]>a[u])res++;
    FOR(i,u+1,n) if (a[i]<a[u])res++;
    return res;
}

int main()
{
    //freopen("E351.inp","r",stdin);
    //freopen("E351.out","w",stdout);
    cin>>n;
    FOR(i,1,n) cin>>a[i];
    res=0;
    FOR(i,1,n) c[i]=calc(i),res+=c[i];
    res/=2;
    /*FOR(i,1,n)
    {
        FOR(j,1,i-1) if (a[j]>a[i])res++;
    }
    FOR(i,1,n) cout<<c[i]<<endl;cout<<res<<endl;*/
    while(true)
    {
        bool ok=false;
        FOR(i,1,n)
        {
            a[i]=-a[i];
            int temp=calc(i);

            if (res>res-c[i]+temp)
            {
                res=res-c[i]+temp;
                //FOR(i,1,n) c[i]=calc(i);
                c[i]=temp;
                FOR(j,1,i-1) c[j]=c[j]-(a[j]>-a[i])+(a[j]>a[i]);
                FOR(j,i+1,n) c[j]=c[j]-(a[j]<-a[i])+(a[j]<a[i]);
                ok=true;
            }
            else
                a[i]=-a[i];
        }
        if (ok==false) break;
    }
    //FOR(i,1,n) cout<<c[i]<<' '<<calc(i)<<endl;
    cout<<res<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
