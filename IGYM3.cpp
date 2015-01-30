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
int c,n,na;
int a[maxn];
vector<int> v[maxn];
set<pair<int,int> > s;
int b[maxn];
int pos[maxn];
int res;

int next(int u)
{
    int num = a[u];
    while (pos[num] < v[num].size() && v[num][pos[num]] <= u) pos[num] ++;
    if (pos[num] == v[num].size()) return 1000000000;
    return v[num][pos[num]];
}

int main()
{
    //freopen("IGYM3.inp","r",stdin);
    //freopen("IGYM3.out","w",stdout);
    scanf("%d%d%d",&c,&n,&na);
    for(int i = 1; i <= na; i++)
    {
        scanf("%d", &a[i]);
        v[a[i]].push_back(i);
    }
    for (int i = 1; i <= na; i++)
    {
        if (s.find(make_pair(b[a[i]], a[i])) != s.end())
        {
            s.erase(s.find(make_pair(b[a[i]], a[i])));
        }
        else
        if (s.size() < c)
        {
            res++;
            //cout<<"push "<<a[i]<<endl;
        }
        else
        {
            res++;
            pair<int,int> x = *s.begin();
            //cout<<"POP "<<x.first<<' '<<x.second<<endl;
            //cout<<"push "<<a[i]<<endl;
            s.erase(s.begin());
        }
            b[a[i]] = -next(i);
            s.insert(make_pair(-next(i), a[i]));
    }
    cout<<res<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

