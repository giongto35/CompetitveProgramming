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
map<long long,bool> b;
int cyc[maxn];
struct edge
{
    int u;
    int v;
} e[maxn];
int n,m;

void swap(int &u,int &v)
{
    int tg;
    tg=u;u=v;v=tg;
}

inline bool c (int u,int v)
{
    return b[(long long)u*(n+1)+v];
}

int random(int n)
{
    return ((long long) rand()*rand())%n;
}

int main()
{
    //freopen("C329.inp","r",stdin);
    //freopen("C329.out","w",stdout);
    cin>>n>>m;
    FOR(i,1,m)
    {
        cin>>e[i].u>>e[i].v;
        b[(long long)e[i].u*(n+1)+e[i].v]=true;
        b[(long long)e[i].v*(n+1)+e[i].u]=true;

    }
    if (m>n)
    {
        cout<<-1;
        return 0;
    }
    FOR(i,0,n-1) cyc[i]=i+1;
    FOR(i,1,50)
    {
        bool ok=true;
        //FOR(i,0,n-1) cout<<cyc[i]<<' ';cout<<endl;
        FOR(j,0,m-1)
            if (c(cyc[j%n],cyc[(j+1)%n])) swap(cyc[(j+1)%n],cyc[random(n)]),ok=false;
        if (ok)
        {
            FOR(i,0,m-1) cout<<cyc[i%n]<<' '<<cyc[(i+1)%n]<<endl;
            return 0;
        }
    }
    cout<<-1<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

