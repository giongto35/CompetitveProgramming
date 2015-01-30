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
map<int,bool> b;
int n,m,k;
long long a[10+10];
int main()
{
    //freopen("Bhalim3.inp","r",stdin);
    //freopen("Bhalim3.out","w",stdout);
    while(true)
    {
        cin>>n>>m;
        if (n==0&&m==0) break;
        n++;
        b.clear();
        cin>>k;
        FOR(i,0,k) cin>>a[i];
        FOR (i,0,m)
        {
            long long s=0;
            long long x=1;
            FOR(j,0,k)
            {
                s=(s+x*a[j])%n;
                x=(x*i)%n;
            }
            b[s]=true;
        }
            int res=0;
            FOREACH(it,b)
            res++;
            cout<<res<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

