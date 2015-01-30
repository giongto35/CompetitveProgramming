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
const int maxn=5000+10;
int F[maxn];
long long a[maxn];
long long D[maxn][maxn];
int res,n;
int main()
{
    freopen("D283.in","r",stdin);
    //freopen("D283.out","w",stdout);
    cin>>n;
    FOR(i,1,n) cin>>a[i];
    FOR(i,1,n)
    {
        D[i][i]=a[i];
        DOW(j,i-1,1)
        if (D[j+1][i]%2==0)
        D[j][i]=D[j+1][i]/2;
        else
        D[j][i]=D[j+1][i];
    }
    FOR(i,1,n)
    {
        F[i]=1;
        FOR(j,1,i-1)
        {
            if (a[j]%D[j][i]==0)
                F[i]=max(F[i],F[j]+1);
        }
        res=max(res,F[i]);
    }
    cout<<n-res<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

//1 2 1 1 2
