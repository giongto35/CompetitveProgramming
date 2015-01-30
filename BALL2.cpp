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
const int maxn=100000+10;
struct convey
{
    int x1;
    int x2;
    int y;
} c[maxn];
struct roirac
{
    int idx;
    int t;
    int x;
} rr[maxn*2];

int x;
int res;
int n,spt;
int IT[maxn*8];
int k;
int d[maxn*2];
int next[maxn][3];
int m,F[maxn];
int bd,kt;
int VT[maxn*2];
int temp;

bool mycmp(convey a,convey b)
{
    return (a.y<b.y)||((a.y==b.y)&&(a.x1<b.x1));
}
bool mycmp2(roirac a,roirac b)
{
    return (a.x<b.x);
}
void extract(int &node)
{
    if (IT[node]!=0)
    {
        IT[node*2]=IT[node];
        IT[node*2+1]=IT[node];
        IT[node]=0;
    }
}

void update(int node,int l,int r,int &u,int &v,int &gt)
{
    if (r<u||l>v) return;
    if (u<=l&&r<=v)
    {
        IT[node]=gt;
        return;
    }
    int mid = (l+r)>>1;
    extract(node);
    update(node<<1,l,mid,u,v,gt);
    update((node<<1) +1,mid+1,r,u,v,gt);
}

int get(int x)
{
    int node=VT[x];
    res=0;

    while (node>=1)
    {
        if (IT[node]!=0) res=IT[node];
        node>>=1;
    }
}

void build(int node,int l,int r)
{
    if (l>r) return;
    if (l==r)
    {
        VT[l]=node;
        return;
    }
    int mid =(l+r)>>1;
    extract(node);
    build((node<<1),l,mid);
    build((node<<1)+1,mid+1,r);
}

int found(int x)
{
    int l=1;
    int r=k;
    int res=0;
    while (l<=r)
    {
        int mid=(l+r)/2;
        if (d[mid]<=x)
        {
            res=mid;
            l=mid+1;
        }
        else
            r=mid-1;
    }
    return res;
}
int main()
{
    //freopen("BALL.in","r",stdin);
    //freopen("convey.out","w",stdout);
    scanf("%d",&n);
    spt=0;
    spt++;rr[spt].x=1;
    FOR(i,1,n)
        {
            scanf("%d%d%d",&c[i].x1,&c[i].x2,&c[i].y);
            spt++;
            rr[spt].x=c[i].x1  ;rr[spt].idx=i;rr[spt].t=1;
            spt++;
            rr[spt].x=c[i].x2+1;rr[spt].idx=i;rr[spt].t=2;
        }
    sort(rr+1,rr+1+spt,mycmp2);
    rr[0].x=-123;
    k=0;
    FOR(i,1,spt)
    {
        if (rr[i].x!=rr[i-1].x) d[++k]=rr[i].x;
        if (rr[i].t==1) c[rr[i].idx].x1=k;
        else c[rr[i].idx].x2=k;
    }
    sort(c+1,c+1+n,mycmp);
    build(1,1,k);
    FOR(i,1,n)
    {
        if (c[i].x1>1)
        {
            temp=c[i].x1-1;
            get(temp);
            if (res!=0) next[i][++next[i][0]]=res;
        }
        get(c[i].x2);
        if (res!=0) next[i][++next[i][0]]=res;
        temp=c[i].x2-1;
        update(1,1,k,c[i].x1,temp,i);
    }
     FOR(i,1,n)
    {

        F[i]=1;
        FOR(j,1,next[i][0])
        F[i]=max(F[i],F[next[i][j]]+1);
    }
    scanf("%d",&m);
    FOR(i,1,m)
    {
        scanf("%d",&x);
        int u=found(x);
        res=0;
        get(u);
        if (res!=0)
        printf("%d\n",F[res]);
        else
        printf("0\n");
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

