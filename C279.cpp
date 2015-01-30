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
const int maxn=100000+10;
int a[maxn];
int l[maxn],r[maxn],ql,qr,n,m;
int main()
{
    //freopen("C279.inp","r",stdin);
    //freopen("C279.out","w",stdout);
    cin>>n>>m;
    FOR(i,1,n) cin>>a[i];
    l[n]=n;
    DOW(i,n-1,1)
    if (a[i]<=a[i+1]) l[i]=l[i+1];else l[i]=i;
    r[1]=1;
    FOR(i,2,n)
    if (a[i]<=a[i-1]) r[i]=r[i-1];else r[i]=i;
    //FOR(i,1,n) cout<<l[i]<<' ';cout<<endl;
    //FOR(i,1,n) cout<<r[i]<<' ';cout<<endl;

    FOR(i,1,m)
    {
        cin>>ql>>qr;
        int u=l[ql];
        int v=r[qr];
        if (u>=qr) cout<<"Yes"<<endl;
        else
        if (v<=ql) cout<<"Yes"<<endl;
        else
        if (u>=v) cout<<"Yes"<<endl;
        else
        cout<<"No"<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

