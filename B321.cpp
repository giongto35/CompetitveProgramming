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
const int maxn = 100+10;
int a[maxn];
int b[maxn];
int c[maxn];
int str;
string st;
int sa,sb,sc;
int sum,res,cnt,n,m;
bool useda[maxn],usedb[maxn],usedc[maxn];
int main()
{
    //freopen("B321.inp","r",stdin);
    //freopen("B321.out","w",stdout);
    cin>>n>>m;
    FOR(i,1,n)
    {
        cin>>st>>str;
        if (st=="ATK") b[++sb]=str;
        else
        a[++sa]=str;
    }
    FOR(i,1,m) cin>>c[i];
    sc=m;
    sort(a+1,a+1+sa);
    sort(b+1,b+1+sb);
    sort(c+1,c+1+sc);

    //Case 1, kill all
    memset(useda,false,sizeof(useda));
    memset(usedb,false,sizeof(usedb));
    memset(usedc,false,sizeof(usedc));

    cnt=0;
    sum=0;
    FOR(i,1,sa)
        FOR(j,1,sc)
            if (usedc[j]==false&&c[j]>a[i]) {usedc[j]=true;cnt++;break;}
    FOR(i,1,sb)
        FOR(j,1,sc)
            if (usedc[j]==false&&c[j]>=b[i]) {usedc[j]=true;cnt++;sum+=c[j]-b[i];break;}
    if (cnt==n)
    {
        FOR(j,1,sc) if (usedc[j]==false) sum+=c[j];
        res=max(res,sum);
    }
    //Case 2, kill just atk
    FOR(k,1,sb)
    {
        memset(useda,false,sizeof(useda));
        memset(usedb,false,sizeof(usedb));
        memset(usedc,false,sizeof(usedc));
        sum=0;
        cnt=0;
        DOW(i,k,1)
            DOW(j,sc,1)
                if (usedc[j]==false&&c[j]>=b[i]) {usedc[j]=true;cnt++;sum+=c[j]-b[i];break;}
        if (cnt==k) res=max(res,sum);
    }
    cout<<res<<endl;

    fclose(stdin);
    fclose(stdout);
    return 0;
}

