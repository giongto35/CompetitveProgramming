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

const int maxn = 200+10;
int smin[maxn];
int smax[maxn];
int t,x,y,v;
int r[maxn];
int le[maxn];
int ri[maxn];
vector<int> e[maxn];
int li[maxn];
bool vis[maxn];
int n,m;

bool find (int u)
{
    if (vis[u]) return false;
    vis[u]=true;
    FOR(i,0,e[u].size()-1)
    {
        int v=e[u][i];
        if (li[v]==0||find(li[v]))
        {
            li[v]=u;
            return true;
        }
    }
    return false;
}

int main()
{
    //freopen("informac.inp","r",stdin);
    //freopen("informac.out","w",stdout);
    scanf("%d%d",&n,&m);
    FOR(i,1,n) smin[i]=1,smax[i]=n,le[i]=1,ri[i]=n;
    FOR(i,1,m)
    {
        scanf("%d%d%d%d",&t,&x,&y,&v);
        le[v]=max(le[v],x);
        ri[v]=min(ri[v],y);
        FOR(j,x,y)
        {
            if (t==1) smax[j]=min(smax[j],v);
            else smin[j]=max(smin[j],v);
            smin[j]=max(smin[j],1);
            smax[j]=min(smax[j],n);
        }
    }
    FOR(i,1,n)//i la gia tri
    {
        FOR(j,le[i],ri[i])
        {
            if (i>=smin[j]&&i<=smax[j])
                e[i].push_back(j);
        }
    }/*
    FOR(i,1,n)
    {
        cout<<e[i].size()<<endl;
        FOR(j,0,e[i].size()-1) cout<<e[i][j]<<' ';cout<<endl;
    }*/
    bool ok=true;
    FOR(i,1,n)
    {
        memset(vis,false,sizeof(vis));
        if (find(i)==false) {ok=false;break;}
        //FOR(i,1,n) cout<<li[i]<<' ';
    }
    if (ok)
        FOR(i,1,n) cout<<li[i]<<' ';//printf("%d%c",li[i]," \n"[i==n]);
    else
        cout<<-1;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
