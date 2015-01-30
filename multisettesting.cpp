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
using namespace std ;

#define FOREACH(it,c) for( __typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define FOR(i,a,b) for( int i=(a),_b=(b);i<=_b;i++)
#define DOW(i,b,a) for( int i=(b),_a=(a);i>=_a;i--)
#define REP(i,n) FOR(i,0,(n)-1)
#define DEP(i,n) DOW(i,(n)-1,0)
#define all(a) (a).begin() , (a).end()
#define push(a,b) (a).push_back((b))
#define mp make_pair

typedef vector<int> VI ;
typedef vector<string> VS ;
template<class T> inline int size(const T&c) { return c.size(); }

using namespace std;
const int maxn = 100000+10;
int c[maxn];
struct mycmp{
bool operator()(int a,int b)
{
    if (c[a]==c[b]) return a<b;
    else
        return c[a]<c[b];
}
};
multiset<int,mycmp> s;
int n;
multiset<int,mycmp>::iterator it,a[4];

int main()
{
    freopen("settesting.inp","r",stdin);
    //freopen("settesting.out","w",stdout);
    a[0]=s.insert(1);
    a[1]=s.insert(1);
    a[2]=s.insert(2);
    a[3]=s.insert(2);
    s.erase(a[0]);
    s.erase(a[2]);

    FOREACH(it,s)
    {
        cout<<*it<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

