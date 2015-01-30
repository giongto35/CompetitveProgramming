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
const int maxn = 2000+10;
int n,m;
string s;
int a[maxn][maxn];
long long res;
int y,x;

bool check(int y1,int x1,int y2,int x2)
{
    bool t0=false;
    bool t1=false;
    FOR(i,y1,y2)
    FOR(j,x1,x2)
    {
        if (a[i][j]==0) t0=true;
        if (a[i][j]==1) t1=true;
    }
    return (t1==true&&t0==true);
}

int main()
{
    //freopen("LSEA.inp","r",stdin);
    //freopen("LSEA.out","w",stdout);
    cin>>n>>m;
    getline(cin,s);
    FOR(i,1,n)
    {
        getline(cin,s);
        FOR(j,1,m)
        a[i][j]=(s[j-1]=='1');
    }
    FOR(i,1,n)
    FOR(j,1,m)
    {
        FOR(k,i,n)
        FOR(l,j,m)
        {
            if (check(i,j,k,l))
            {
                //cout<<i<<' '<<j<<' '<<k<<' '<<l<<endl;
                res+=(k-i+1)*(l-j+1);
            }
        }
    }
    cout<<res;

    fclose(stdin);
    fclose(stdout);
    return 0;
}

