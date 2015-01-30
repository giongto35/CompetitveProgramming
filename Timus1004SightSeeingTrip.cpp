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
const int oo=1000000000+10;
const int maxn=100+10;
int tr[maxn],d[maxn][maxn],dist[maxn];
pair<int,int> e[maxn*maxn];
int used[maxn],res,resu,resv,ress,n,m,u,v,l;

void solve(int s)
{
    FOR(i,1,n) tr[i]=0;
    FOR(i,1,n) dist[i]=oo,used[i]=false;
    dist[s]=0;
    FOR(k,1,n)
    {
        int u=0;
        FOR(i,1,n)
        {
            if (used[i]==false)
            if (u==0||dist[i]<dist[u]) u=i;
        }
        used[u]=true;
        FOR(i,1,n)
        {
            if (used[i]==false)
            {
                if (dist[i]>dist[u]+d[u][i])
                {
                    dist[i]=dist[u]+d[u][i];
                    tr[i]=u;
                }
            }
        }
    }

    FOR(i,1,m)
    {
        int u=e[i].first;
        int v=e[i].second;
        if (tr[u]!=v&&tr[v]!=u)
        {
            if (res>d[u][v]+dist[u]+dist[v])
            {
                res=d[u][v]+dist[u]+dist[v];
                ress=s;
                resu=u;
                resv=v;
            }
        }
    }
}

void trace(int v,int s, int t)
{
    if (t==1) cout<<v<<' ';
    if (v==s) return;
    trace(tr[v],s,t);
    if (t==2) cout<<v<<' ';
}

int main()
{
    //freopen("SightSeeingTrip.inp","r",stdin);
    //freopen("SightSeeingTrip.out","w",stdout);
    while(true)
    {
        cin>>n>>m;
        if (n==-1) break;
        FOR(i,1,n) FOR(j,1,n) d[i][j]=oo;
        FOR(i,1,m)
        {
            cin>>u>>v>>l;
            d[u][v]=l;
            d[v][u]=l;
            e[i].first=u;
            e[i].second=v;
        }
        res=oo;
        FOR(i,1,n) solve(i);
        solve(ress);
        if (res==oo) cout<<"No solution."<<endl;
        else
        {
            trace(resu,ress,2);
            trace(resv,ress,1);
            cout<<endl;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
