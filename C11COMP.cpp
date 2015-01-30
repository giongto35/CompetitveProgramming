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
const int maxn = 100000+10;
const int oo=1000000000;
int p[maxn],v[maxn],k,q,m,u,n;
vector<int> ke[maxn];
map<int,int> F[maxn];
int d[maxn];
int RP[maxn];
int res[maxn];
map<int,int>::iterator it;

void merge(int x,int y)
{
    int u=RP[x];
    int v=RP[y];
    //cout<<u<<' '<<v<<' '<<F[u].size()<<' '<<F[v].size()<<endl;
    if (F[u].size()<F[v].size())
    {
        int tg=u;
        u=v;
        v=tg;
        RP[x]=RP[y];
    }
    else
        RP[y]=RP[x];
    //cout<<x<<' '<<y<<' '<<u<<' '<<v<<endl;
    //push v to u
    FOREACH(it,F[v])
    {
        //cout<<' '<<(*it).second<<' '<<F[u][(*it).first]<<endl;
        if ((*it).second>0&&F[u][(*it).first]>=0) F[u][(*it).first]+=(*it).second;
        if ((*it).second<0&&F[u][(*it).first]>=0) F[u][(*it).first]=-1;
    }
    FOREACH(it,F[u])
    {
        if ((*it).second>k) F[u][(*it).first]=-1;
        //cout<<(*it).first<<' '<<(*it).second<<endl;
    }
    F[v].clear();

}

void DFS(int x)
{
    //cout<<x<<endl;
    RP[x]=x;
    F[x][v[x]]=1;
    FOR(i,0,ke[x].size()-1) DFS(ke[x][i]);
    FOR(i,0,ke[x].size()-1)
    {
        //cout<<"Canh "<<x<<' '<<ke[x][i]<<endl;
        merge(x,ke[x][i]);
    }
    //if (x==1) cout<<"check "<<x<<" "<<RP[x]<<endl;
    int u=RP[x];
    FOREACH(it,F[u])
    {
        //if (x==1) cout<<"ABC "<<(*it).first<<' '<<(*it).second<<endl;
        if ((*it).second<=k&&(*it).second>0) res[x]++;
    }
    //cout<<"res[2] "<<res[2]<<endl;
    //cout<<x<<endl;
}
int main()
{
    //freopen("C11COMP.inp","r",stdin);
    //freopen("C11COMP.out","w",stdout);
    scanf("%d%d%d",&n,&m,&k);
    FOR(i,2,n)
    {
        scanf("%d",&p[i]);
        ke[p[i]].push_back(i);
    }
    FOR(i,1,n) scanf("%d",&v[i]);
    DFS(1);
    scanf("%d",&q);
    //cout<<"BD"<<endl;
    FOR(i,1,q)
    {
        scanf("%d",&u);
        cout<<res[u]<<endl;
    }
    //cout<<"res[2] "<<res[2]<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

