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
using namespace std ;

#define FOREACH(it,c) for( __typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define FOR(i,a,b) for( int i=(a),_b=(b);i<=_b;i++)
#define DOW(i,b,a) for( int i=(b),_a=(a);i>=_a;i--)
#define REP(i,n) FOR(i,0,(n)-1)
#define DEP(i,n) DOW(i,(n)-1,0)
#define all(a) (a).begin() , (a).end()
#define push(a,b) (a).push_back((b))

typedef vector<int> VI ;
typedef vector<string> VS ;
template<class T> inline int size(const T&c) { return c.size(); }

using namespace std;
const int cmod=1000000009;
const int maxn = 200000+10;
long long gh,T,n,m;
long long a[maxn],c[maxn],s[maxn],d[maxn];
long long F[maxn];
long long BIT[2][262144+10];

void update(long long i,long long k,long long gt)
{
    i++;
    while (i<=gh)
    {
        BIT[k][i]=(BIT[k][i]+gt)%cmod;
        i=i+(i & (-i));
    }
}

long long get(long long i,long long k)
{
    i++;
    long long gt=0;
    while (i>=1)
    {
        gt=(BIT[k][i]+gt)%cmod;
        i=i-(i & (-i));
    }
    return gt;
}

int main()
{
    //freopen("AMSEQT.in","r",stdin);
    //freopen("AMSEQT.out","w",stdout);
    cin>>T;
    while(T>0)
    {
        memset(BIT,0,sizeof(BIT));
        memset(F,0,sizeof(F));
        scanf("%d%d",&n,&m);
        gh=(1<<m);
        FOR(i,1,n)
        {
            scanf("%d",&a[i]);
            s[i]=s[i-1]+a[i];
            d[i]=(s[i]>>(m-1))&1;
            c[i]=s[i]&((1<<(m-1))-1);
            //cout<<s[i]<<' '<<d[i]<<' '<<c[i]<<endl;
        }
        //cout<<n<<' '<<m<<' '<<gh<<endl;
        F[0]=1;
        update(0,0,1);
        FOR(i,1,n)
        {
            F[i]=(get(c[i],d[i])+F[i])%cmod;
            F[i]=(get(gh,1-d[i])-get(c[i],1-d[i])+F[i])%cmod;
            update(c[i],d[i],F[i]);
            //cout<<i<<endl;
        }
        cout<<(F[n]+cmod)%cmod<<endl;
        T--;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

