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
const int maxu = 10000+10;
int a[maxn][maxn];
map<pair<int,int>,bool> d;
int c[maxn][maxn];
pair<int,int> Q[maxn*maxu];
int l[maxn*maxu];
int s,f,sum,n,m,u,v;
void BFS()
{
    Q[1]=make_pair(s,1);
    l[1]=1;
    d[make_pair(s,1)]=true;
    int fr=0;
    int re=1;
    while(fr<re)
    {
        fr++;
        int u=Q[fr].first;
        int x=Q[fr].second;
        //cout<<u<<' '<<x<<endl;
        FOR(i,1,a[u][0])
        {
            int v=a[u][i];
            if (x<=(sum+1)/(c[u][v]+1)&&d[make_pair(v,x*(c[u][v]+1))]==false)
            {
                //cout<<u<<' '<<v<<' '<<c[u][v]<<endl;
                d[make_pair(v,x*(c[u][v]+1))]=true;
                Q[++re]=make_pair(v,x*(c[u][v]+1));
                l[re]=l[fr]+1;
                if (Q[re].first==f&&Q[re].second==sum+1)
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
    //freopen("GOHOME.inp","r",stdin);
    //freopen("GOHOME.out","w",stdout);
    cin>>n>>m>>s>>f>>sum;
    FOR(i,1,m)
    {
        cin>>u>>v;cin>>c[u][v];
        a[u][++a[u][0]]=v;
    }
    BFS();
    fclose(stdin);
    fclose(stdout);
    return 0;
}


