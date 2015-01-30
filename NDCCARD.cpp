#include <vector>
#include <list>
#include <bitset>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
#define FOR(i,a,b) for( int i=(a),_b=(b);i<=_b;i++)
#define DOW(i,a,b) for( int i=(b),_a=(a);i>=_a;i--)
const int maxn = 10000+1;
int a[maxn];
int F[maxn][maxn],n,m,res;
int main()
{
    //freopen("NDCCARD.inp","r",stdin);
    //freopen("NDCCARD.out","w",stdout);
    cin>>n>>m;
    FOR(i,1,n)
    {
        cin>>a[i];
        F[i][a[i]]=a[i];
        F[i][0]=F[i-1][0];
        FOR(j,1,min(10000,m)) F[i][j]=max(F[i][j],max(F[i-1][j],F[i][j-1]));

    }
    FOR(i,1,n)
    FOR(j,i+1,n)
    if (m-a[i]-a[j]>=0&&F[i-1][min(10000,m-a[i]-a[j])]!=0)
        res=max(res,a[i]+a[j]+F[i-1][min(10000,m-a[i]-a[j])]);
    cout<<res<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
