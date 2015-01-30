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
#include <conio.h>

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

const int maxn = 3000+10;
int a[maxn],n,m;
int b[maxn];
int cnt ;
set<int> same;
set<int> diff;
vector<pair<int,int> > res;
int main()
{
    //freopen("D441.inp","r",stdin);
    //freopen("","w",stdout);
    scanf("%d",&n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d",&a[i]);
        b[a[i]] = i;
    }

    scanf("%d",&m);
    m = n - 1 - m;c
    cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] == i)
        {
            cnt++;
            same.insert(i);
        }
        else
            diff.insert(i);
    }
    if (m == 0) m = 5;
    if (cnt == m);
    else
    if (cnt > m)
    {
        while (cnt > m)
        {
            bool t = false;
            if (cnt - m >= 2)
            {
                if (same.size() >= 2)
                {
                    int u = *same.begin();
                    same.erase(u);
                    int v = *same.begin();
                    same.erase(v);
                    res.push_back(make_pair(u,v));
                    swap(a[u],a[v]);
                    diff.insert(u);
                    diff.insert(v);
                    cnt-=2;
                }
                else t = true;
            } else t = true;
            if (t)
            {
                int u = *same.begin();
                same.erase(u);
                int v = *diff.begin();
                diff.erase(v);
                res.push_back(make_pair(u,v));
                swap(a[u],a[v]);
                diff.insert(u);
                diff.insert(v);
                cnt-=1;
            }
        }
    }
    else
    if (cnt < m)
    {
        while (cnt < m)
        {
            bool found = false;
            for (int i = 1; i <= n; i++)
            {
                int j = b[i];
                if (i == j) continue;
                if (a[i] == j && a[j] == i && m - cnt >= 2)
                {
                    swap(a[i],a[j]);
                    b[a[i]] = i;
                    b[a[j]] = j;
                    res.push_back(make_pair(i,j));
                    found = true;
                    cnt+=2;
                }
            }
            if (found == false)
            {
                for (int i = 1; i <= n; i++)
                {
                    int j = b[i];

                    if (i == j) continue;
                    if (!(a[i] == j && a[j] == i) && m - cnt >= 1)
                    {
                        swap(a[i],a[j]);
                        b[a[i]] = i;
                        b[a[j]] = j;
                        res.push_back(make_pair(i,j));
                        found = true;
                        cnt+=1;
                    }
                }
            }
            /*cout<<res[res.size()-1].first<<' '<<res[res.size()-1].second<<' '<<cnt<<' '<<m<<' '<<endl;
            for (int i = 1; i<=n; i++) cout<<a[i]<<' ';cout<<endl;
            for (int i = 1; i<=n; i++) cout<<b[i]<<' ';cout<<endl;
            getch();*/

        }
    }
    cout<<res.size()<<endl;
    for (int i = 0; i < res.size(); i++)
    {
        printf("%d %d ",min(res[i].first,res[i].second),max(res[i].first,res[i].second));
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

