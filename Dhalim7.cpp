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
const int maxn = 1000+10;
bool F[maxn][maxn];
int a[maxn];
int b[maxn];
int n;
int main()
{
    //freopen("Dhalim7.inp","r",stdin);
    //freopen("Dhalim7.out","w",stdout);
    while (scanf("%d",&n)!=EOF)
    {
        FOR (i,1,n) cin>>a[i];
        FOR (i,1,n) cin>>b[i];
        memset(F,false,sizeof(F));
        FOR (i,1,n) F[i][i-1]=true;
        reverse(b+1,b+1+n);
        DOW (i,n,1)
        FOR (j,i,n)
        {
            if (F[i+1][j]&&a[i]==b[j-i+1]) F[i][j]=true;
            if (F[i][j-1]&&a[j]==b[j-i+1]) F[i][j]=true;
        }
        cout<<F[1][n]<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

