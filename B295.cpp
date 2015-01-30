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
const int maxn=500+10;
int a[maxn][maxn];
int d[maxn];
int c[maxn][maxn];
int l[maxn];
bool mark[maxn];
int n;
long long kq[maxn];
const int oo=1000000000;
int spt;
long long res;
/*
void dijkstra(int root)
{
    memset(mark,false,sizeof(mark));
    FOR(i,1,spt)
    c[root][root]=0;
    while(true)
    {
        int gtmin=1000000000;
        u=0;
        FOR(i,1,spt)
        {
            int v=l[i];
            if (mark[v]==false)
            {
                if (gtmin>k[v])
                {
                    gtmin=k[v];
                    u=v;
                }
            }
        }
        if (u==0) break;
        mark[u]=true;
        FOR(i,1,spt)
        {
            int v=l[i];
            if (mark[v]==false)
                c[root][v]=min(c[root][v],c[root][u]+a[u][v]);
        }
    }
}*/

int main()
{
    //freopen("B295.in","r",stdin);
    //freopen("B295.out","w",stdout);
    cin>>n;
    FOR(i,1,n)
    FOR(j,1,n) cin>>a[i][j];
    FOR(i,1,n)
        cin>>d[i];
    FOR(i,1,n)
    {
        FOR(j,1,n) c[i][j]=oo;
        c[i][i]=0;
    }
    DOW(i,n,1)
    {
        int u=d[i];
        l[++spt]=u;
        //dijkstra(d[i]);
        FOR(jj,1,spt-1)
        FOR(kk,1,spt-1)
        {
            int j=l[jj];
            int k=l[kk];
            c[u][k]=min(c[u][k],a[u][j]+c[j][k]);
            c[k][u]=min(c[k][u],c[k][j]+a[j][u]);
        }
        res=0;
        FOR(jj,1,spt)
        FOR(kk,1,spt)
        {
            int j=l[jj];
            int k=l[kk];
            c[j][k]=min(c[j][k],c[j][u]+c[u][k]);
            res=res+c[j][k];
        }
        kq[i]=res;
    }
    FOR(i,1,n)
    cout<<kq[i]<<' ';
    fclose(stdin);
    fclose(stdout);
    return 0;
}

