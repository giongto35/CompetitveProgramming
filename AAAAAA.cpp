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
#define RESET(c,x) memset (c, x, sizeof (c))
#define oo 1000111000
#define PI acos(-1.0)
#define fi first
#define se second
#define SIZE(c) (c).size()

typedef vector<int> VI ;
typedef vector<string> VS ;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;

template<class T> inline int size(const T&c) { return c.size(); }

using namespace std;
int fastMax(int x, int y) { return (((y-x)>>(32-1))&(x^y))^y; }
int fastMin(int x, int y) { return (((y-x)>>(32-1))&(x^y))^x; }

const int maxn = 500+10;
char a[maxn][maxn];
string st;
int F[maxn][maxn][2];
int U[maxn][maxn],L[maxn][maxn];
int G[maxn][maxn];
int res;
int n,m,T;

void DP()
{
    memset(F,0,sizeof(F));
    memset(U,0,sizeof(U));
    memset(L,0,sizeof(L));
    memset(G,0,sizeof(G));
    res = 0;
    if (a[1][1] == '#') return ;
    F[1][1][0] = 1;
    F[1][1][0] = 1;
    FOR(i,1,n)
    FOR(j,1,m)
    FOR(k,0,1)
    {
        if (F[i][j][k]>0 && a[i+1][j]=='.')//down
            F[i+1][j][1] = max(F[i+1][j][1],F[i][j][k]+1);
        if (F[i][j][k]>0 && a[i][j+1]=='.')//right
            F[i][j+1][0] = max(F[i][j+1][0],F[i][j][k]+1);
    }
    FOR(i,1,n) FOR(j,1,m) U[i][j] = F[i][j][0],L[i][j]=F[i][j][1];
    DOW(i,n,1) DOW(j,m,1)
    {
        if (a[i][j]=='.')
        {
            if (U[i+1][j]>0)
            U[i][j] = max(U[i][j],U[i+1][j]+1);
            if (L[i][j+1]>0)
            L[i][j] = max(L[i][j],L[i][j+1]+1);
        }
    }
    FOR(i,1,n)
    FOR(j,1,m)
    FOR(k,0,1)
    {
        if (j>1 && U[i][j-1]>0 && a[i][j]=='.')
        F[i][j][k] = max(F[i][j][k],U[i][j-1]+1);
        if (i>1 && L[i-1][j]>0 && a[i][j]=='.')
        F[i][j][k] = max(F[i][j][k],L[i-1][j]+1);
    }

    FOR(i,1,n)
    FOR(j,1,m)
    FOR(k,0,1)
    {
        if (F[i][j][k]>0 && a[i+1][j]=='.')//down
            F[i+1][j][1] = max(F[i+1][j][1],F[i][j][k]+1);
        if (F[i][j][k]>0 && a[i][j+1]=='.')//right
            F[i][j+1][0] = max(F[i][j+1][0],F[i][j][k]+1);
    }
    res = 0;
    FOR(i,1,n)
    FOR(j,1,m)
    {
        res = max (res , F[i][j][0]);
        res = max (res , F[i][j][1]);
    }/*
    FOR(i,1,n)
    {
        FOR(j,1,m)
        cout<<max(F[i][j][0],F[i][j][1])<<' ';
        cout<<endl;
    }
    FOR(i,1,n)
    {
        FOR(j,1,m)
        cout<<U[i][j]<<' ';
        cout<<endl;
    }
    FOR(i,1,n)
    {
        FOR(j,1,m)
        cout<<L[i][j]<<' ';
        cout<<endl;
    }*/
}

int main()
{
    freopen("aaaaaa.txt","r",stdin);
    freopen("AAAAAA.out","w",stdout);
    scanf("%d",&T);
    FOR(sT,1,T)
    {
        scanf("%d%d",&n,&m);
        getline(cin,st);
        FOR(i,1,n)
        {
            getline(cin,st);
            FOR(j,1,m) a[i][j] = st[j-1];
        }
        DP();
        cout<<"Case #"<<sT<<": "<<res<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
