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
const int maxn=10000+10;
const int oo=1000000000+100;
vector<pair<int,int> > a[maxn];
int n,m,s,t,p,l,r,mid,cap,gh,u,v,c;
long long F[maxn];
bool mark[maxn];
long long rec(int u)
{
    if (u==t) return 0;
    if (mark[u]) return F[u];
    mark[u]=true;
    F[u]=0;
    FOR(i,0,a[u].size()-1)
    {
        int v=a[u][i].first;
        if (a[u][i].second<=gh)
            F[u]=max(F[u],rec(v)+a[u][i].second);
    }
    return F[u];
}

bool check(int cap)
{
    gh=cap;
    memset(mark,false,sizeof(mark));
    memset(F,0,sizeof(F));
//    cout<<rec(s)<<endl;
    if (rec(s)>p) return false;
    else return true;
}

long long rec2(int u)
{
    if (u==t) return 0;
    if (mark[u]) return F[u];
    mark[u]=true;
    F[u]=oo;
    FOR(i,0,a[u].size()-1)
    {
        int v=a[u][i].first;
        F[u]=min(F[u],rec2(v)+a[u][i].second);
    }
    return F[u];
}

bool checkimpossible()
{
    memset(mark,false,sizeof(mark));
    if (rec2(s)>p) return true; else return false;
}


int main()
{
    //freopen("Hfinal.inp","r",stdin);
    //freopen("Hfinal.out","w",stdout);
    int T;
    cin>>T;
    while (T>0)
    {
        scanf("%d%d%d%d%d",&n,&m,&s,&t,&p);
        FOR(i,1,n) a[i].clear();
        r=0;
        l=oo;
        FOR(i,1,m)
        {
            scanf("%d%d%d",&u,&v,&c);
            r=max(r,c);
            l=min(l,c);
            a[u].push_back(make_pair(v,c));
        }
        if (checkimpossible())
        {
            cout<<-1<<endl;
            T--;
            continue;
        }
        int res=-1;
        while (l<=r)
        {
            int mid=(l+r)/2;
            if (check(mid))
            {
                res=mid;
                l=mid+1;
            }
            else
                r=mid-1;
        }
        cout<<res<<endl;
        T--;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

