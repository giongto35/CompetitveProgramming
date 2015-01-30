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
const int maxm=10000+10;
int n,m,u,v,sk;
int a[maxn];
int l[maxm][maxn];
int r[maxm][maxn];
int lab[maxn];
int res;
int le,ri;
pair<int,int> e[maxm];

int getroot(int node)
{
    if (lab[node]==0) return node;
    return lab[node]=getroot(lab[node]);
}
int main()
{
    //freopen("D292.inp","r",stdin);
    //freopen("D292.out","w",stdout);
    cin>>n>>m;
    FOR(i,1,m) cin>>e[i].first>>e[i].second;
    cin>>sk;
    memset(lab,0,sizeof(lab));
    FOR(i,1,m)
    {
        u=getroot(e[i].first);
        v=getroot(e[i].second);
        if (u!=v) lab[u]=v;
        FOR(j,1,n) l[i][j]=lab[j];
    }

    memset(lab,0,sizeof(lab));
    DOW(i,m,1)
    {
        u=getroot(e[i].first);
        v=getroot(e[i].second);
        if (u!=v) lab[u]=v;
        FOR(j,1,n) r[i][j]=lab[j];
    }

    FOR(i,1,sk)
    {
        cin>>le>>ri;
        le--;
        ri++;
        FOR(j,1,n) lab[j]=l[le][j];//,cout<<l[le][j]<<' ';cout<<endl;
        FOR(j,1,n)
        {
            int x=j;int y=r[ri][j];
            //cout<<y<<' ';
            if (y!=0)
            {
                u=getroot(x);
                v=getroot(y);
                if (u!=v) lab[u]=v;
            }
        }
        //cout<<endl;
        res=0;
        FOR(j,1,n) if (lab[j]==0) res++;
        cout<<res<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
