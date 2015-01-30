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
const int maxn = 50+10;
int n,k,t;
int sl;
bool used[maxn];
int F[maxn][maxn];
pair<int,pair<int,int> > E[maxn*maxn];
int res;
int cnt;
int lab[maxn];
int u,v;

int getroot(int u)
{
    if (lab[u] == -1) return u;
    lab[u] = getroot(lab[u]);
    return lab[u];
}

int calc()
{
    FOR(i,0,n-1) lab[i] = -1;

    int sum = 0;
    int dem = 0;
    FOR (i,1,t)
    {
        //if (sum + E[i].first > res) return sum + E[i].first;
        if (used[E[i].second.first] && used[E[i].second.second])
        {
            int u = getroot(E[i].second.first);
            int v = getroot(E[i].second.second);
            if ( u != v)
            {
                lab[u] = v;
                sum += E[i].first;
                dem++;
//                if (dem == (sl + k) - 1) break;
            }
        }
    }
    return sum;
}
void rec(int u)
{
    if (u == n)
    {
        res = min(res,calc());
        return;
    }

    rec(u+1);
    used[u] = true;
    rec(u+1);
    used[u] = false;/*
    FOR(i,u,n - 1)// - (sl - (cnt + 1) ))
    {
        if (used[i] == false && cnt < sl)
        {
            cnt++;
            used[i] = true;
            rec(i+1);
            used[i] = false;
            cnt--;
        }
    }*/
}

int main()
{
    freopen("C4.inp","r",stdin);
    //freopen("C4.out","w",stdout);
    while(scanf("%d%d%d",&n,&k,&t) == 3){
    FOR(i,0,n-1) { FOR(j,0,n-1) F[i][j] = oo; F[i][i] = 0;}
    FOR(i,1,t)
    {
        scanf("%d%d",&u,&v);
        scanf("%d",&F[u][v]);
        F[v][u] = F[u][v];
        E[i].second.first = u;
        E[i].second.second = v;
    }
    FOR(i,0,n-1) used[i] = false;
    FOR(i,0,k-1) used[i] = true;
    FOR(x,0,n-1)
    FOR(i,0,n-1)
    FOR(j,0,n-1)
    F[i][j] = min (F[i][j], F[i][x] + F[x][j]);
    t = 0;
    FOR(i,0,n-1)
    FOR(j,i+1,n-1)
    {
        t++;
        E[t].first =  F[i][j];
        E[t].second.first = i;
        E[t].second.second = j;
    }
    sort(E+1,E+1+t);

        res = oo;
        rec(k);
        if (res == oo) cout<<0<<endl;else
        cout<<res<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

