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
#include <iomanip>

using namespace std ;

#define FOREACH(it,c) for( __typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define FOR(i,a,b) for( int i=(a),_b=(b);i<=_b;i++)
#define DOW(i,b,a) for( int i=(b),_a=(a);i>=_a;i--)
#define REP(i,n) FOR(i,0,(n)-1)
#define DEP(i,n) DOW(i,(n)-1,0)
#define all(a) (a).begin() , (a).end()
#define mp(a,b) make_pair((a),(b))
#define fi first
#define se second

typedef vector<int> VI ;
typedef vector<string> VS ;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;

template<class T> inline int size(const T&c) { return c.size(); }

using namespace std;
int fastMax(int x, int y) { return (((y-x)>>(32-1))&(x^y))^y; }
int fastMin(int x, int y) { return (((y-x)>>(32-1))&(x^y))^x; }
const int cmod = 1000000007;
const int maxn = 2000+10;
int a[maxn];
bool b[maxn];
bool c[maxn];
int dau;
int m;
int k;
long long res;
long long TH[maxn][maxn];
long long GT[maxn];
int n;

int main()
{
    //freopen("C341.inp","r",stdin);
    //freopen("C341.out","w",stdout);
    scanf("%d",&n);
    FOR(i,1,n)
    scanf("%d",&a[i]);
    FOR(i,1,n)
    {
            if (a[i]!=-1)
        {
            c[a[i]]=true;
            b[i]=true;
        }
        else m++;
    }
    //FOR(i,1,n) cout<<c[i]<<' '<<b[i]<<endl;
    FOR(i,1,n)
        if (a[i]==-1&&c[i]==false) k++;
    TH[0][0]=1;
    res=0;
    FOR(i,1,n)
    {
        TH[i][0]=1;
        FOR(j,1,n)
        TH[i][j]=(TH[i-1][j]+TH[i-1][j-1])%cmod;
    }
    GT[0]=1;
    FOR(i,1,n)
    GT[i]=(GT[i-1]*i)%cmod;
    FOR(i,0,k)
    {

        if (i%2==0) dau=1;else dau=-1;
        res=(res+(dau*(GT[m-i]*TH[k][i]))%cmod)%cmod;
    }
    cout<<(res%cmod+cmod)%cmod;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

