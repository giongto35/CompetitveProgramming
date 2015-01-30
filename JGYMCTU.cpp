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

const int maxn = 1000+10;
string s;
map<string, int> c;
int q;
int n,T;
int a[maxn];

int findfarthest(int pos)
{
    int val = a[pos];
    int res = pos;
    for (int i = 1; i <= n; i++)
    {
        if (val == i) continue;
        int temp = q + 1;
        for (int j = pos; j <= q; j++)
        {
            if (a[j] == i)
            {
                temp = j;
                break;
            }
        }
        res = max(res, temp);
    }
    return res;
}

int main()
{
    freopen("JGYMCTU.inp","r",stdin);
    //freopen("JGYMCTU.out","w",stdout);
    scanf("%d",&T);
    for (; T > 0; T--)
    {
        c.clear();
        scanf("%d",&n);
        getline(cin,s);
        for (int i = 1; i <= n; i++)
        {
            getline(cin,s);
            c[s] = i;
        }
        scanf("%d",&q);
        getline(cin,s);
        for (int i = 1; i <= q; i++)
        {
            getline(cin,s);
            a[i] = c[s];
        }
        int cur = 0;
        int res = -1;
        while (cur <= q)
        {
            res++;
            cur = findfarthest(cur);
            //cout<<cur<<endl;
        }
        cout<<res<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

