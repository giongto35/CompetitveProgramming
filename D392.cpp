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
int a[3][maxn];
map<int, bool> m;
map<int, int> vt[3];
vector<pair<int,int> > c[3];
set<int,greater<int> > s[3];
int res;
int n;

void preprocessing()
{
    for (int x = 0; x <= 2; x++)
    {
        m.clear();
        for (int i = 1; i <= n; i++)
        {
            if (m[a[x][i]] == false)
            {
                m[a[x][i]] = true;
                c[x].push_back(make_pair(a[x][i], i));
                vt[x][a[x][i]] = c[x].size()-1;
            }
        }
    }

}

void process()
{
    for (int i = 1; i <= 2; i++)
        for (int j = 0; j < c[i].size(); j++)
            s[i].insert(j);
    int bd = -1;
    for (int i = (int)c[0].size() - 1; i >= 0; i--)
    {
        if (vt[1].count(c[0][i].first) == 0 && vt[2].count(c[0][i].first) == 0)
        {
            bd = i;
            break;
        }
    }

    if (bd == -1)
    {
        if (s[1].empty() && s[2].empty())
            res = min(res, 0);

        int u1,u2;
        if (!s[1].empty())
            u1 = *(s[1].begin());
        else
            res = min(res, c[2][*(s[2].begin())].second);
        if (!s[2].empty())
            u2 = *(s[2].begin());
        else
            res = min(res, c[1][*(s[1].begin())].second);
        if (c[1][u1].first!=c[2][u2].first)
            res = min(res, c[1][u1].second + c[2][u2].second);
        else
        {
            cout<<"BANG "<<c[1][u1].second<<' '<<c[2][u2].second<<endl;
            if (s[1].size() > 1)
                {
                    set<int,greater<int> >::iterator it = s[1].begin();
                    it++;
                    res = min(res, c[1][*it].second + c[2][u2].second);
                }
                else
                    res = min(res, c[2][u2].second);
            if (s[2].size() > 1)
                {
                    set<int,greater<int> >::iterator it = s[2].begin();
                    it++;
                    res = min(res, c[1][u1].second + c[2][*it].second);
                }
                else
                    res = min(res, c[1][u1].second);
        }
    }
    for (int i = 0; i < c[0].size(); i++)
    {
        int v = c[0][i].first;
        for (int k = 1; k <= 2; k++)
            if (vt[k].count(v) > 0)
                s[k].erase(vt[k][v]);
        if (i < bd) continue;
        if (s[1].empty() && s[2].empty())
        {
            res = min(res, c[0][i].second);
            continue;
        }
        int u1,u2;
        if (!s[1].empty())
            u1 = *(s[1].begin());
        else
        {
            res = min(res, c[0][i].second + c[2][*(s[2].begin())].second);
            continue;
        }
        if (!s[2].empty())
            u2 = *(s[2].begin());
        else
        {
            res = min(res, c[0][i].second + c[1][*(s[1].begin())].second);
            continue;
        }
        if (c[1][u1].first!=c[2][u2].first)
        {
            res = min(res, c[0][i].second + c[1][u1].second + c[2][u2].second);
        }
        else
        {
            //cout<<"BANG "<<c[0][i].second<<' '<<c[1][u1].second<<' '<<c[2][u2].second<<endl;
            if (s[1].size() > 1)
                {
                    set<int,greater<int> >::iterator it = s[1].begin();
                    it++;
                    res = min(res, c[0][i].second + c[1][*it].second + c[2][u2].second);
                }
                else
                    res = min(res, c[0][i].second + c[2][u2].second);
            if (s[2].size() > 1)
                {
                    set<int,greater<int> >::iterator it = s[2].begin();
                    it++;
                    res = min(res, c[0][i].second + c[1][u1].second + c[2][*it].second);
                }
                else
                    res = min(res, c[0][i].second + c[1][u1].second);
        }
    }
}

int main()
{
    freopen("D392.inp","r",stdin);
    //freopen("D392.out","w",stdout);
    scanf("%d",&n);
    for (int i = 0; i <= 2; i++)
    for (int j = 1; j <= n; j++)
        scanf("%d",&a[i][j]);
    preprocessing();
    res = oo;
    process();
    cout<<res<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

