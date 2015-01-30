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
int a[maxn],b[maxn],n;
long long res;

void merge(int l,int mid,int r)
{
    int i=l;
    int j=mid+1;
    int cnt=0;
    FOR(i,l,mid)
    {
        for (;j<=r&&a[j]<a[i];j++) b[++cnt]=a[j];
        b[++cnt]=a[i];
        //cout<<j<<' '<<mid<<endl;
        res+=j-(mid+1);
    }
    for (;j<=r;j++) b[++cnt]=a[j];
    FOR(i,1,cnt) a[l+i-1]=b[i];
}

void mergesort(int l,int r)
{
    if (l==r) return;
    int mid = (l+r)/2;
    mergesort(l,mid);
    mergesort(mid+1,r);
    merge(l,mid,r);

}
int main()
{
    //freopen("NKINV.inp","r",stdin);
    //freopen("NKINV.out","w",stdout);
    cin>>n;
    FOR(i,1,n) cin >>a[i];
    //FOR(i,1,n) cout<<a[i]<<' ';cout<<endl;
    res=0;
    mergesort(1,n);
    //FOR(i,1,n) cout<<a[i]<<' ';cout<<endl;
    cout<<res<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

