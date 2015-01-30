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
const int maxn=1000000+10;
const int cmod = 1000000007;
int F[maxn],s[maxn],n,m,k,u,v,r,cnt;
int co[maxn];
vector<int> l[maxn];
map<long long,bool> chash;
pair<int,int> E[maxn];
int st,fn;
long long res;

int pow(int x,int n)
{
    if (n==0) return 1;
    if (n%2==1)
        return ((long long)x*pow(x,n-1))%cmod;
    else
    {
        long long y=pow(x,n/2);
        return (y*y)%cmod;
    }
}

int main()
{
    //freopen("D305.inp","r",stdin);
    //freopen("D305.out","w",stdout);
    cin>>n>>m>>k;
    int umin=n+1;
    //int vmax=0;
    k++;
    st=0;
    fn=n+1;
    FOR(i,1,m)
    {
        cin>>u>>v;
        //vmax=max(vmax,v);
        chash[(long long)u*1000000+v]=true;
        if (v-u!=k&&v-u!=1)
        {
            cout<<0;
            return 0;
        }
        E[i].first=u;
        E[i].second=v;
        if (v-u==k)
        {
            co[u]=true;
            umin=min(umin,u);
            st=max(st,u);
            fn=min(fn,v);
        }
    }
    if (st>=fn)
    {
        cout<<0;
        return 0;
    }
    sort(E+1,E+1+m);
    //if (n==77527) cout<<st<<' '<<fn<<endl;
    if (st!=0)
    {
            res=0;
            FOR(j,st+1,fn)
            {
                if (j-k<1) continue;
                //cout<<j<<' '<<i+k-1-j<<' '<<min(n-k-vt+1,j-vt)<<endl;
                res=(res+((long long)pow(2,fn-1-j)*pow(2,min(n-k-st,j-(st+1))))%cmod)%cmod;
            }

            cnt=0;FOR(j,umin+1,st-1) if (co[j]==false&&j+k<=n)
            {
                res=(res*2)%cmod;
            }
            cout<<res<<endl;
            return 0;
    }
    int res=1;
    FOR(i,1,n-k)
    {
        int r=min(k-1,n-(i+k));
        res=(res+pow(2,r))%cmod;
    }
    cout<<res;

    fclose(stdin);
    fclose(stdout);
    return 0;
}

