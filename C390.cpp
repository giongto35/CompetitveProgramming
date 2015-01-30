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
#define RESET(c,x) memset (c, x, sizeof (c))
#define oo 1000111000
#define PI acos(-1.0)
#define fi first
#define se second
#define SIZE(c) (c).size()

typedef vector<int> VI ;
typedef vector<string> VS ;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;

template<class T> inline int size(const T&c) { return c.size(); }

using namespace std;
int fastMax(int x, int y) { return (((y-x)>>(32-1))&(x^y))^y; }
int fastMin(int x, int y) { return (((y-x)>>(32-1))&(x^y))^x; }

const int maxn = 200000+10;
int a[maxn];
int F1[maxn];
int F0[maxn];
int S[maxn];
int n,k,w;
int l,r;
string st;
int main()
{
    //freopen("C390.inp","r",stdin);
    //freopen("C390.out","w",stdout);
    scanf("%d%d%d",&n,&k,&w);
    cin>>st;
    FOR(i,0,n-1)
    {
        if (i+1 >= k)
        {
            F1[i+1] = F1[i - k+1] + (st[i] == '1');
            F0[i+1] = F0[i - k+1] + (st[i] == '0');
        }
        else
        {
            F1[i+1] = (st[i] == '1');
            F0[i+1] = (st[i] == '0');
        }
        S[i+1] = S[i - 1+1] + (st[i] == '1');
    }
    FOR(i,n+1,n+k) F0[i] = F0[i-k],F1[i]=F1[i-k],S[i]=S[i-1];
    FOR(i,1,w)
    {
        scanf("%d%d",&l,&r);
        int s1 = max(0,F1[r] - F1[l - 1]);
        int s2 = S[r] - S[l-1];
        int s3 = s2 - s1 ;
        int res = max(0,F0[r] - F0[l - 1]) + max(0,s3);
        printf("%d\n",max(0,res));
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

