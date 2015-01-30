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
#include <iomanip>

using namespace std ;

#define FOREACH(it,c) for( __typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define FOR(i,a,b) for( int i=(a),_b=(b);i<=_b;i++)
#define DOW(i,b,a) for( int i=(b),_a=(a);i>=_a;i--)
#define REP(i,n) FOR(i,0,(n)-1)
#define DEP(i,n) DOW(i,(n)-1,0)
#define all(a) (a).begin() , (a).end()
#define mp(a,b) make_pair((a),(b))
#define fi first
#define se second

typedef vector<int> VI ;
typedef vector<string> VS ;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;

template<class T> inline int size(const T&c) { return c.size(); }

using namespace std;
int fastMax(int x, int y) { return (((y-x)>>(32-1))&(x^y))^y; }
int fastMin(int x, int y) { return (((y-x)>>(32-1))&(x^y))^x; }

const int maxn = 1000000+10;
const int oo=1000000000;
map<long long,int> F;
long long M10[maxn];
long long res;
long long n;
/*
int rec(long long i)
{
    if (i==0) return 0;
    if (F[i]!=0) return F[i];
    //cout<<i<<endl;
    F[i]=oo;
    long long cnt=0;
    FOR(j,0,18)
        {
            if ((i/M10[j])%10!=0)
                cnt=max(cnt,(i/M10[j])%10);
            //F[i]=min(F[i],rec(i-(i/M10[j])%10)+1);
        }
    F[i]=rec(i-cnt)+1;
    return F[i];
}*/
int main()
{
    //freopen("c3331.inp","r",stdin);
    //freopen("C331.out","w",stdout);
    scanf("%d",&n);
    cout<<n<<endl;
    M10[0]=1;
    FOR(i,1,18) M10[i]=M10[i-1]*10;
    int res=0;
    while (n>0)
    {
        long long cnt=0;
        FOR(j,0,18)
            cnt=max(cnt,(n/M10[j])%10);
        n=n-cnt;
        //cout<<n<<' '<<cnt<<endl;
        res++;
    }
    cout<<res<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

