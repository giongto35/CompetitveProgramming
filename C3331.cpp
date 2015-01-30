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
typedef pair<long long,long long> pli;

template<class T> inline int size(const T&c) { return c.size(); }

using namespace std;
int fastMax(int x, int y) { return (((y-x)>>(32-1))&(x^y))^y; }
int fastMin(int x, int y) { return (((y-x)>>(32-1))&(x^y))^x; }
const int maxn = 100;
long long n;
map<pli,pli> F;
long long pow10[maxn];
// 1st : so am tiep theo
// 2nd : so luong can -

int sochuso(long long n)
{
    int res=1;
    while (n/10 > 0) res++,n/=10;
    return res;
}

pli rec(long long n,long long maxd)
{
    //cout<<"VAO "<< n<<' '<<maxd<<endl;
    if (n==0&&maxd==0) return pli(0,0);
    if (F.count(pli(n,maxd))) return F[pli(n,maxd)];
    long long nn=n;
    long long res=0;
    long long scs=sochuso(n);
    if (maxd==0&&scs==1) return pli(0,1);
    if (scs==1)
        {
            int cnt=0;
            while (n>=0)
            {
                n-=max(n,maxd),cnt++;
                if (n==0&&maxd==0) break;
            }
            F[pli(nn,maxd)]=pli(n,cnt);
            return F[pli(nn,maxd)];
        }
    int d=n / pow10[scs-1];
    n%=pow10[scs-1];
    for (long long i=d;i>=0;i--)
    {
        //cout<<n<<' '<<d<<endl;
        pli temp=rec(n,max(maxd,i));
        n=temp.first+pow10[scs-1];
        res=res+temp.second;
    }
    //cout<<9*pow10[scs-1]+n<<' '<<res<<endl;
    F[pli(nn,maxd)]=pli(n-pow10[scs-1],res);
    return F[pli(nn,maxd)];
}

int main()
{
    //freopen("C3331.inp","r",stdin);
    //freopen("C3331.out","w",stdout);
    cin>>n;
    pow10[0]=1;
    FOR(i,1,19) pow10[i]=pow10[i-1]*10;
    cout<<rec(n,0).second;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

