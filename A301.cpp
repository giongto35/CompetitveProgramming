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
const int maxn=200+10;
int a[maxn];
int s1,s2,res,n;
int main()
{
    //freopen("A301.inp","r",stdin);
    //freopen("A301.out","w",stdout);
    cin>>n;
    s1=0;
    FOR(i,1,n*2-1)
    {
        cin>>a[i];
        s1+=a[i];
    }
    sort(a+1,a+(n*2));
    if (n%2==0)
    {
        for(int i=0;i<=2*n-2;i+=2)
        {
            s2=s1;
            FOR(j,1,i) s2=s2-(2*a[j]);
            res=max(res,s2);
        }
    }
    else
    {
        for(int i=0;i<=2*n-1;i+=1)
        {
            s2=s1;
            FOR(j,1,i) s2=s2-(2*a[j]);
            res=max(res,s2);
        }

    }
    cout<<res<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

