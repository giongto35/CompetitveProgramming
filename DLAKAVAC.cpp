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
const int maxn = 1500+10;
const int hashbase = 1000000;
int m,n,vt,bd;
long long k;
int a[maxn],b[maxn],temp[maxn],newm[maxn];
bool freex[maxn];
vector<pair<int,int> > hashs[hashbase+10];
int M2[maxn];
int sl;

void add(int n,int vt)
{
    hashs[abs(n%hashbase)].push_back(make_pair(n,vt));
}

int found(int n)
{
    int gt=abs(n%hashbase);
    FOREACH(it,hashs[gt])
        if (it->first==n) return it->second;
    return 0;
}

int change()
{
    int res=0;
    FOR(i,1,n)
    res=res+M2[a[i]];
    return res;
}
/*
void next()
{
    sl=0;
    FOR(i,1,n)
    FOR(j,1,bd)
    {
        if (freex[(a[i]*a[j])%m]==true)
        {
            a[(++sl)+n]=(a[i]*a[j])%m;
            freex[a[sl+n]]=false;
        }
    }
    n=n+sl;
}
*/
void next()
{
    sl=0;
    memset(freex,true,sizeof(freex));
    FOR(i,1,n)
    FOR(j,1,bd)
    {
        temp[++sl]=(a[i]*b[j])%m;
        if (freex[temp[sl]]==false) sl--;
        else
            freex[temp[sl]]=false;
    }
    n=sl;
    FOR(i,1,n)a[i]=temp[i];
}

int main()
{
    //freopen("dlakavac.inp","r",stdin);
    //freopen("dlakavac.out","w",stdout);
    cin>>k>>m>>n;
    M2[0]=1;
    FOR(i,1,m) M2[i]=M2[i-1]*3;
    FOR(i,0,m-1) freex[i]=true;
    FOR(i,1,n) cin>>a[i],b[i]=a[i],freex[a[i]]=false;
    bd=n;
    for(int i=1;i<=k;i++)
    {
        int y=change();
        int x=found(y);
        //FOR(j,1,n) cout<<a[j]<<' ';
        //cout<<endl;
        if (x!=0)
        {
            int loop=i-x;

//            cout<<"co"<<' '<<i<<' '<<x<<' '<<loop<<endl;
            k-=(x-1);
            k=(k-1)%loop +1;
            k+=(x-1);
            //cout<<k<<endl;
            n=bd;
            FOR(j,1,n) a[j]=b[j],freex[a[j]]=false;
            //cout<<n<<endl;
            FOR(j,2,k) next();
            break;
        }
        add(y,i);
        if (i!=k)next();
    }
    sort(a+1,a+n+1);
    FOR(i,1,n) cout<<a[i]<<' ';
    cout<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

//1 2 3 4 | 5 6 7 | 8
//          x       i
