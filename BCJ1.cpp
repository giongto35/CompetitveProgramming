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
const int maxn=10+1;
int t,e,r,n,sE;
int v[maxn];
int d[maxn],c[maxn];
int res;

void duyet(int e,int x,int kq)
{
    if (x==n+1)
    {
        if (res<kq)
        {
            res=kq;
            FOR(i,1,n) c[i]=d[i];
        }
        return;
    }
    //cout<<e<<' '<<x<<' '<<kq<<endl;
    FOR(i,0,e)
    {
        d[x]=i;
        duyet(min(sE,e-i+r),x+1,kq+v[x]*i);
    }
}

int main()
{
    freopen("B-small-attempt0.in","r",stdin);
    freopen("BCJ1AC.out","w",stdout);
    cin>>t;
    FOR(st,1,t)
    {
        cin>>e>>r>>n;
        sE=e;
        //cout<<e<<' '<<r<<' '<<n<<endl;
        //FOR(i,1,n) cout<<v[i]<<' ';
        FOR(i,1,n) cin>>v[i];
        //cout<<endl;
        //cout<<v[1]<<' '<<v[2]<<endl;
        res=0;
        duyet(e,1,0);
        int sum=0;
        FOR(i,1,n)
        {
            //cout<<c[i]<<' ';
            sum=sum+c[i];
        }
        //cout<<endl;
        //cout<<sum<<' '<<n*r+(e-r)<<endl;
        cout<<"Case #"<<st<<": "<<res<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

