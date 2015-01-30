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

const int maxn = 100000+10;
int n;
int a[maxn];
map<int,int> c;
set<int> res;

int main()
{
    //freopen("C382.inp","r",stdin);
    //freopen("C382.out","w",stdout);
    //scanf("%d%d%d%d%d",&a,&b,&w,&x,&c);
    scanf("%d", &n);
    FOR(i,1,n) scanf("%d",&a[i]);
    if ( n == 1) {cout<<-1; return 0;} else
    if ( n == 2){
        int dist = a[2] - a[1];
        res.insert(a[1] - dist);
        if (dist % 2 == 0)
        res.insert(a[1] + dist / 2);
        res.insert(a[2] + dist);
    } else
    {

        sort(a+1,a+1+n);
        FOR(i,2,n)
            c[a[i] - a[i-1]]++;
        if (c.size() == 1)
        {
            int dist = a[2] - a[1];
            res.insert(a[1] - dist);
            res.insert(a[n] + dist);
        }
        else
        {
            int dist = 1000000000;
            FOREACH(it, c)
            if ((*it).second == n - 2) dist = min(dist,(*it).first);
            if (dist == 1000000000) {cout << 0; return 0;}
            FOR (i,2,n)
            if (a[i] - a[i-1] != dist)
                if (a[i] - a[i-1] == 2 * dist) res.insert((a[i] + a[i-1]) / 2);
                    else{cout<<0; return 0;}
        }
    }
    //sort(res.begin(),res.end());
    printf("%d\n", res.size());
    //FOR(i,0,res.size()-1) printf("%d ", res[i]);
    FOREACH(it,res) printf("%d ",(*it));
    fclose(stdin);
    fclose(stdout);
    return 0;
}

