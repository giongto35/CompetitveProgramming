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
const int maxc = 100;
const int oo =100000000;
int F[maxc*2+10][maxc+10];
int main()
{
    //freopen("BCJB1.inp","r",stdin);
    freopen("BCJB1.out","w",stdout);
    //cin>>n;
    FOR(i,0,maxc*2) FOR(j,0,maxc) F[i][j]=oo;
    F[maxc][0]=0;
    FOR(j,1,maxc)
    FOR(i,0,maxc*2)
    {
        if (i>=j)
        F[i][j]=min(F[i][j],F[i-j][j-1]+1);
        if (i+j<=maxc*2)
        F[i][j]=min(F[i][j],F[i+j][j-1]+1);
    }
    FOR(i,maxc,maxc*2)
    {
        int smin=oo;
        FOR(j,0,maxc) smin=min(smin,F[i][j]);
        cout<<i-maxc<<' '<<smin<<endl;
    }
    fclose(stdin);

    fclose(stdout);
    return 0;
}
