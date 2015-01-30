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
const int maxn=60+10;
long long F[maxn][10000+10];
int a[maxn],T,n;

int GCD(int u,int v)
{
    if (v==0) return u;
    return GCD(v,u%v);
}

int main()
{
    //freopen("AMSGAME2.inp","r",stdin);
    //freopen("AMSGAME2.out","w",stdout);
    cin>>T;
    while (T>0)
    {
        memset(F,0,sizeof(F));
        cin>>n;
        FOR(i,1,n) cin>>a[i];
        FOR(i,1,n) F[i][a[i]]=1;
        FOR(i,1,n-1)
        {
            FOR(j,1,10000)
            {
                if (F[i][j]!=0)
                {
                    F[i+1][GCD(a[i+1],j)]+=F[i][j];
                }
                F[i+1][j]+=F[i][j];
            }
        }
        cout<<F[n][1]<<endl;
        T--;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

