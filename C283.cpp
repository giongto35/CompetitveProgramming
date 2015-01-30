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
const int maxs=100000+10;
const int cmod=1000000007;
int next[maxn],deg[maxn];
int a[maxn];
long long c[maxn];
int b[maxn];
long long F[maxs];
bool used[maxn];
long long t;
int n,q,u,v,spt;
int main()
{
    //freopen("C283.in","r",stdin);
    //  freopen("C283.out","w",stdout);
    cin>>n>>q>>t;
    FOR(i,1,n) cin>>a[i];
    FOR(i,1,q)
    {
        cin>>u>>v;
        next[v]=u;
        deg[u]++;
    }
    int dem=0;
    FOR(i,1,n)
    if (deg[i]==0)
    {
        int v=i;
        spt=1;b[1]=v;c[v]=a[v];
        used[v]=true;
        //cout<<v<<' ';
        int sl=0;
        dem++;
        while (next[v]!=0)
        {
            v=next[v];
        dem++;
            if (used[v])
            {
                cout<<0;
                return 0;
            }
            used[v]=true;
            //cout<<v<<' ';
            b[++spt]=v;
            FOR(j,1,spt)
            c[b[j]]+=a[v];
            sl++;
            t-=a[v]*sl;
        }
        //cout<<endl;
    }
    if (dem!=n)
    {
        cout<<0;
        return 0;
    }
    //FOR(i,1,n) cout<<c[i]<<' ';cout<<endl;
    if (t<0)
    {
        cout<<0;
        return 0;
    }
    F[0]=1;
    FOR(i,1,n)
    {
        //cout<<c[i]<<endl;
        FOR(j,c[i],t)
        F[j]=(F[j]+F[j-c[i]])%cmod;
        //FOR(j,0,t) cout<<F[j]<<' ';
        //cout<<endl;
    }
    cout<<F[t]<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

