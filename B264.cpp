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
const int maxn = 100000+10;
int a[maxn];
int b[maxn][10];
int maxnt[maxn];
int F[maxn],n,res;

void factorize(int x)
{
    int so=a[x];
    int i=2;
    while (i<=trunc(sqrt(so)))
    {
        if (so%i==0)
        {
            b[x][++b[x][0]]=i;
            while (so%i==0) so/=i;
        }
        i++;
    }
    if (so>1)
    {
        b[x][++b[x][0]]=so;
    }
}

int main()
{
    //freopen("B264.inp","r",stdin);
    //freopen("B264.out","w",stdout);
    cin>>n;
    res=1;
    FOR (i,1,n)
    {
        cin>>a[i];
        factorize(i);
        /*cout<<a[i]<<':';
        FOR(j,1,b[i][0])
            cout<<b[i][j]<<' ';
        cout<<endl;*/
        FOR(j,1,b[i][0])
            F[i]=max(F[i],maxnt[b[i][j]]+1);
        FOR(j,1,b[i][0])
            maxnt[b[i][j]]=max(maxnt[b[i][j]],F[i]);
        res=max(res,F[i]);
    }
    cout<<res;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

