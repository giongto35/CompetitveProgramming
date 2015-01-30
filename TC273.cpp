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
int u,v,n,m;
int cnt[300000+10];

int random(int x)
{
    return ((long long)rand()*rand())%x+1;
}
int main()
{
    freopen("c273.inp","w",stdout);
    cin>>n>>m;
    cout<<n<<' '<<m<<endl;
    FOR(i,1,m)
    {
        do
        {
            u=random(n);
            v=random(n);
        } while(cnt[v]==3||cnt[u]==3);
        cnt[v]++;
        cnt[u]++;
        cout<<u<<' '<<v<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

