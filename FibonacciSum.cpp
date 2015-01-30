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
long long n,m,cnt,T;
long long F[1000],S[1000];

long long sum(long long n)
{
    n--;
    return S[cnt-1] * (n / cnt) + S[n % cnt];
}

int main()
{
    //freopen("FibonacciSum.inp","r",stdin);
    //freopen("FibonacciSum.out","w",stdout);
    scanf("%d",&T);


    F[0] = 1;S[0] = 1;
    F[1] = 1;S[1] = 2;
    for (cnt = 2; !(F[cnt-2] == 1 && F[cnt-1] == 1 && cnt != 2); cnt++)
        {
            F[cnt] = (F[cnt-1] + F[cnt-2])% 100;
            S[cnt] = S[cnt-1] + F[cnt];
        }
    cnt -= 2;
    for (int i  =1 ;i <= T; i++)
    {
        cin>>n>>m;
        cout<<sum(m) - sum (n-1)<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

