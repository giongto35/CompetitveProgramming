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

typedef vector<int> VI ;
typedef vector<string> VS ;
template<class T> inline int size(const T&c) { return c.size(); }

using namespace std;
const int maxn = 100000+10;
set<int> s;
bool sa[maxn],sb[maxn];
int va[maxn],vb[maxn];
queue<int> g[maxn];
int a[maxn],b[maxn],c[maxn],cnt[maxn];
int gtmax,res,n,m,p,sl;
int main()
{
    //freopen("search1.inp","r",stdin);
    //freopen("search1.out","w",stdout);
    scanf("%d%d%d",&m,&n,&p);
    FOR(i,1,m) {scanf("%d",&a[i]);if (sa[a[i]]==false) sl++;sa[a[i]]=true;cnt[a[i]]++;}
    FOR(i,1,n) scanf("%d",&b[i]),sb[b[i]]=true;
    FOR(i,1,p) scanf("%d",&c[i]);
    gtmax=1;
    FOR(i,1,p)
    {
        int u=c[i];
        if (sa[u])
        {
             g[u].push(i);
            if (g[u].size()>cnt[u])
            {
                s.erase(g[u].front());
                g[u].pop();
            }
            if (g[u].size()==cnt[u]) s.insert(g[u].front());
        }
        if (sb[u]) gtmax=max(gtmax,i+1);
        //cout<<i<<' '<<gtmax<<' '<<s.size()<<' '<<*(s.begin())<<endl;
        if (s.size()==sl&&gtmax<=*(s.begin()))
            {
                //cout<<i<<' '<<gtmax<<endl;
                res=max(res,i-gtmax+1);
            }
    }
    cout<<res<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

