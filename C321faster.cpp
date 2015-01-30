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
const int maxn=100000+10;
vector<int> a[maxn];
vector<bool> ok[maxn];
vector<int> cs[maxn];
int n;
vector<int> c;
int u,v;
int used[maxn];
int cur;
int q[maxn],s[maxn],e[maxn],dx[maxn];
char res[maxn];
int deg[maxn];
int fr,re;

void DFS(int u)
{
    used[u]=cur;
    c.push_back(u);
    FOR(i,0,a[u].size()-1)
    {
        int v=a[u][i];
        if (ok[u][i]&&used[v]!=cur)
            DFS(v);
    }
}

int FindCenter()
{
    re=0;
    FOR(i,0,c.size()-1)
    {
        int u=c[i];
        //cout<<"ABC "<<u<<' ';
        deg[u]=0;
        FOR(j,0,a[u].size()-1)
        {
            int v=a[u][j];
            if (ok[u][j]) deg[u]++;
        }
        if (deg[u]<=1) q[++re]=u,dx[u]=cur;
    }
    //cout<<endl;
    //FOR(i,1,re) cout<<q[i]<<' ';cout<<endl;
    fr=0;
    while (fr<re)
    {
        fr++;
        int u=q[fr];
        FOR(j,0,a[u].size()-1)
        {
            int v=a[u][j];
            if (ok[u][j]&&dx[v]!=cur)
            {
                deg[v]--;
                if (deg[v]==1) {q[++re]=v;dx[v]=cur;}
            }
        }
    }
    return q[re];
}

void compute(int r,char kt)
{
    cur++;
    c.clear();
    DFS(r);
    int u = FindCenter();
    //cout<<"Center : "<<u<<endl;
    res[u]=kt;
    FOR(i,0,a[u].size()-1)
    {
        int v=a[u][i];
        //cout<<"dang xet "<<u<<' '<<v<<' '<<ok[u*(n+1)+v]<<endl;
        if (ok[u][i])
        {
            //cout<<"xet tiep "<<v<<endl;
            ok[u][i]=false;
            ok[v][cs[u][i]]=false;
            //cout<<u<<' '<<i<<endl;
            //cout<<v<<' '<<cs[u][i]<<endl;
            //return ;
            compute(v,kt+1);
        }
    }
}

int main()
{
    //freopen("C321.inp","r",stdin);
    //freopen("C321.out","w",stdout);
    cin>>n;
    FOR(i,1,n-1)
    {
        //cin>>u>>v;
        scanf("%d%d",&u,&v);
        a[u].push_back(v);
        a[v].push_back(u);
        ok[u].push_back(true);
        ok[v].push_back(true);
        cs[u].push_back(a[v].size()-1);
        cs[v].push_back(a[u].size()-1);
    }
    compute(1,'A');
    FOR(i,1,n)
    printf("%c ",res[i]);
    //cout<<res[i]<<' ';
    fclose(stdin);
    fclose(stdout);
    return 0;
}

