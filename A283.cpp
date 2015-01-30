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
const int maxn=2*100010;
int BIT[maxn];
int b[maxn],a[maxn],s;
long long sum;
int u,v,t,n;

int main()
{
    //freopen("A283.in","r",stdin);
    //freopen("A283.out","w",stdout);
    cin>>s;
    n=1;
    a[1]=0;
    FOR(i,1,s)
    {
        cin>>t;
        if (t==2)
        {
            cin>>u;
            a[++n]=u;;
            sum+=u;
        }
        else
        if (t==1)
        {
            cin>>u>>v;
            sum+=u*v;
            b[u]+=v;
        }
        else
        if (t==3)
        {
            sum=sum-b[n]-a[n];
            b[n-1]+=b[n];
            b[n]=0;
            n--;
        }
        printf("%0.6f\n",(sum+0.0)/n);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

