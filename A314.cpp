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
long long a[2*100000+10];
long long d[2*100000+10];
long long c[2*100000+10];
long long cnt,top,n,k,m;
int main()
{
    //freopen("A314.inp","r",stdin);
    //freopen("A314.out","w",stdout);
    cin>>n>>k;
    top=0;
    m=n;
    FOR(i,1,n)
    {
        cin>>a[i];
        c[++top]=a[i];
        if (top==1) d[top]=0;
        else
            d[top]=d[top-1]+c[top-1]*(top-2);
        /*if (i==5)
        {
            cout<<endl;
            FOR(j,1,top) cout<<c[j]<<' ';cout<<endl;
            cout<<i<<' '<<d[top]<<endl;
        }*/
        if (d[top]-(top-1)*(m-top)*c[top]<k)
        {
            cout<<i<<endl;
            m--;
            top--;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

