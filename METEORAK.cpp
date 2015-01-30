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

const int maxn = 1000+10;
int a[maxn][maxn];
int x,y;
int lab[maxn];
int F[maxn][maxn];
pair<int,int> h[maxn][maxn];
bool flag[maxn];
int cnt[maxn];
int maxw;
int n,m,Q,k;
int L,H;

int getroot(int u)
{
    if (lab[u] == u) return u;
    lab[u] = getroot(lab[u]);
    return lab[u];
}

void merge(int u,int v)
{
    cnt[v] += cnt[u];
    maxw = max (maxw , cnt[v]);
    lab[u] = v;
}

int main()
{
    //freopen("METEORAK.inp","r",stdin);
    //freopen("METEORAK.out","w",stdout);
    scanf("%d%d%d",&n,&m,&k);
    FOR(i,1,n)
    FOR(j,1,m) a[i][j] = 1;
    FOR(i,1,k)
    {
        scanf("%d%d",&x,&y);
        a[x][y] = 0;
    }
    FOR(i,1,n){
    FOR(j,1,m)
    {
        h[i][j].second = j;
        if (a[i][j] == 0) h[i][j].first = 0; else
        h[i][j].first = h[i-1][j].first + 1;
    }
    h[i][m+1].first = 0;
    h[i][m+1].second = m + 1;
    }
    FOR(i,1,n)
    {
       sort(h[i] + 1, h[i] + m + 2, greater<pair<int,int> >());
       memset(flag,false,sizeof(flag));
       FOR(j,1,m+1) lab[j] = j,cnt[j]=1;
       maxw = 0;
       //FOR(j,1,m) cout<<h[i][j].second<<' ';cout<<endl;
       int ih = 1;
       FOR(j,1,m+1)
       {
            while (ih < i - h[i][j].first+1)
            {
                F[ih][i] = (i - ih + 1) * maxw;
                ih++;
            }
            int u = h[i][j].second;
            //cout<<h[i][j].first;
            flag[u] = true;
            maxw=max(maxw,1);
            if (u + 1 <= m && flag[u+1])
                merge(getroot(u),getroot(u+1));
            if (u - 1 >= 1 && flag[u-1])
                merge(getroot(u),getroot(u-1));
            //FOR(k,1,m) cout<<cnt[k]<<' ';cout<<endl;
            //FOR(k,1,m) cout<<lab[k]<<' ';cout<<endl;
            F[i-h[i][j].first+1][i] = maxw * h[i][j].first;
       }
       //cout<<endl;
    }
    DOW(i,n,1)
    FOR(j,i,n)
    {
        F[i][j] = max (F[i+1][j], F[i][j]);
        F[i][j] = max (F[i][j-1], F[i][j]);
    }/*
    FOR(i,1,n)
    {
        FOR(j,1,n) cout<<F[i][j]<<' ';cout<<endl;
    }*/
    scanf("%d",&Q);
    FOR(i,1,Q)
    {
        scanf("%d%d",&L,&H);
        printf("%d\n",F[L][H]);
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}

