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
const int maxn = 55;
double F[maxn][maxn][maxn];//den i tong j chon dc k
int a[maxn],b[maxn];
int s,n,p,m;
int cc;
double res;
double ps;

void calc()
{
    FOR(i,0,m)FOR(j,0,p)FOR(k,0,m) F[i][j][k]=0;
    F[0][0][0]=1;
    FOR(i,0,m)
    FOR(j,0,p)
    FOR(k,0,i)
    {
        //chon i+1
        if (j+b[i+1]<=p)
        F[i+1][j+b[i+1]][k+1]+=F[i][j][k]*(k+1);
        F[i+1][j][k]+=F[i][j][k];
    }
    //res=0;
    FOR(j,0,p)
    FOR(k,0,m)
    if (j+cc>p)
    {
        double g = F[m][j][k]*ps*k;
        FOR(l,1,m-k) g*=l;
        res+=g;
        //if (F[m][j][k]>0) cout<<cc<<' '<<j<<' '<<k<<' '<<F[m][j][k]<<endl;
    }
    //printf("%.4f\n",res);
}

void process()
{
    ps=1;
    FOR(i,1,n) ps/=i;
    if (s<=p) cout<<n;
    else
    {
        res=0;
        FOR(i,1,n)
        {
            m=0;
            FOR(j,1,n)
            if (j!=i) b[++m]=a[j];
            cc=a[i];
            calc();
        }
        printf("%.4f",res);
    }
}

int main()
{
    //freopen("B261.inp","r",stdin);
    //freopen("B261.out","w",stdout);
    cin>>n;
    FOR(i,1,n) cin>>a[i],s+=a[i];
    cin>>p;
    process();
    fclose(stdin);
    fclose(stdout);
    return 0;
}

