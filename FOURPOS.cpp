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
const int cmod = 1000003;
int a[maxn],b[maxn],a2[maxn],a3[maxn],a4[maxn],t[maxn],vt3[maxn],vt4[maxn],n;
long long res;
vector<pair<int,int> > hash[cmod];


inline int gethash(long long n)
{
    int c=n%cmod;
    FOR(i,0,hash[c].size()-1)
        if (hash[c][i].first == n) return hash[c][i].second;
    //hash[c].push_back(make_pair(n,0));
    return 0;
}

inline void updatehash(long long n,const int gt)
{
    int c=n%cmod;
    FOR(i,0,hash[c].size()-1)
        if (hash[c][i].first == n) { hash[c][i].second+=gt; return; }
    hash[c].push_back(make_pair(n,gt));
    return;
}

inline int bit_get(int i,int jj)
{
    int res=0;
    while (i>=1)
    {
        int j=jj;
        while (j>=1)
        {
            res+=gethash((long long)i*(n+1)+j);//BIT[(long long)i*(n+1)+j];
            j=j- (j&(-j));
        }
        i=i - (i&(-i));
    }
    return res;
}

inline void bit_add(int i,int jj,const int gt)
{
    int res=0;
    while (i<=n)
    {
        int j=jj;
        while (j<=n)
        {
            //BIT[(long long)i*(n+1)+j]+=gt;
            updatehash(i*(n+1)+j,gt);
            j=j+(j&(-j));
        }
        i=i+(i&(-i));
    }
}

void merge(int l,int mid,int r)
{
    int i=l;
    int j=mid+1;
    int cnt=0;
    int sl=0;
    //cout<<"add ";
    FOR(i,l,mid)
    {
        for (;j<=r&&a[j]<a[i];j++)
        {
            b[++cnt]=a[j];
            //cout<<j<<' ';
            bit_add(vt3[a[j]],vt4[a[j]],1);
        }
        b[++cnt]=a[i];
        //cout<<bit_get(vt3[a[i]],vt4[a[i]])<<endl;
        res+=bit_get(vt3[a[i]],vt4[a[i]]);//j-(mid+1);
    }
    //cout<<endl;
    //cout<<"remove ";
    FOR (x,mid+1,j-1) bit_add(vt3[a[x]],vt4[a[x]],-1);//,cout<<x<<' ';cout<<endl;
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
    //freopen("FOURPOS.inp","r",stdin);
    //freopen("NKINV.out","w",stdout);
    cin>>n;
    FOR(i,1,n) {scanf("%d",&a[i]);t[a[i]]=i;}
    FOR(i,1,n) {scanf("%d",&a2[i]);a2[i]=t[a2[i]];}
    FOR(i,1,n) {scanf("%d",&a3[i]);a3[i]=t[a3[i]];}
    FOR(i,1,n) {scanf("%d",&a4[i]);a4[i]=t[a4[i]];}
    FOR(i,1,n) a[i]=a2[i];
    //FOR(i,1,n) cout<<a[i]<<' '<<vt3[i]<<' '<<vt4[i]<<endl;
    //FOR(i,1,n) cout<<a2[i]<<' ';cout<<endl;
    //FOR(i,1,n) cout<<a3[i]<<' ';cout<<endl;
    //FOR(i,1,n) cout<<a4[i]<<' ';cout<<endl;
    reverse(a4+1,a4+1+n);
    FOR(i,1,n) vt3[a3[i]]=i;
    FOR(i,1,n) vt4[a4[i]]=i;
    //FOR(i,1,n) cout<<a[i]<<' ';cout<<endl;
    res=0;
    mergesort(1,n);
    //FOR(i,1,n) cout<<a[i]<<' ';cout<<endl;
    cout<<res<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}


