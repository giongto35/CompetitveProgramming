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
int a[5000+10];
int F[5000+10];
double x;
int res,n,m;
int main()
{
    //freopen("B269.inp","r",stdin);
    //freopen("B269.out","w",stdout);
    cin>>n>>m;
    FOR(i,1,n)
    {
        cin>>a[i]>>x;
    }
    res=0;
    FOR(i,1,n)
    {
        F[i]=1;
        FOR(j,1,i-1)
        if (a[i]>=a[j]) F[i]=max(F[i],F[j]+1);
        res=max(res,F[i]);
    }
    cout<<n-res;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

