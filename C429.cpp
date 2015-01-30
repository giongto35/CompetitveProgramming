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
int schild[maxn];
int n;
int cnt1;
bool ok;

void dfs(int vt)
{
    if (vt == c.size())
    {
        int sum = 0;
        for (int i = 0; i < vt; i++)
        {
            if (schild[c[i]] + a[c[i]] - 1 == 1) return;
            sum += (a[c[i]] - 1);
            //cout<<"CO "<<a[c[i]]<<' '<<c[i]<<endl;
        }
        if (sum == cnt1) ok = true;
        return;
    }
    for (int i = 0; i < vt; i++)
    {
        int u = c[i];
        if (a[u] > a[c[vt]])
        {
            //cout<<u<<' '<<c[vt]<<' '<<a[u]<<' '<<a[c[vt]]<<endl;
            a[u] -= a[c[vt]];
            schild[u] ++;
            dfs(vt+1);
            schild[u] --;
            //cout<<'-'<<u<<' '<<c[vt]<<endl;
            if (ok) return;
            a[u] += a[c[vt]];
        }
    }
}

bool mycmp(int u,int v)
{
    return a[u] > a[v];
}

int main()
{
    //freopen("C429.inp","r",stdin);
    //freopen("C429.out","w",stdout);
    scanf("%d",&n);
    cnt1 = 0;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d",&a[i]);
        if (a[i]!=1)
            c.push_back(i);
        else
            //q.push_back(i);
            cnt1++;
    }
    sort(c.begin(),c.end(),mycmp);
    if (n == 1)
    {
        if (a[1] == 1) cout<<"YES"; else cout<<"NO";
    }
    else
    if (c.size() * 2 > n - 1)
    {
        cout<<"NO";
        return 0;
    }
    else
    {
        ok = false;
        dfs(1);
        if (ok)
        cout<<"YES";
        else
            cout<<"NO";
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
