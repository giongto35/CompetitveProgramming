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
const int maxn=1000+10;
//int a[maxn][maxn];
int ok[maxn];
bool r[maxn],c[maxn];
int res,n,m,x,y,sres;
void process1(bool r[maxn],bool c[maxn])
{
    res=0;
    FOR(i,2,n/2)
    {
        if (c[i]==false) res++;
        if (c[n-i+1]==false) res++;
        if (r[i]==false) res++;
        if (r[n-i+1]==false) res++;
    }
    if (n%2==1)
    {
        if (c[(n+1)/2]==false||r[(n+1)/2]==false) res++;
    }
}
int main()
{
    //freopen("B333.inp","r",stdin);
    //freopen("B333.out","w",stdout);
    cin>>n>>m;
    FOR(i,1,m)
    {
        cin>>x>>y;
        r[y]=true;
        c[x]=true;
    }
    process1(r,c);
    //process1(c,r);
    cout<<res<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}


