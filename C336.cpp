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
const int maxn=100000+10;
const int oo=1000000000+10;
const int maxcs=32;
int n,a[maxn];
int main()
{
    //freopen("C336.inp","r",stdin);
    //freopen("C336.out","w",stdout);
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d",&a[i]);
    int m2;
    DOW(i,log2(oo),0)
    {
        int t=-1;
        int cnt=0;
        FOR(j,1,n)
        {
            if (((a[j]>>i)&1)==1)
            {
                cnt++;
                if (t==-1) t=a[j];
                else t=t&a[j];
            }
        }
        if (t % (1<<i) == 0)
        {
            cout<<cnt<<endl;
            FOR(j,1,n)
            {
                if (((a[j]>>i)&1)==1)
                {
                    cout<<a[j]<<' ';
                }
            }
            return 0;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

