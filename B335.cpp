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
#define fi first
#define se second

typedef vector<int> VI ;
typedef vector<string> VS ;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;

template<class T> inline int size(const T&c) { return c.size(); }

using namespace std;
int fastMax(int x, int y) { return (((y-x)>>(32-1))&(x^y))^y; }
int fastMin(int x, int y) { return (((y-x)>>(32-1))&(x^y))^x; }
const int maxn = 5*10000+10;
const int oo =1000000000;
const int hs=100;
string st,st2;
int next[maxn][30];
int next2[maxn][30];
int F[maxn][hs+10];//den i do dai j
int tr[maxn][hs+10];
int n,m;
string res;

void trace(int i,int j)
{
    if (i==0) return;
    if (tr[i][j]==1) res=res+st[i];
    trace(i-1,j-tr[i][j]);
}
int main()
{
    freopen("B335.inp","r",stdin);
    //freopen("B335.out","w",stdout);
    getline(cin,st);
    st2=st;
    n=st.length();
    int i=0;
    int j=n-1;
    while (i<=j)
    {
        char tg=st2[i];st2[i]=st2[j];st2[j]=tg;
        i++;
        j--;
    }
    st="@"+st;
    st2="@"+st2;
    n++;
    FOR(j,0,'z'-'a') next[n-1][j]=n;
    DOW(i,n-2,0)
    {
        FOR(j,0,'z'-'a') next[i][j]=next[i+1][j];
        next[i][st[i+1]-'a']=i+1;
    }
    FOR(j,0,'z'-'a') next2[n-1][j]=n;
    DOW(i,n-2,0)
    {
        FOR(j,0,'z'-'a') next2[i][j]=next2[i+1][j];
        next2[i][st2[i+1]-'a']=i+1;
    }
    FOR(i,0,n-1) FOR(j,0,hs+2) F[i][j]=oo;
    F[0][0]=0;
    FOR(i,0,n-2)
    FOR(j,0,hs+2)
    {
        if (F[i][j]==oo) continue;
        if (F[i+1][j]>F[i][j])
        {
            F[i+1][j]=F[i][j];
            tr[i+1][j]=0;
        }
        int v=next2[F[i][j]][st[i+1]-'a'];
        //cout<<i<<' '<<j<<' '<<v;
        if (v<n&&F[i+1][j+1]>v)
        {
            F[i+1][j+1]=v;
            tr[i+1][j+1]=1;
        }
    }
    int vt=0;
    DOW(j,hs+2,0)
    if (F[n-1][j]!=oo)
    {
        trace(n-1,j);
        if (j<=hs) cout<<res;
        else
        {
            //cout<<res<<endl;
            reverse(res.begin(),res.end());
            //cout<<res<<endl;
            FOR(i,0,hs/2-1) cout<<res[i];
            DOW(i,hs/2-1,0) cout<<res[i];
        }
        return 0;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

