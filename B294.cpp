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
const int maxn=100+10;
int t[maxn],w[maxn];
vector<int> d[3];
int s1[maxn],s2[maxn];
int res,n;
int main()
{
    //freopen("B294.inp","r",stdin);
    //freopen("B294.out","w",stdout);
    cin>>n;
    FOR(i,1,n)
    {
        cin>>t[i]>>w[i];
        d[t[i]].push_back(w[i]);
    }
    sort(d[1].begin(),d[1].end(),greater<int>());
    sort(d[2].begin(),d[2].end(),greater<int>());
    FOR(i,1,d[1].size()) s1[i]=s1[i-1]+d[1][i-1];
    FOR(i,1,d[2].size()) s2[i]=s2[i-1]+d[2][i-1];
    res=100000000;
    FOR(i,0,d[1].size())
    FOR(j,0,d[2].size())
    {
        if (i*1+j*2>=s1[d[1].size()]+s2[d[2].size()]-s1[i]-s2[j])
            res=min(res,i*1+j*2);
    }
    cout<<res<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
