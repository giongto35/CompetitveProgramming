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

int random(int gt)
{
    return (rand()*rand())%gt;
}
int main()
{
    freopen("BALL.in","w",stdout);
    int n=100000;
    int x1,x2;
    cout<<n<<endl;
    FOR(i,1,n)
    {
        x1=random(1000000000)+1;
        x2=random(1000000000)+1;
        if (x1>x2) int tg=x1,x1=x2,x2=tg;
        cout<<x1<<' '<<x2<<' '<<random(1000000000)<<endl;
    }
    cout<<n<<endl;
    FOR(i,1,n)
    cout<<random(1000000000)+1<<' '<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

