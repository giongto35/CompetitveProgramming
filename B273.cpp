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
int a[maxn];
int b[maxn];
pair<int,int> c[maxn*2];
int m,n,spt,bd,kt;
long long res;
int main()
{
    //freopen("B273.inp","r",stdin);
    //freopen("B273.out","w",stdout);
    cin>>n;
    spt=0;
    FOR(i,1,n) {
        cin>>a[i];
        c[++spt].first=a[i];
        c[spt].second=i;
    }

    FOR(i,1,n) {
        cin>>b[i];
        c[++spt].first=b[i];
        c[spt].second=i;
    }
    cin>>m;
    sort(c+1,c+1+spt);
    res=1;
    c[0].first=-123;
    c[spt+1].first=-123;
    FOR(i,1,spt+1)
    {
        if (c[i].first!=c[i-1].first) bd=i;
        if (c[i].first!=c[i+1].first)
        {
            kt=i;
            //cout<<bd<<' '<<kt<<endl;
            FOR(k,bd,kt)
            {
                if (k>bd&&c[k].second==c[k-1].second)
                {
                    long long s= ((long long)(k-bd+1)*(k-bd))/2;
                    s%=m;
                    res=(res*s)%m;
                }
                else
                if (k==kt||(k<kt&&c[k].second!=c[k+1].second))
                    res=(res*(k-bd+1))%m;
            }
        }
    }
    cout<<res<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}












