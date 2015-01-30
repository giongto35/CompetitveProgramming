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
const int maxn = 100+10;
int n;
string a[maxn];
int r[maxn];
int c[maxn];

int main()
{
    //freopen("A329.inp","r",stdin);
    //freopen("A329.out","w",stdout);
    string temp;
    cin>>n;getline(cin,temp);
    FOR(i,0,n-1) getline(cin,a[i]),r[i]=-1,c[i]=-1;

    FOR(i,0,n-1)
    FOR(j,0,n-1)
    {
        if (a[i][j]=='.') r[i]=j,c[j]=i;
    }
    bool ok = true;
    FOR(i,0,n-1) if (r[i]==-1) ok=false;
    if (ok)
    {
        FOR(i,0,n-1) cout<<i+1<<' '<<r[i]+1<<endl;
        return 0;
    }

    ok = true;
    FOR(i,0,n-1) if (c[i]==-1) ok=false;
    if (ok)
    {
        FOR(i,0,n-1) cout<<c[i]+1<<' '<<i+1<<endl;
        return 0;
    }
    cout<<-1;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
