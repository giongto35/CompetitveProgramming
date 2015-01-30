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
const int maxn=5000+10;
map<int,int> prev;
map<int,bool> exist;
map<int,int> par;
struct range
{
    int u;
    int v;
    int c;
} r[maxn];
int l,n;
string temp;
bool add(int u,int v,int c)
{
    //cout<<t<<' '<<u<<' '<<v<<' '<<c<<endl;
    if (exist[v]==false)
    {
        exist[v]=true;
        prev[v]=u;
        par[v]=c;
        return true;
    }
    else
    {
        if (prev[v]==u) return (c==par[v]);else
        if (prev[v]<u) return add(prev[v],u-1,c!=(par[v]));else
        return add(u,prev[v]-1,par[v]!=c);
    }
}
int main()
{
    //freopen("parity.inp","r",stdin);
    //freopen("parity.out","w",stdout);
    while (true)
    {
        cin>>l;
        if (l==-1) break;
        cin>>n;
        prev.clear();
        exist.clear();
        par.clear();
        FOR(i,1,n)
        {
            cin>>r[i].u>>r[i].v>>temp;
            if (temp=="even") r[i].c=0;else r[i].c=1;
        }
        int res=0;
        FOR(i,1,n)
            if (add(r[i].u,r[i].v,r[i].c)==true) res=i;else break;
        cout<<res<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
