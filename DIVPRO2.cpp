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
const int hs = 18;
map<int,int,long long> F;

long long rec(int i,int j)
{
    if (F[i][j]!=0) return F[i][j];
    if (i==0)
    {
        if (j==1) return 1;
        if (j!=1) return 0;
    }
    FOR(k,i!=1,9)
    {
        if (j==0) F[i][0]+=rec(i-1,0);
        else
        if (k!=0&&j%k==0) F[i][j]+=rec(i-1,j/k);

    }
    return F[i][j];
}

int main()
{
//    freopen("DIVPRO.inp","r",stdin);
//    freopen("DIVPRO.out","w",stdout);
    fclose(stdin);
    fclose(stdout);
    return 0;
}

