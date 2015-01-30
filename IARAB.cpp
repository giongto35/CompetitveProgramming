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
const int maxn  =100+10;
int a[maxn][maxn],n,m,res;
bool freex[maxn];
const int dy[4] = {0,-1,-1,-1};
const int dx[4] = {-1,-1,0,1};

int main()
{
    //freopen("IARAB.inp","r",stdin);
    //freopen("IARAB.out","w",stdout);
    cin>>n>>m;
    FOR(i,1,n)
    FOR(j,1,m)
    {
        cin>>a[i][j];
        if (a[i][j]!=-1)
        {
            FOR(k,0,3)
            {
                if (a[i][j]==a[i+dy[k]][j+dx[k]]) freex[a[i][j]]=true;
            }
        }
    }
    res=0;
    FOR(i,1,100) if (freex[i]) res++;
    cout<<res;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

