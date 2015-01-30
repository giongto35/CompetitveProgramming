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
#include <ctime>
#include <cstring>
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
const int maxn = 1000000+10;
int sl[maxn];
bool prime[maxn],ok[maxn];
int i,j,n,m;
long long res;
int s[maxn],G[maxn],F[maxn];
int T;
int spt;

void sieve(int n)
{
    memset(prime,true,sizeof(prime));
    memset(ok,true,sizeof(ok));
    FOR(i,1,1000000)sl[i]=1,s[i]=1;
    i=2;
    while (i<=n)
    {
        if (prime[i])
        {
            sl[i]=-1;s[i]=i;
            for(j=i+i;j<=n;j+=i)
            {
                prime[j]=false;
                sl[j]=-sl[j];
                s[j]*=i;
            }
        }
        i++;
    }
    spt=0;
    FOR(i,1,n)
    if (s[i]==i) G[++spt]=i,F[spt]=sl[i];
    //cout<<sl[2]<<' '<<sl[4]<<' '<<sl[8]<<' '<<sl[3]<<' '<<sl[6]<<' '<<sl[12]<<' '<<sl[10]<<' '<<sl[30]<<' '<<sl[2*3*5*7]<<endl;
}

int main()
{
    //freopen("RAYGUN.inp","r",stdin);
    //freopen("RAYGUN.out","w",stdout);
    cin>>T;
    sieve(1000000);
    FOR(ct,1,T)
    {
        scanf("%d%d",&n,&m);
        res=0;
        FOR(i,1,spt){
            if (n<G[i]) break;
            //cout<<F[i]<<' '<<G[i]<<endl;
            res=res+(long long)F[i]*(n/G[i])*(m/G[i]);
        }
        printf("Case %d: %lld\n",ct,res+(n!=0)+(m!=0));
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
