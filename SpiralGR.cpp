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
#include <cmath>
#include <cstdio>
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
const int maxn=100;
const int maxn30=100+100;
const int dy[4]={-1,0,1,0};
const int dx[4]={0,-1,0,1};
int y,x;
int c[maxn30+10][maxn30+10];
int mark[maxn30*maxn30+10];
int a[maxn30*maxn30+10][5];
int d[maxn30*maxn30+10];
bool prime[maxn30*maxn30+10];
int q[maxn30*maxn30+10];
int st;
pair<int,int> VT[maxn30*maxn30];

void sieve()
{
        memset(prime,true,sizeof(prime));
        prime[0]=false;prime[1]=false;
        int i=2;
        while (i*i<=maxn30*maxn30)
        {
            if (prime[i])
            {
                int j=i*i;
                while (j<=maxn30*maxn30)
                {
                    prime[j]=false;
                    j+=i;
                }
            }
            i++;
        }
}
void gentable()
{
    int step=0;
    y=(maxn30)/2;
    x=(maxn30)/2;
    int cs=0;
    c[y][x]=++cs;
    VT[cs]=make_pair(y,x);
    while(true)
    {
        step+=2;
        x++;
        y++;
        FOR(i,0,3)
        {
            FOR(j,1,step)
            {
                y+=dy[i];
                x+=dx[i];
                c[y][x]=++cs;
                VT[cs]=make_pair(y,x);
                if (cs==maxn30*maxn30) return;
            }
        }
    }
}

void buildgraph()
{
    sieve();
    FOR(i,1,maxn30*maxn30)
    {
        y=VT[i].first;
        x=VT[i].second;
        FOR(j,0,3)
        {
            int u=y+dy[j];
            int v=x+dx[j];
            if (u>=1&&u<maxn30&&v>=1&&v<maxn30&&c[u][v]!=0)
            if (!prime[c[u][v]])
            a[i][++a[i][0]]=c[u][v];
        }
    }

}

void BFS(int bd,int kt)
{
    int fr=0;
    int re=1;
    //memset(mark,0,sizeof(mark));
    //memset(d,0,sizeof(d));
    //memset(q,0,sizeof(q));
    q[re]=bd;
    d[bd]=0;
    cout<<"Case "<<st<<": ";
    while (fr<re)
    {
        int u=q[++fr];
        if (u==kt)
        {
            cout<<d[u];
            return;
        }
        FOR(i,1,a[u][0])
        {
            int v=a[u][i];
            //return ;
            if (mark[v]!=st)
            {
                d[v]=d[u]+1;
                mark[v]=st;
                q[++re]=v;
            }
        }
    }
    cout<<"impossible";

}

int main()
{
    //freopen("spiral.in","r",stdin);
    //freopen("spiralgr.out","w",stdout);
    gentable();
    buildgraph();
//12 7570
    //cout<<VT[maxn30*maxn30].first<<' '<<VT[maxn30*maxn30].second<<endl;
    while (scanf("%d%d",&x,&y)==2)
    {
        st++;
        BFS(x,y);
        cout<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

