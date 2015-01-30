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
const int maxn=300+10;
const int oo=1000000000;
int a[maxn],b[maxn];
int d[maxn][maxn],u,v,top,n,e;
struct ketqua
{
    int i;
    int j;
    int d;
} res[maxn*maxn*3];
void add(int i,int j, int d)
{
    a[i]-=d;
    a[j]+=d;
    res[++top].i=i;
    res[top].j=j;
    res[top].d=d;
}

void go(int s,int e,int c)
{
        //cout<<s<<' '<<e<<' '<<d[s][e]<<endl;
    if (d[s][e]==1)
    {
        add(s,e,c);
        return ;
    }
    FOR(i,1,n)
    {
        if (i!=s&&i!=e&&d[i][e]==1&&d[s][e]==d[s][i]+d[i][e])
        {
            if (a[i]>=c)
            {
                add(i,e,c);
                go(s,i,c);
                return ;
            }
            else
            {
                int rem=c-a[i];
                add(i,e,a[i]);
                go(s,i,c);
                add(i,e,rem);
                return ;
            }
        }
    }
}

int main()
{
    //freopen("C317.inp","r",stdin);
    //freopen("C317.out","w",stdout);
    cin>>n>>v>>e;
    FOR(i,1,n) cin>>a[i];
    FOR(i,1,n) cin>>b[i];
    FOR(i,1,n) { FOR(j,1,n) d[i][j]=oo;d[i][i]=0;}
    FOR(i,1,e)
    {
        cin>>u>>v;
        d[u][v]=1;
        d[v][u]=1;
    }
    FOR(k,1,n)
    FOR(i,1,n)
    FOR(j,1,n)
    d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
    FOR(k,1,n*5)
    {
        FOR(i,1,n)
        FOR(j,1,n)
        {
            if (i==j) continue;
            if (a[i]<b[i]&&a[j]>b[j])
            {
                int c=min(b[i]-a[i],a[j]-b[j]);
                go(j,i,c);
            }
        }
    }
    FOR(i,1,n)
    if (a[i]!=b[i])
    {
        cout<<"NO";
        return 0;
    }
    cout<<top<<endl;
    FOR(i,1,top)
    cout<<res[i].i<<' '<<res[i].j<<' '<<res[i].d<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
