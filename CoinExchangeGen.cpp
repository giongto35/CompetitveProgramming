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
int st,N,GH,n;

int random(int n)
{
    return ((long long)rand()*rand())%n;
}

int main()
{
    freopen("CoinExchange.inp","w",stdout);
    scanf("%d%d%d",&st,&N,&GH);
    FOR(ct,1,st)
    {
        n=random(N);
        cout<<n<<endl;
        FOR(i,1,N) cout<<random(GH)<<' ';
        cout<<endl;
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}

