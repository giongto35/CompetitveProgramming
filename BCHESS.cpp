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
const int maxn = 2000+10;
int a[maxn][maxn];
int mh[maxn][maxn],mc[maxn][maxn],sq[maxn][maxn];
int smax[maxn];
int cmax[maxn];
int n;
string s;
int main()
{
    //freopen("BCHESS.inp","r",stdin);
    //freopen("BCHESS.out","w",stdout);
    cin>>n;
    getline(cin,s);
    FOR(i,1,n)
    {
        getline(cin,s);
        FOR(j,0,n-1)
        a[i][j+1]=(s[j]=='1');
    }
    FOR(i,1,n) mc[1][i]=1,mh[i][1]=1,sq[1][i]=1,sq[i][1]=1;
    FOR(i,1,n)
    FOR(j,1,n)
    {
        if (i>1&&j>1){
            if (a[i-1][j]!=a[i][j]) mc[i][j]=mc[i-1][j]+1;else mc[i][j]=1;
            if (a[i][j-1]!=a[i][j]) mh[i][j]=mh[i][j-1]+1;else mh[i][j]=1;
            //cout<<i<<' '<<j<<' '<<mh[i][j]<<' '<<mc[i][j]<<' '<<a[i-1][j]<<' '<<a[i][j]<<endl;
            if (a[i-1][j-1]==a[i][j]) sq[i][j]=min(sq[i-1][j-1]+1,min(mh[i][j],mc[i][j])); else sq[i][j]=1;
            //cout<<sq[i][j]<<endl;
        }
        if (sq[i][j] % 2 ==0)
        {
            if (smax[1]<sq[i][j]) smax[1]=sq[i][j],cmax[1]=1;
            else
            if (smax[1]==sq[i][j]) cmax[1]++;

            if (a[i][j]==1)
            {
                if (smax[2]<sq[i][j]-1) smax[2]=sq[i][j]-1,cmax[2]=1;
                else
                if (smax[2]==sq[i][j]-1) cmax[2]++;
            }
            else
            {
                if (smax[3]<sq[i][j]-1) smax[3]=sq[i][j]-1,cmax[3]=1;
                else
                if (smax[3]==sq[i][j]-1) cmax[3]++;
            }

        }
        else
        {
            if (smax[1]<sq[i][j]-1) smax[1]=sq[i][j]-1,cmax[1]=1;
            else
            if (smax[1]==sq[i][j]-1) cmax[1]++;

            if (a[i][j]==1)
            {
                if (smax[2]<sq[i][j]) smax[2]=sq[i][j],cmax[2]=1;
                else
                if (smax[2]==sq[i][j]) cmax[2]++;
            }
            else
            {
                if (smax[3]<sq[i][j]) smax[3]=sq[i][j],cmax[3]=1;
                else
                if (smax[3]==sq[i][j]) cmax[3]++;
            }
        }
    }
    FOR (i,1,3)
    if (smax[i]==0) cout<<0<<' '<<0;else cout<<smax[i]<<' '<<cmax[i]<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

