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
const int maxn=300000+10;
int a[maxn],s[maxn],n,cs,j,T;
int res;
int main()
{
    freopen("Bhalim1.inp","r",stdin);
    //freopen("Bhalim1.out","w",stdout);
    while (scanf("%d%d", &n,&cs) ==2)
    {
        FOR(i,1,n) {
            cin>>a[i];
            s[i]=s[i-1]+a[i];
        }
        j=1;
        res=n+1;
        FOR(i,1,n)
        {
            while (s[i]-s[j]>=cs) j++;
            if (s[i]-s[j-1]>=cs)
            res=min(res,i-j+1);
        }
        if (res==n+1) cout<<0; else cout<<res;
        cout<<endl;
        T--;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

