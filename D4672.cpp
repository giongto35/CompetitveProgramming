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
char* ch;
string a[maxn],x,y;
int m,n;
map<string, pair<int,string> > ma;
int resR;
int resL;

int countR(const string &s)
{
    int res = 0;
    for (int i = 0; i < s.length(); i++)
        res += (s[i] == 'r');
    return res;
}

bool cmp(const pair<int,string> &a,const string &b)
{
    int v = countR(b);
    if (a.first > v) return true;
    if (a.first < v) return false;
    return (a.second.length() >= b.length());
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    freopen("D467.inp","r",stdin);
    //freopen("D467.out","w",stdout);
    cin>>m;
    for (int i = 1; i <= m; i++)
    {
        cin>>a[i];
        std::transform(a[i].begin(), a[i].end(), a[i].begin(), ::tolower);
    }
    cin>>n;
    for (int i = 1; i <= n; i++)
    {
        cin>>x>>y;
        std::transform(x.begin(), x.end(), x.begin(), ::tolower);
        std::transform(y.begin(), y.end(), y.begin(), ::tolower);
        if (cmp(make_pair(countR(x),x), y))
        {
            //cout<<x<<' '<<y<<endl;
            if (ma.count(x) == 0) ma[x] = make_pair(countR(y), y);
            else
            {
                if (cmp(ma[x],y)) ma[x] = make_pair(countR(y), y);
            }
        }
    }
    for (int i = 1; i <= m; i++)
    {
        if (ma.count(a[i]) > 0)
        {
            resR += ma[a[i]].first;
            resL += ma[a[i]].second.length();
        }
        else
        {
            resR += countR(a[i]);
            resL += a[i].length();
        }
    }
    cout<<resR<<' '<<resL<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

