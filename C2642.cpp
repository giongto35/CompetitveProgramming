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

typedef vector<int> VI ;
typedef vector<string> VS ;
template<class T> inline int size(const T&c) { return c.size(); }

using namespace std;
const int maxn = 100000+10;
const long long low = -100000000000000000LL;
int v[maxn];
int c[maxn];
int a,b;
long long f;
int n,q;
int gtmaxc1,gtmaxc2;
long long res,val;
long long GT[maxn];

void calc()
{
    FOR(i,0,n+1) GT[i]=low;
    GT[n+1]=0;
    gtmaxc1=n+1;
    gtmaxc2=0;
    long long res=0;
    FOR(i,1,n)
    {
        f=GT[c[i]];
        //cout<<i<<endl;
        if (GT[c[i]]!=low) f=max(f,GT[c[i]]+(long long)v[i]*a);
        if (gtmaxc1!=c[i])
        f=max(f,GT[gtmaxc1]+(long long)v[i]*b);
        else
        f=max(f,GT[gtmaxc2]+(long long)v[i]*b);
        if (GT[gtmaxc1]<=f)
        {
            if (gtmaxc1!=c[i]) gtmaxc2=gtmaxc1;
            gtmaxc1=c[i];
        }
        else
        {
            if (c[i]!=gtmaxc1&&GT[gtmaxc2]<f) gtmaxc2=c[i];
        }
        GT[c[i]]=max(GT[c[i]],f);
        res=max(res,f);
    }
    cout<<res<<endl;
}

int main()
{
    //freopen("C264.in","r",stdin);
    //freopen("C264.out","w",stdout);
    cin>>n>>q;
    FOR(i,1,n)scanf("%d",&v[i]);
    FOR(i,1,n)scanf("%d",&c[i]);
    FOR (i,1,q)
    {
        scanf("%d %d",&a,&b);
        calc();
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

