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
typedef pair<int,int> pii;
typedef vector<int> VI ;
typedef vector<string> VS ;
template<class T> inline int size(const T&c) { return c.size(); }
const int maxn = 100000+10;
const int maxx = 10000000+10;
const int maxbgh = 200;
using namespace std;

pii F[maxbgh][maxn],g[maxn];
int a[maxn],k,t,maxb;
vector<int> b[maxn];
int vtmin[maxn],n;

bool operator <(pii a,pii b)
{
    return a.first<b.first||(a.first==b.first&&a.second<b.second);
}

pii min(pii a,pii b)
{
    if (a<b) return a; else return b;
}

void process()
{
    FOR(j,1,n) g[j]=make_pair(n+1,0);
    g[0]=make_pair(1,0);
    FOR(i,1,maxb)
    {
        if (b[i].size()==0) continue;
        FOR(j,1,n)
        {
            if (g[j-1].first==n+1) continue;
            vector<int>::iterator it=upper_bound(b[i].begin(),b[i].end(),g[j-1].second);
            if (it!=b[i].end())
            {
                F[i][j]=make_pair(g[j-1].first,*it);
            }
            else
                F[i][j]=make_pair(g[j-1].first+1,b[i][0]);
            g[j]=min(g[j],F[i][j]);
        }
    }
    int res = 1;
    FOR(j,1,n) if (g[j].first<=t) res=j;
    cout<<res<<endl;
}

int main()
{
    freopen("D261.inp","r",stdin);
    //freopen("D261.out","w",stdout);
    cin>>k>>n>>maxb>>t;
    FOR(ss,1,k)
    {
        FOR(i,1,maxb) b[i].clear();
        FOR(i,1,n) scanf("%d",&a[i]),b[a[i]].push_back(i);
        FOR(i,1,maxb) sort(b[i].begin(),b[i].end());
        process();
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

