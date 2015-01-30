#include <vector>
#include <list>
#include <bitset>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
#define FOR(i,a,b) for( int i=(a),_b=(b);i<=_b;i++)
//#define DOW(i,a,b) for( int i=(b),_a=(a);i>=_a;i--)
const int maxn = 30000+3;
int a[maxn];
int F[maxn][3],n,res,m;
int main()
{

    //freopen("NDCCARD.inp","r",stdin);
    //freopen("NDCCARD.out","w",stdout);
    cin>>n>>m;
    FOR(i,1,n)
    {
        cin>>a[i];
        for(int j=min(10000,m);j>=a[i];j--)
        {
            FOR(k,1,2)
            {
                F[j][k]=max(F[j][k],F[j-a[i]][k-1]+a[i]);
                //cout<<i<<' '<<j<<' '<<k<<' '<<F[j][k]<<endl;
                //F[j][k]=max(F[j][k],F[j-1][k]);
            }
        }
        F[a[i]][0]=a[i];
    }
    FOR(j,1,min(30000,m)) res=max(res,F[j][2]);
    cout<<res<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
