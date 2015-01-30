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
const int maxn=10000+10;
int a[maxn];
int F[2][maxn];
int gh;
int n;
const int cmod=1000000007;
int ii;
int main()
{
    //freopen("JEDAN.inp","r",stdin);
    //freopen("JEDAN.out","w",stdout);
    cin >>n;
    gh=(n+1)/2;
    FOR(i,1,n)
    {
        ii=i&1;
        memset(F[ii],0,sizeof(F[ii]));
        cin>>a[i];
        if (i==1)
        {
            if (a[i]==-1||a[i]==0) F[ii][0]=1;
            else
            {
                cout<<0;
                return 0;
            }
            continue;
        }
        if (a[i]!=-1)
        {
            if (a[i]>0)
            F[ii][a[i]]=(F[ii][a[i]]+F[ii^1][a[i]-1])%cmod;
            if (a[i]<gh)
            F[ii][a[i]]=(F[ii][a[i]]+F[ii^1][a[i]+1])%cmod;
            F[ii][a[i]]=(F[ii][a[i]]+F[ii^1][a[i]])%cmod;
        }
        else
        FOR(j,0,gh)
        {
            if (j>0)
            F[ii][j]=(F[ii][j]+F[ii^1][j-1])%cmod;
            if (j<gh)
            F[ii][j]=(F[ii][j]+F[ii^1][j+1])%cmod;
            F[ii][j]=(F[ii][j]+F[ii^1][j])%cmod;
        }
    }
    cout<<F[n&1][0]<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

