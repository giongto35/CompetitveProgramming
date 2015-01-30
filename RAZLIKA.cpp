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
const int maxn = 1000000+10;
int a[maxn],n,k,bot,res;
int top,st[maxn],gt[maxn];
int main()
{
    //freopen("razlika.inp","r",stdin);
    //freopen("razlika.out","w",stdout);
    cin>>n>>k;
    FOR(i,1,n)
    scanf("%d",&a[i]);
    sort(a+1,a+1+n);
    k=n-k;
    bot=1;
    top=0;
    res=1000000000;
    FOR (i,2,k-1)
    {
        while (top>=bot&&gt[top]>a[i]-a[i-1]) top--;
        st[++top]=i;
        gt[top]=a[i]-a[i-1];
    }
    FOR (i,k,n)
    {
        while (top>=bot&&st[bot]<i-k+2) bot++;
        while (top>=bot&&gt[top]>a[i]-a[i-1]) top--;
        st[++top]=i;
        gt[top]=a[i]-a[i-1];
        //cout<<gt[bot]<<' '<<a[i]<<' '<<a[i-k+1]<<endl;
        res=min(res,gt[bot]+a[i]-a[i-k+1]);
    }
    cout<<res;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
