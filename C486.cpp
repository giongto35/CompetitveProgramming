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
string st;
int res;
int cnt[maxn];
int n,p;
int main()
{
    //freopen("C486.inp","r",stdin);
    //freopen("C486.out","w",stdout);
    scanf("%d%d",&n,&p);
    getline(cin,st);
    getline(cin,st);
    int i = 0;
    int j = st.length()-1;
    while (i < j) {
        int val = abs(st[i] - st[j]);
        val = min(val, st[i] - 'a' + 1 + 'z' - st[j]);
        val = min(val, st[j] - 'a' + 1 + 'z' - st[i]);
        cnt[i] = val;
        cnt[j] = val;
        //cout<<st[i]<<' '<<st[j]<<' '<<i<<' '<<cnt[i]<<endl;
        i++;
        j--;
    }

    if (p > n / 2) p = (n + 1 - p);

        p--;
        int l = n + 1;
        int r = -1;
        int res = 0;
        for (int i = 0; i < n/2; i++) {
            if (cnt[i] > 0) {
                l = min(l, i);
                r = max(r, i);
                res = res + cnt[i];
            }
        }
        //cout<<res<<endl;
        if (l > r); else {
            res = res + min(abs(r - p) + abs(l - r), abs(p - l) + abs(l - r));
        }
    cout<<res<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

