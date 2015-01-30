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
string st(1000000,' ');
int cnt[maxn];
int ca,cdot;
long long res;
int sum[maxn];
vector<int> kt;
int main()
{
    //freopen("E412.inp","r",stdin);
    //freopen("","w",stdout);
    getline(cin,st);
    res = 0;

    for (int i = 0 ; i<st.length(); i++)
    {
        if (i == 0) sum[i] = !isalpha(st[i]);else
        sum[i] = sum[i-1] + !isalpha(st[i]);
        if (st[i] == '@' || st[i] == '.')
        {
            cnt[i+1] = 0;
            kt.push_back(i);
        }
        else
        {
            if (isalpha(st[i]) || (st[i] >= '0' && st[i] <= '9') || (st[i] == '_'))
            {
                cnt[i+1] = cnt[i];
                if (isalpha(st[i]))
                    cnt[i+1]++;
            }

            if (kt.size()>=2)
            {
                int u = kt[(int)kt.size()-1];
                int v = kt[(int)kt.size()-2];
                char c1 = st[u];
                char c2 = st[v];
                if (c1 == '.' && c2 == '@' && u - v > 1 && sum[i] - sum[u] == 0)
                {
                    res += (long long)cnt[v];
                }
            }
        }
    }
    cout<<res<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
//gerald.agapov1991@gmail.com
