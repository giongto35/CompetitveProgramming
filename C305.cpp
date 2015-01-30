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
const int maxn=10000000+10;
int a[maxn],cnt;
pair<int,int> b[maxn];
pair<int,int> c[maxn];
int sres,n,spt;
int main()
{
    //freopen("C305.inp","r",stdin);
    //freopen("C305.out","w",stdout);
    cin>>n;
    FOR(i,1,n) cin>>a[i];
    sort(a+1,a+1+n);
    a[0]=-1231;
    a[n+1]=-1252;
    spt=-1;
    FOR(i,1,n+1)
    {
        if (a[i]!=a[i-1])
        {
            ++spt;
            b[spt].first=a[i-1];
            b[spt].second=cnt;
            cnt=0;
        }
        cnt++;
    }
    c[sres].first=-123124;
    FOR(i,1,spt)
    {
        if (c[sres].first!=b[i].first)
        {
            sres++;
            c[sres].first=b[i].first;
            c[sres].second=0;
        }
        c[sres].second=c[sres].second+b[i].second;
        //cout<<i<<' '<<c[sres].first<<' '<<c[sres].second<<endl;
        while (c[sres].second>1)
        {
            sres++;
            c[sres].first =c[sres-1].first+1;
            c[sres].second=c[sres-1].second/2;
            c[sres-1].second%=2;
            //cout<<i<<' '<<c[sres].first<<' '<<c[sres].second<<endl;
            if (i<spt&&c[sres].first==b[i+1].first) break;
        }
    }
    cnt=0;
    FOR(i,1,sres)
    {
        if (c[i].second==1) cnt++;
        //cout<<c[i].first<<' '<<c[i].second<<endl;
    }
    cout<<c[sres].first+1-cnt;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

