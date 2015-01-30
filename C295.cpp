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
const int oo=1000000000;
const int cmod=1000000007;
const int maxm=50+10;
const int maxn=maxm*maxm;
struct stt
{
    int s1;
    int s2;
    int t;
};
int pos[maxm][maxm][2];
int D[maxm][maxm][2];
long long F[maxm][maxm][2];
int n,m,nheap;
int s1,s2,k;
stt heap[maxn];
int C[maxm][maxm];

stt makestt(int s1,int s2,int t)
{
    stt u;
    u.s1=s1;
    u.s2=s2;
    u.t=t;
    return u;
}
void swap(int u,int v)
{
    stt tg;
    tg=heap[u];heap[u]=heap[v];heap[v]=tg;
    pos[heap[u].s1][heap[u].s2][heap[u].t]=u;pos[heap[v].s1][heap[v].s2][heap[v].t]=v;
}

void update(int s1,int s2,int t)
{
    int c=pos[s1][s2][t];
    if (c==0)
    {
        nheap++;heap[nheap]=makestt(s1,s2,t);pos[s1][s2][t]=nheap;
        c=nheap;
    }
    while (c/2>=1&&D[heap[c/2].s1][heap[c/2].s2][heap[c/2].t]>D[heap[c].s1][heap[c].s2][heap[c].t])
    {
        swap(c,c/2);
        c/=2;
    }
}

stt pop()
{
    int u,r,c;
    stt res=heap[1];
    heap[1]=heap[nheap];
    nheap--;
    r=1;
    while (r*2<=nheap)
    {
        c=r*2;
        if (c+1<=nheap&&D[heap[c+1].s1][heap[c+1].s2][heap[c+1].t]<D[heap[c].s1][heap[c].s2][heap[c].t]) c++;
        if (D[heap[r].s1][heap[r].s2][heap[r].t]<D[heap[c].s1][heap[c].s2][heap[c].t]) break;
        swap(r,c);
        r=c;
    }
    return res;
}

void setup()
{
    C[0][0]=1;
    FOR(i,1,n)
    {
        C[i][0]=1;
        FOR(j,1,n)
        C[i][j]=(C[i-1][j]+C[i-1][j-1])%cmod;
    }
    int i;
    FOR(i,0,s1)
    FOR(j,0,s2)
    FOR(k,0,1)
    {
        D[i][j][k]=oo;
        F[i][j][k]=0;
    }
    D[s1][s2][0]=0;
    F[s1][s2][0]=1;
    update(s1,s2,0);
}

void dijkstra()
{
    setup();
    while(nheap>0)
    {
        stt u=pop();
        //cout<<u.s1<<' '<<u.s2<<' '<<u.t<<endl;
        if (u.s1==0&&u.s2==0&&u.t==1)
        {
            cout<<D[u.s1][u.s2][u.t]<<endl;
            cout<<F[u.s1][u.s2][u.t]<<endl;
            return;
        }
        stt v=makestt(s1-u.s1,s2-u.s2,1-u.t);
        if (u.t==0)//go
        {
            FOR(i,0,u.s1)
            FOR(j,0,u.s2)
            {
                stt g=makestt(u.s1-i,u.s2-j,1-u.t);
                if (i*1+j*2>k) break;
                if (i+j>=1)
                {
                    //cout<<u.s1<<' '<<u.s2<<' '<<u.t<<' '<<g.s1<<' '<<g.s2<<' '<<g.t<<endl;
                    if (D[g.s1][g.s2][g.t]>D[u.s1][u.s2][u.t]+1)
                    {
                        D[g.s1][g.s2][g.t]=D[u.s1][u.s2][u.t]+1;
                        F[g.s1][g.s2][g.t]=(((F[u.s1][u.s2][u.t]*C[u.s1][i])%cmod)*C[u.s2][j])%cmod;
                        update(g.s1,g.s2,g.t);
                    }
                    else
                    if (D[g.s1][g.s2][g.t]==D[u.s1][u.s2][u.t]+1)
                    {
                        F[g.s1][g.s2][g.t]=(F[g.s1][g.s2][g.t]+(((F[u.s1][u.s2][u.t]*C[u.s1][i])%cmod)*C[u.s2][j])%cmod)%cmod;
                    }

                }
            }
        }
        else
        {
            FOR(i,0,v.s1)
            FOR(j,0,v.s2)
            {
                stt g=makestt(u.s1+i,u.s2+j,1-u.t);
                    //cout<<u.s1<<' '<<u.s2<<' '<<u.t<<' '<<g.s1<<' '<<g.s2<<' '<<g.t<<endl;
                if (i*1+j*2>k) break;
                if (i+j>=1)
                {
                    if (D[g.s1][g.s2][g.t]>D[u.s1][u.s2][u.t]+1)
                    {
                        D[g.s1][g.s2][g.t]=D[u.s1][u.s2][u.t]+1;
                        F[g.s1][g.s2][g.t]=(((F[u.s1][u.s2][u.t]*C[v.s1][i])%cmod)*C[v.s2][j])%cmod;
                        update(g.s1,g.s2,g.t);
                    }
                    else
                    if (D[g.s1][g.s2][g.t]==D[u.s1][u.s2][u.t]+1)
                    {
                        F[g.s1][g.s2][g.t]=(F[g.s1][g.s2][g.t]+(((F[u.s1][u.s2][u.t]*C[v.s1][i])%cmod)*C[v.s2][j])%cmod)%cmod;
                    }

                }
            }
        }
    }
    cout<<-1<<endl;
    cout<<0<<endl;
}

int main()
{
    //freopen("C295.in","r",stdin);
    //freopen("C295.out","w",stdout);
    cin>>n>>k;
    s1=0;
    s2=0;
    int s;
    FOR(i,1,n)
    {
        cin>>s;
        if (s==50) s1++;
        else s2++;
    }
    k=k/50;
    dijkstra();
    fclose(stdin);
    fclose(stdout);
    return 0;
}

