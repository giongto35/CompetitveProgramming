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
double F[100000+10];
double G[100000+10];
double M10[100000+10];
int T,n;
int main()
{
    //freopen("TAAPLUSB.inp","r",stdin);
    //freopen("TAAPLUSB.out","w",stdout);
    cin>>T;
    M10[0]=1.0/200;
    FOR(i,1,100000) M10[i]=M10[i-1]/10;
    FOR(i,1,100000)
    {
        G[i]=1.0/200-M10[i-1];
        F[i]=F[i-1]+55*G[i];
        F[i]=F[i]+45*(1.0/100 - G[i]);
    }
    while (T>0)
    {
        cin>>n;
        printf("%0.6f\n",F[n]);
        T--;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

