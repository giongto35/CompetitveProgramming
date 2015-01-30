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
map<int,int> b;
int cnt,res,n,k,x;
const int maxn=100000+10;
bool vis[maxn];
int a[maxn];
int main()
{
    //freopen("A274.inp","r",stdin);
    //freopen("A274.out","w",stdout);
    cin>>n>>k;
    FOR(i,1,n)
            cin>>a[i];

    sort(a+1,a+1+n);
    FOR(i,1,n)
            b[a[i]]=i;
    FOR(i,1,n)
    {

        if (vis[i]==false)
        {
            x=i;
            vis[i]=true;
            //cout<<x<<endl;
            cnt=1;
            while ((long long)a[x]*k<=1000000000&&b[a[x]*k]!=0&&b[a[x]*k]!=x)
            {
                x=b[a[x]*k];
//                cout<<x<<' '<<a[x]<<' '<<a[x]*k<<' '<<b[a[x]*k]<<endl;
                vis[x]=true;
                cnt++;
            }
            res+=(cnt+1)/2;
        }
    }
    cout<<res<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
//2 3 4 5 6 10
