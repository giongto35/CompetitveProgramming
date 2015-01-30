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

int main()
{
    //freopen("","r",stdin);
    freopen("C396.inp","w",stdout);
    int n = 300000;
    int q = 300000;
    cout<<n<<endl;
    for (int i = 2; i<= n; i++)
        cout<<((long long)rand() * rand())%(i-1)+1<<' ';
        cout<<endl;
    cout<<q<<endl;
    for (int i = 1; i<=q; i++)
    {
        int com = rand() % 2 + 1;
        if (com == 1)
        {
            int v = ((long long)rand() * rand())%n + 1;
            int x = ((long long)rand() * rand())%1000000007;
            int k = ((long long)rand() * rand())%1000000007;
            cout<<com<<' '<<v<<' '<<x<<' '<<k<<endl;
        }
        else
        {
            int v = ((long long)rand() * rand())%n + 1;
            cout<<com<<' '<<v<<endl;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

