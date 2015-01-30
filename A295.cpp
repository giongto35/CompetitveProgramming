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
long long l[maxn],r[maxn],d[maxn],s[maxn],res[maxn],a[maxn];
int n,m,k;

int main()
{
    //freopen("A295.in","r",stdin);
    //freopen("A295.out","w",stdout);
    cin>>n>>m>>k;
    FOR(i,1,n) cin>>a[i];
    FOR(i,1,m)
    {
        cin>>l[i]>>r[i]>>d[i];
    }
    FOR(i,1,k)
    {
        int u,v;
        cin>>u>>v;
        s[u]++;
        s[v+1]--;
    }
    FOR(i,1,m)
    {
        s[i]=s[i-1]+s[i];
        //cout<<s[i]<<' '<<d[i]<<endl;
        res[l[i]]+=s[i]*d[i];
        res[r[i]+1]-=s[i]*d[i];
    }
    FOR(i,1,n) res[i]=res[i-1]+res[i];
    FOR(i,1,n)
    cout<<res[i]+a[i]<<' ';

    fclose(stdin);
    fclose(stdout);
    return 0;
}

