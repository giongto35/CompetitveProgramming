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

int n,v,cmd;
vector<int> a;
map<int,int> idx;
bool firsttime;
int main()
{
    //freopen("3230.inp","r",stdin);
    //freopen("3230.out","w",stdout);
    firsttime = false;
    while (scanf("%d%d",&cmd,&v) == 2)
    {
        if (cmd == 5) break;
        if (cmd == 1) a.push_back(v);else
        if (cmd == 2) a.push_back(v);else
        if (cmd == 3)
        {
            if (firsttime == false)
            {
                firsttime = true;
                sort(a.begin(),a.end(),greater<int>() );
                FOR(i,0,a.size()-1) idx[a[i]] = i+1;
            }
            if (v>a.size()) printf("-1\n"); else
            printf("%d\n",a[v-1]);
        } else
        {
            if (firsttime == false)
            {
                firsttime = true;
                sort(a.begin(),a.end(),greater<int>() );
                FOR(i,0,a.size()-1) idx[a[i]] = i+1;
            }
            if (idx.find(v) == idx.end()) printf("-2\n"); else printf("%d\n",idx[v]);
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

