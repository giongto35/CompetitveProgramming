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

const int maxn = 100+10;
int T;
bool ok[maxn];
vector<int> s;
int ste;
int n;
long long F[1000000 + 10];
int ch[1000000 + 10];

int calc(int u)
{
    int res = 0;
    while (u > 0)
    {
        if (ok[u % 10])
            res = res + 1;
        else
            return oo;
        u /= 10;
    }
    return res;
}

int main()
{
    freopen("C-large.in","r",stdin);
    freopen("CAPAC.out","w",stdout);
    scanf("%d",&T);
    for (ste = 1; ste <= T; ste++)
    {
        for (int i = 0; i <= 9; i++)
        {
            scanf("%d",&ok[i]);
        }
        scanf("%d",&n);
        s.clear();
        for (int i = 1; (long long)i * i <= n; i++) {
            if (n % i == 0)
            {
                s.push_back(i);
                s.push_back(n / i);
            }
        }
        sort(s.begin(), s.end());

        for (int i = 0; i < s.size(); i++)
        {
            F[i] = calc(s[i]);
        }
        for (int i = 0; i < s.size(); i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (s[i] % s[j] == 0 && F[j] < oo)
                {
                    //cout<<i<<' '<<j<<' '<<s[i]<<' '<<s[j]<<' '<<F[i]<<' '<<F[j]<<' '<<ch[i]<<endl;
                    F[i] = min(F[i], F[j] + calc(s[i] / s[j]) + 1);
                }
            }
            //cout<<s[i]<<' '<<F[i]<<endl;
        }
        if (F[s.size() - 1] >= oo)
        cout<<"Case #"<<ste<<": "<<"Impossible"<<endl;
        else
        cout<<"Case #"<<ste<<": "<<F[s.size()-1] + 1<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

