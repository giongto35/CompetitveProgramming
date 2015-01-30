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
const int maxs=200000+10;
const int oo=1000000000;
int g[maxs*2+10];
int a[maxn];
int res,n;
int main()
{
    //freopen("DOBRI.inp","r",stdin);
    //freopen("DOBRI.out","w",stdout);
    cin>>n;
    FOR(i,1,n)
        cin>>a[i];
    FOR(i,0,maxs*2) g[i]=oo;
    FOR(i,1,n)
    FOR(j,1,n)
    g[a[i]+a[j]+maxs]=min(g[a[i]+a[j]+maxs],max(i,j));
    res=0;
    FOR(i,1,n)
    FOR(j,1,i-1)
        if ((a[i]-a[j])>=-maxs&&(a[i]-a[j])<=maxs&&g[a[i]-a[j]+maxs]<i)
        {
            res++;
            break;
        }
    cout<<res<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

