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

const int maxn = 1000000+10;
int s0,s1;
string st;
string f;
int cnt[maxn];
int main()
{
    //freopen("C401.inp","r",stdin);
    // freopen("C401.out","w",stdout);
    cin>>s0>>s1;

    if (s1 < s0 - 1)
    {
        cout<<-1;
        return 0;
    }
    if (s1 > s0 * 2 + 2)
    {
        cout<<-1;
        return 0;
    }
    int l = s0 + s1;
    int t1 = s1 - (s0 - 1);
    for (int i = 2; i <= s0; i++)
        cnt[i] = 1;
        //0101010
        //11011011011011
        //cout<<t1<<endl;
    for (int i = 1; i <= s0+1; i++)
    {
        int v = min(t1,2-cnt[i]);
        t1 -= v;
        cnt[i] += v;
    }
    if (t1 > 0)
    {
        cout<<-1;
        return 0;
    }
    for (int i = 1; i <= s0+1; i++)
    {
        for(int j = 1; j <= cnt[i]; j++)
        printf("1");
        if (i < s0+1)
        printf("0");

    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

