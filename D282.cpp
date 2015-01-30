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
const int maxn=300+10;
bool F[maxn][maxn][maxn];
bool oki[maxn][maxn],okj[maxn][maxn],okk[maxn][maxn],okijk[maxn][maxn][maxn];
int a[3];
int n;

int min3(int i,int j,int k)
{
    return min(min(i,j),k);
}
int main()
{
    //freopen("D282.in","r",stdin);
    //freopen("D282.out","w",stdout);
    cin>>n;
    memset(a,0,sizeof(a));
    FOR(i,0,n-1) cin>>a[i];

    F[0][0][0]=false;
        oki[0][0]=oki[0][0]|(F[0][0][0]==false);
        okj[0][0]=okj[0][0]|(F[0][0][0]==false);
        okk[0][0]=okk[0][0]|(F[0][0][0]==false);
        okijk[0][0][0]=true;

    if (a[0]+a[1]+a[2]==0)
    {
        cout<<"BitAryo";
        return 0;
    }
    if (n==1)
    {
        cout<<"BitLGM";
        return 0;
    }
    FOR(i,0,a[0])
    FOR(j,0,a[1])
    FOR(k,0,a[2])
    {
        if (i==0&&j==0&&k==0) continue;
        F[i][j][k]=false;
        if (n==2&&i>0&&j>0)
        {
            if (okijk[i-1][j-1][k])
            F[i][j][k]=true;
        }
        if (n==3&&i>0&&j>0&&k>0)
            if (okijk[i-1][j-1][k-1])
            F[i][j][k]=true;
        if (i>0&&oki[j][k]) F[i][j][k]=true;
        if (j>0&&okj[i][k]) F[i][j][k]=true;
        if (k>0&&okk[i][j]) F[i][j][k]=true;
        oki[j][k]=oki[j][k]|(F[i][j][k]==false);
        okj[i][k]=okj[i][k]|(F[i][j][k]==false);
        okk[i][j]=okk[i][j]|(F[i][j][k]==false);
        if (n==3&&i>0&&j>0&&k>0)
        okijk[i][j][k]=okijk[i-1][j-1][k-1]|(F[i][j][k]==false);
        else
        if (n==2&&i>0&&j>0)
        okijk[i][j][k]=okijk[i-1][j-1][k]|(F[i][j][k]==false);

    }
    if (F[a[0]][a[1]][a[2]]==false) cout<<"BitAryo"<<endl;else cout<<"BitLGM"<<endl;

    fclose(stdin);
    fclose(stdout);
    return 0;
}
