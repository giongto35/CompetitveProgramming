#include <vector>
#include <list>
#include <conio.h>
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
int n,a,b;
int p[maxn];
map<int,int> ma;
int res[maxn];
set<pair<int,int> > s;
int cnt[maxn];
int v;

void update(int u)
{
    if (u == 0) return;
    s.erase(make_pair(cnt[u], u));
    cnt[u]--;
    if (cnt[u] > 0)
    s.insert(make_pair(cnt[u], u));
}

int main()
{
    //freopen("B468.inp","r",stdin);
    //freopen("B468.out","w",stdout);
    scanf("%d%d%d",&n,&a,&b);
    ma.clear();
    for (int i = 1; i <= n; i++)
    {
        scanf("%d",&p[i]);
        ma[p[i]] = i;
    }
    for (int i = 1; i <= n; i++)
    {
        if (ma[a - p[i]] != 0) cnt[i]++;
        if (ma[b - p[i]] != 0) cnt[i]++;
    }
    for (int i = 1; i <= n; i++)
    {
        res[i] = -1;
        if (cnt[i] == 0)
        {
            cout<<"NO"<<endl;
            return 0;
        }
        else
        s.insert(make_pair(cnt[i], i));
    }
    while (s.size() > 0)
    {
        pair<int, int> u = *s.begin();
        bool change = false;
        if (u.first == 0)
        {
            s.erase(make_pair(u.first,u.second));
            continue;
        }
        //for (int i = 1; i <= n; i++) cout<<cnt[i]<<' ';cout<<endl;
        v = ma[a - p[u.second]];
        if (v != 0 && res[v] == -1) {
            change = true;
            res[u.second] = 0;
            res[v] = 0;
            s.erase(make_pair(cnt[u.second], u.second));
            s.erase(make_pair(cnt[v], v));
            cnt[u.second] = 0;
            cnt[v] = 0;
            update(ma[b - p[v]]);
            update(ma[b - p[u.second]]);
        }
        v = ma[b - p[u.second]];
        if (v != 0 && res[v] == -1) {
            change = true;
            res[u.second] = 1;
            res[v] = 1;
            s.erase(make_pair(cnt[u.second], u.second));
            s.erase(make_pair(cnt[v], v));
            //cout<<u.second<<' '<<v<<endl;
            cnt[u.second] = 0;
            cnt[v] = 0;
            update(ma[a - p[v]]);
            update(ma[a - p[u.second]]);
        }
        if (change == false) break;
    }
    for (int i = 1; i <= n; i++)
        if (res[i] == -1)
    {
        cout<<"NO"<<endl;
        return 0;
    }
    cout<<"YES"<<endl;
    for (int i = 1; i <= n; i++) cout<<res[i]<<' ';
    fclose(stdin);
    fclose(stdout);
    return 0;
}


