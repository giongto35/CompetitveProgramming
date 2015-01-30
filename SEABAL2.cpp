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

template<class T> inline int size(const T&c) { return c.size(); }

using namespace std;
int fastMax(int x, int y) { return (((y-x)>>(32-1))&(x^y))^y; }
int fastMin(int x, int y) { return (((y-x)>>(32-1))&(x^y))^x; }
const int maxn=100000+10;
int l[maxn],r[maxn],a[maxn],sl,sr;
int querycnt[maxn];
int ll[maxn],lr[maxn];
int sq;
vector<int> q[maxn];
bool c[maxn];
int b[maxn];
int s[maxn];
int ans;
int u,n,m;


int getleft(int u)
{
    if (ll[u]==u) return u;
    ll[u]=getleft(ll[u]);
    return ll[u];
}

int getright(int u)
{
    if (lr[u]==u) return u;
    lr[u]=getright(lr[u]);
    return lr[u];
}

int main()
{
    freopen("SEABALlarge.inp","r",stdin);
    freopen("SEABAL2.out","w",stdout);
    scanf("%d%d",&n,&m);
    FOR(i,1,n) scanf("%d",&a[i]);
    FOR(i,1,m)
    {
        scanf("%d%d",&l[i],&r[i]);
        q[l[i]].push_back(i);
        q[r[i]].push_back(i);
        //update(l[i],1);
        //update(r[i],1);
        s[l[i]]++;
        s[r[i]]++;
    }
    a[0]=1000000000;
    a[n+1]=1000000000;
    FOR(i,1,n) ll[i]=i,lr[i]=i;
    scanf("%d",&sq);
    FOR(i,1,sq)
    {
        scanf("%d",&u);
        u=u+ans;
        a[u]--;
        if (a[u]==0)
        {
            if (a[u-1]==0) lr[u-1]=u;
            if (a[u+1]==0) lr[u]=u+1;
            if (a[u+1]==0) ll[u+1]=u;
            if (a[u-1]==0) ll[u]=u-1;
            int pl,pr;
            //FOR(i,1,n) cout<<ll[i]<<' ';cout<<endl;
            //FOR(i,1,n) cout<<lr[i]<<' ';cout<<endl;
            //if (u==5) cout<<getleft(u)<<endl;
            //if (u==5) return 0;
            //if (sum2(getleft(u),u)<sum2(u,getright(u))) pl=getleft(u),pr=u;
            //else
                pl=u,pr=getright(u);
            FOR(j,pl,pr)
            {
                FOR(k,0,q[j].size()-1)
                {
                    if (c[q[j][k]]==false)
                    {
                        int u=l[q[j][k]];
                        int v=r[q[j][k]];
                        if (getright(u)>=v)
                        {
                            ans++;
                            c[q[j][k]]=true;
                            //update(u,-1);
                            //update(v,-1);
                        }
                    }
                }
            }
        }
        cout<<ans<<endl;
    }
    //FOR(i,1,m) cout<<c[i]<<endl;
    //cout<<sum2(1,n)<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

