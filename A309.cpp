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
const int maxn=3000000+10;
int n;
long long l,t;
long long a[maxn];
double res;

int bnr_searchl(long long so)
{
    int l=1;
    int r=n*3;
    int res;
    while (l<=r)
    {
        int mid = (l+r)/2;
        if (a[mid]>=so)
        {
            res=mid;
            r=mid-1;
        }
        else
            l=mid+1;
    }
    return res;
}

int main()
{
    //freopen("A309.inp","r",stdin);
    //freopen("A309.out","w",stdout);
    cin>>n>>l>>t;
    t=t*2;
    FOR(i,1,n)
    {
        cin>>a[i];
        a[i+n]=a[i]+l;
        a[i+2*n]=a[i]+2*l;
    }
    FOR(i,n+1,n*2)
    {
        res=res+(long long)(n-1)*(t/l)*0.25;
        long long st=t%l;
        int x=bnr_searchl(a[i]-st);
        //cout<<i<<' '<<x<<endl;
        res=res+(i-x)*0.25;
    }
    printf("%0.6f",res);
    fclose(stdin);
    fclose(stdout);
    return 0;
}

