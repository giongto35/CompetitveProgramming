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
const int maxn = 100+10;
const int maxso= 1000000+10;
int A[maxn],B[maxn];
int snt[maxso];
bool prime[maxso];
long long res[maxn];
int s[maxn];
int spt;
int sl;
int T;
int n,m;
int dx;

void sieve(int n)
{
    memset(prime,true,sizeof(prime));
    int i=2;
    int j;
    while (i*i<=n)
    {
        if (prime[i])
        {
            j=i*i;
            while (j<=n)
            {
                prime[j]=false;
                j+=i;
            }
        }
        i++;
    }
    FOR(i,2,n) if (prime[i]) snt[++spt]=i;
}

void DFS(int vt,int product,int dau)
{
    if (vt==sl+1)
    {
        //cout<<product<<"product"<<endl;
        //cout<<A[1]<<' '<<dx<<endl;
        FOR(i,1,T)
            if (dx<=A[i])
                {
                    //cout<<B[i]/product<<"b[i]/product"<<endl;
                    res[i]+=dau*(B[i]/product);
                }
        return;
    }
    DFS(vt+1,product*s[vt],dau*(-1));
    DFS(vt+1,product,dau);
}

void Process(int so)
{
    sl=0;
    dx=so;
    FOR(i,1,spt)
    {
        if (so%snt[i]==0)
        {
            s[++sl]=snt[i];
            while (so%snt[i]==0) so/=snt[i];
        }
        if ((long long)snt[i]*snt[i]>so)break;
        if (so==1) break;
    }
    if (so>1) s[++sl]=so;
    DFS(1,1,1);
}

int main()
{
    //freopen("raygun.inp","r",stdin);
    //freopen("raygun.out","w",stdout);
    cin>>T;
    int ms=0;
    FOR (i,1,T)
    {
        scanf("%d%d",&n,&m);
        if (n<m) A[i]=n,B[i]=m;else A[i]=m,B[i]=n;
        ms=max(ms,A[i]);
    }
    sieve(ms);
    FOR(i,1,ms)
        Process(i);
    FOR(i,1,T)
    {
        printf("Case %d: %lld\n",i,res[i]+(n!=0)+(m!=0));
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

