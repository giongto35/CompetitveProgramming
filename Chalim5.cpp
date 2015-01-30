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
const int maxn=35;
long long F[maxn*2][maxn][maxn][2];
long long res;
int D,G,ct;
int main()
{
    //freopen("Chalim5.inp","r",stdin);
    //freopen("Chalim5.out","w",stdout);
    while (true)
    {
        ct++;
        cin>>D>>G;
        if (D==-1&&G==-1) return 0;
        D*=2;
        memset(F,0,sizeof(F));
        F[1][1][1][0]=2;
        FOR (i,1,D-1)
        {
            FOR (j,1,G)//min(i,G))
            FOR (k,1,D/2)//min(i,D/2))
            FOR (l,0,1)
            {
                if (F[i][j][k][l]!=0)
                    {
                        //if (j+1<=G&&k+1<=D/2)
                        F[i+1][j+1][k+1][l]+=F[i][j][k][l];
                        //if ((i+1)-k<=D/2)
                        F[i+1][1][(i+1)-k][1-l]+=F[i][j][k][l];
                    }

            }
        }
        res=0;
        FOR(j,1,G)
            res+=F[D][j][D/2][1];
        cout<<"Case "<<ct<<": "<<res<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
/*
GDGD
DGDG
GDDG
DGGD
GGDD
DDGG
*/
/*
GDDD
*/
/*
GDGDGD
GDGDDG
DGDGGD
DGDGDG
GDDGGD
GDDGDG
DGGDGD
DGGDDG
GGDDGD
DDGGDG

*/
