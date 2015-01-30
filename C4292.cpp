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

const int maxn = 30;
int a[maxn];
vector<int> c;
deque<int> q;
bool used[maxn];
bool ok;
int n;

void dfs(int vt)
{
    if (vt == c.size())
    {
        if (q.size() == 1)
        ok = true;
        return;
    }
    int sum = 0;
    int v;
    for (int i = 0; i < c.size(); i++)
    {
        v = c[i];
        vector<int> x;
        x.clear();
        if (used[v] == false)
        {
            sum = 0;
            used[v] = true;
            while (q.size() > 0 && sum + a[q.front()] <= a[v] - 1)
            {
                sum += a[q.front()];
                x.push_back(q.front());
                q.pop_front();
            }
            q.push_back(v);
            if (sum == a[v]-1 && x.size() > 1) dfs(vt+1);
            if (ok) return;
            used[v] = false;
            q.pop_back();
            for (int j = 0; j < x.size(); j++) q.push_back(x[j]);
        }
    }
}

int main()
{
    //freopen("C429.inp","r",stdin);
    //freopen("C429.out","w",stdout);
    scanf("%d",&n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d",&a[i]);
        if (a[i]!=1)
            c.push_back(i);
        else
            q.push_back(i);
    }
    ok=false;
    dfs(0);
    if (ok)
    {
        cout<<"YES";
    }
    else
        cout<<"NO";
    fclose(stdin);
    fclose(stdout);
    return 0;
}

