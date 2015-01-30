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
const int maxn=40000+10;
const int maxm=100000+10;
int n,m,k;
int sa[maxn];
int sb[maxn];
pair<int,int> c[maxm];
int F[maxm];
int G[maxn];
vector<int> a[maxn];
int res;
int main()
{
    freopen("route.inp","r",stdin);
    //freopen("route.out","w",stdout);
    cin>>n>>m>>k;
    FOR(i,1,n) cin>>sa[i];
    FOR(i,1,m) cin>>sb[i];
    FOR(i,1,k)
    {
        cin>>c[i].first>>c[i].second;
        a[c[i].first].push_back(c[i].second);
    }
    FOR(i,1,n) sort(a[i].begin(),a[i].end());
    res=0;
    FOR(i,1,m) G[i]=sb[i];
    FOR(i,1,n) F[i]=sa[i];
    FOR(i,1,n)
    {
        FOR(j,0,a[i].size()-1)
        {
            int v= G[a[i][j]];
            G[a[i][j]]=max(G[a[i][j]],F[i]+sb[a[i][j]]);
            F[i]=max(F[i],v+sa[i]);
        }
        res=max(res,F[i]);
    }
    cout<<res<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

