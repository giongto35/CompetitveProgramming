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

int k,n1,n2,n3,t1,t2,t3;
multiset<int> wash;
multiset<int> dry;
multiset<int> fold;
int main()
{
    //freopen("D452.inp","r",stdin);
    //freopen("D452.out","w",stdout);
    scanf("%d%d%d%d%d%d%d",&k,&n1,&n2,&n3,&t1,&t2,&t3);
    int cur = 0;
    for (int i = 1; i <= k; i++)
    {
        if (wash.size() < n1 && dry.size() < n2 && fold.size() < n3)
        {

        }
        else
        {
            if (wash.size() == n1)
            cur = max(cur, *wash.begin());
            if (dry.size() == n2)
            cur = max(cur, *dry.begin() - t1);
            if (fold.size() == n3)
            cur = max(cur, *fold.begin() - t1 - t2);
            while (wash.size() > 0 && *wash.begin() <= cur)
            {
                wash.erase(wash.begin());
            }
            while (dry.size() > 0 && *dry.begin() - t1 <= cur)
            {
                dry.erase(dry.begin());
            }
            while (fold.size() > 0 && *fold.begin() - t1 - t2 <= cur)
            {
                fold.erase(fold.begin());
            }
        }
        wash.insert(cur + t1);
        dry.insert(cur + t1 + t2);
        fold.insert(cur + t1 + t2 + t3);
    }
    cout<<cur+t1 + t2 + t3<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

