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

typedef vector<int> VI ;
typedef vector<string> VS ;
template<class T> inline int size(const T&c) { return c.size(); }

using namespace std;
long long x,y,m;
long long res;
int main()
{
    //freopen("A317.inp","r",stdin);
    //freopen("A317.out","w",stdout);
    cin>>x>>y>>m;
    if (x>=m||y>=m)
    {
        cout<<0;
        return 0;
    }
    if (m<0)
    {
        cout<<-1;
        return 0;
    }
    if (x>y) {long long tg=x;x=y;y=tg;}
    if (x<0&&y<0)
    {
        cout<<-1;
        return 0;
    }
    else
    if (x<0&&y>0)
    {
        long long sl=abs(x)/y;
        res=res+sl;
        x=x+sl*y;
    }
    //cout<<x<<' '<<y<<endl;
    int cnt=0;
    while (x<m&&y<m)
    {
        res++;
        cnt++;
        if (cnt>10000000)
        {
            cout<<-1;
            return 0;
        }
        //cout<<x<<' '<<y<<endl;
        if (x<y) x=x+y;else
        y=x+y;
    }
    cout<<res<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

