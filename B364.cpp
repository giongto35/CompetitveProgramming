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

const int maxn  = 100;
int F[maxn];
int G[maxn][maxn];
int a[maxn];
int s[maxn],n,d;

int rec(int j,int k)
{
    if (s[k]-s[j-1]<=d) {G[j][k]=1;return 1;}
    if (G[j][k]<oo)return G[j][k];
    G[j][k]=oo-1;
    //cout<<j<<' '<<k<<' '<<s[k]-s[j-1]<<endl;
    FOR(x,j,k)
    {
        if (s[x]-s[j-1]<=d) G[j][k]=min(G[j][k],rec(x+1,k)+1);
        if (s[k]-s[x]<=d)   G[j][k]=min(G[j][k],rec(j,x)+1);
    }


    FOR(x,1,j-1)
    FOR(y,x,j-1)
        if (s[y]-s[x-1]+d>=s[k]-s[j-1])
            {
                //cout<<x<<' '<<y<<endl;
                G[j][k]=min(G[j][k],1+rec(x,y));
            }
    return G[j][k];
}

int main()
{
    //freopen("B364.inp","r",stdin);
    //freopen("B364.out","w",stdout);
    cin>>n>>d;

    FOR(i,1,n) cin>>a[i];
    sort(a+1,a+1+n);
    FOR(i,1,n) F[i]=oo,s[i]=s[i-1]+a[i];
    FOR(i,0,n) FOR(j,0,n) G[i][j]=oo;
    F[0]=0;
    FOR(i,1,n)
    {
        FOR(j,0,i-1)
        {
            if (F[j]<oo-1)
            {
                if (s[i]-s[j]<=d)
                    F[i]=min(F[i],F[j]+1);
                /*if (s[j]+d>=s[i]-s[j])
                    F[i]=min(F[i],2*F[j]+1);*/
                FOR(l,1,j)
                {
                    FOR(k,l,j)
                    {
                        int sum=s[k]-s[l-1];
                        if (sum+d>=s[i]-s[j])
                        {
                            F[i]=min(F[i],F[j]+rec(l,k)+1);
                        }
                    }
                }

            }

            /*
            if (F[j]<oo&& (s[j] + d >= s[i]-s[j]))
            {
                F[i]=min(F[i],F[j]+2);
            }*/
        }
    }
    DOW(i,n,0)
    {
        if (F[i]<oo-1) {cout<<s[i]<<' '<<F[i]; break;}
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

