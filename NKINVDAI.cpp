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
const int maxn = 100000+10;
int a[maxn],b[maxn],c[maxn],d[maxn],n;
long long res;

void merge(int l,int mid,int r)
{
    int i=l;
    int j=mid+1;
    int cnt=0;
    while (i<=mid||j<=r)
    {
        //cout<<i<<' '<<j<<' '<<mid<<' '<<r<<' '<<endl;
        if (i==mid+1) b[++cnt]=a[j++],d[l+cnt-1]=c[j-1];
        else
        if (j==r+1) b[++cnt]=a[i++],d[l+cnt-1]=c[i-1];
        else
        if (a[j]<=a[i]) b[++cnt]=a[j++],d[l+cnt-1]=c[j-1];
        else
        b[++cnt]=a[i++],d[l+cnt-1]=c[i-1];
    }
    FOR(i,1,cnt) a[l+i-1]=b[i];
}

void mergesort(int l,int r)
{
    if (l==r) return;
    int mid = (l+r)/2;
    mergesort(l,mid);
    mergesort(mid+1,r);
    FOR(i,l,mid)  c[i]=1;
    FOR(i,mid+1,r)c[i]=0;
    merge(l,mid,r);
    int cnt=0;
    int t=a[l];
    int tr=l;
    FOR(i,l,r)
    {
        //cout<<d[i]<<' ';
        //cout<<a[i]<<' '<<c[a[i]]<<endl;
        if (a[i]!=t)
        {
            FOR(j,tr,i-1) if (d[j]==1) res+=cnt;
            FOR(j,tr,i-1) if (d[j]==0) cnt++;
            t=a[i];
            tr=i;
        }
    }
    FOR(j,tr,r) if (d[j]==1) res+=cnt;
    FOR(j,tr,r) if (d[j]==0) cnt++;
    //cout<<l<<' '<<mid<<' '<<r<<' '<<res<<endl;

}
int main()
{
    //freopen("NKINV.inp","r",stdin);
    //freopen("NKINV.out","w",stdout);
    cin>>n;
    FOR(i,1,n) cin >>a[i];
    mergesort(1,n);
    cout<<res<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

