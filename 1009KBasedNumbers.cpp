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
const int maxn=100+10;
long long F[maxn][2];
int ni,nj,nl,n,k;
int main()
{
    //kfreopen("kbasednumbers.inp","r",stdin);
    //freopen("kbasednumbers.out","w",stdout);
    cin>>n>>k;
    F[0][0]=1;


    FOR(i,0,n-1)
    FOR(j,0,1)
    {
        if (F[i][j]!=0)
        {
            FOR(d,(i+1==1),k-1)
            {
                if (d>0)
                    F[i+1][0]+=F[i][j];
                if (d==0)
                    if (j==0)
                    F[i+1][1]+=F[i][j];
            }
        }
    }
    int res=0;
    FOR(i,0,1) res=res+F[n][i];
    cout<<res<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

