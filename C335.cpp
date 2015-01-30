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
const int maxn = 100+10;
int n,r,ri,ci;
int a[maxn];
int F[maxn][3][3];
int was[maxn];
int res;

void process()
{
    FOR(i,1,r)
    FOR(j,0,2)
    FOR(k,0,2)
    {

        FOR(x,1,i)
        FOR(t,0,1)
        {
            if (x==1&&t+j==1) continue;
            if (x==i&&t+k==1) continue;
            int g=F[x-1][j][t]^F[i-x][t][k];
            was[g]=i*9+j*3+k;
        }
        F[i][j][k]=0;
        while (was[F[i][j][k]]==i*9+j*3+k) F[i][j][k]++;
    }
}

int main()
{
    //freopen("C335.inp","r",stdin);
    //freopen("C335.out","w",stdout);
    cin>>r>>n;
    FOR(i,1,n)
    {
        cin>>ri>>ci;
        a[ri]=ci;
    }
    process();
    int i=1;
    a[0]=3;a[r+1]=3;
    res=0;
    //FOR(i,1,r) cout<<a[i];cout<<endl;
    while (i<=r)
    {
        int cnt=0;
        if (a[i]==0)
        {
            int l=i-1;
            while (a[i]==0) i++;
            int r=i;
            //cout<<l<<' '<<r<<' '<<r-l-1<<' '<<a[l]-1<<' '<<a[r]-1<<endl;
            res=res^F[r-l-1][a[l]-1][a[r]-1];
        }
        else
        i++;
    }
    if (res==0) cout<<"LOSE"; else cout<<"WIN";
    fclose(stdin);
    fclose(stdout);
    return 0;
}

