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
const int maxn = 1000+10;
const int maxu = 5000+10;
int a[maxn][10000+10];
//map<int,int> d;
bool b[maxn][maxu];
int c[maxn][10000+10];
int U[maxu];
pair<int,int> Q[maxn*maxu];
int l[maxn*maxu];
int s,f,sum,n,m,u,v,spt,Cost;

void BFS()
{
    Q[1]=make_pair(s,1);
    l[1]=1;
    int fr=0;
    int re=1;
    while(fr<re)
    {
        fr++;
        int u=Q[fr].first;
        int x=Q[fr].second;
        FOR(i,1,a[u][0])
        {
            int v=a[u][i];
            int Cost=c[u][i]+1;
            if (U[x]<=sum/Cost)
            {
                int *vtp=find(U+1,U+1+spt,(U[x]*Cost));
                int vt=*vtp;
                cout<<U[x]<<' '<<U[x]*Cost<<' '<<vtp<<endl;
                if (vtp==U+1+spt||b[v][vt]==true) continue;
                //cout<<vt<<endl;
                b[v][vt]=true;
                Q[++re]=make_pair(v,vt);
                l[re]=l[fr]+1;
                if (Q[re].first==f&&U[vt]==sum)
                {
                    cout<<l[re]<<endl;
                    return;
                }
            }
        }
    }
    cout<<-1<<endl;
}

int main()
{
    freopen("GOHOME.inp","r",stdin);
    //freopen("GOHOME.out","w",stdout);
    cin>>n>>m>>s>>f>>sum;
    FOR(i,1,m)
    {
        scanf("%d%d",&u,&v);
        scanf("%d",&Cost);
        a[u][++a[u][0]]=v;
        c[u][a[u][0]]=Cost;
    }
    sum++;
    FOR(t,1,sqrt(sum))
    {
        if (sum%t==0)
        {
            U[++spt]=t;
            //d[t]=spt;
            if (t*t!=sum)
            {
                U[++spt]=sum/t;
                //d[(sum/t)]=spt;
            }
        }
    }
    sort(U+1,U+spt+1);
    //FOR(i,1,spt) cout<<U[i]<<endl;
    BFS();
    fclose(stdin);
    fclose(stdout);
    return 0;
}


