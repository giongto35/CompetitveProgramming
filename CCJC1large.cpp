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
const int maxn = 1000000+10;
int di[maxn],ni[maxn],wi[maxn],ei[maxn],si[maxn],ddi[maxn],dpi[maxn],dsi[maxn];

struct event
{
    int l;
    int r;
    int s;
    int d;
} e[maxn];
struct roirac
{
    int gt;
    int idx;
    int t;
} rr[4*maxn];
int spt,bd,kt;
const int oo = 1000000000;
int res,n,T,sl,srr;
bool duyet;
struct interval
{
    int min;
    int val;
} IT[40000000];

bool mycmp(event a,event b)
{
    return a.d<b.d;
}

bool mycmp2(roirac a,roirac b)
{
    return a.gt<b.gt;
}

void extract(int node)
{
    if (IT[node].val!=0)
    {
        IT[node*2].val=max(IT[node*2].val,IT[node].val);
        IT[node*2].min=max(IT[node*2].min,IT[node].val);
        IT[node*2+1].val=max(IT[node*2+1].val,IT[node].val);
        IT[node*2+1].min=max(IT[node*2+1].min,IT[node].val);
        //IT[node].val=0;
    }
}

int get(int node,int l,int r,int u,int v)
{
    //if (duyet) {
            //cout<<IT[2].val<<endl;
            //cout<<"ABC  "<<node<<' '<<l<<' '<<r<<' '<<IT[node].min<<' '<<IT[node].val<<endl;
    //}
    if (r<u||l>v) return oo;
    if (u<=l&&r<=v) return IT[node].min;
    int mid = (l+r)/2;
    extract(node);
    return min(get(node*2,l,mid,u,v),get(node*2+1,mid+1,r,u,v));
}

void update(int node,int l,int r,int u,int v,int gt)
{
    if (r<u||l>v) return;
    if (u<=l&&r<=v)
    {

        IT[node].val=max(IT[node].val,gt);
        IT[node].min=max(IT[node].min,gt);
        //if (duyet) cout<<"ABC  "<<node<<' '<<l<<' '<<r<<' '<<u<<' '<<v<<' '<<IT[node].min<<' '<<IT[node].val<<' '<<gt<<endl;
        return;
    }
    int mid = (l+r)/2;
    extract(node);
    update(node*2,l,mid,u,v,gt);
    update(node*2+1,mid+1,r,u,v,gt);
    //IT[node].min=min(IT[node*2].min,IT[node*2+1].min);
    IT[node].min=oo;
    if (l<=mid) IT[node].min=min(IT[node].min,IT[node*2].min);
    if (mid+1<=r) IT[node].min=min(IT[node].min,IT[node*2+1].min);
}

void roirachoa()
{
    sort(rr+1,rr+1+srr,mycmp2);
    rr[0].gt=-123;
    FOR(i,1,srr)
    {
        if (rr[i].gt!=rr[i-1].gt) sl++;
        if (rr[i].idx==0) continue;
        if (rr[i].t==1) e[rr[i].idx].l=sl;
        else
            e[rr[i].idx].r=sl;
    }

}
int main()
{
    freopen("C-large-practice.in","r",stdin);
    //freopen("CCJC1.inp","r",stdin);
    freopen("CCJC1.out","w",stdout);
    cin>>T;
    FOR(st,1,T)
    {
        cin>>n;
        spt=0;
        srr=0;
        memset(IT,0,sizeof(IT));
        cerr<<st<<endl;
        sl=0;
        FOR(i,1,n)
        {
            cin>>di[i]>>ni[i]>>wi[i]>>ei[i]>>si[i]>>ddi[i]>>dpi[i]>>dsi[i];
            //cout<<n<<' '<<ni[i]
            FOR(j,1,ni[i])
            {
                spt++;
                //cout<<spt<<endl;
                e[spt].l=wi[i]+dpi[i]*(j-1);
                e[spt].l=e[spt].l*2;

                srr++;
                rr[srr].gt=e[spt].l;
                rr[srr].idx=spt;
                rr[srr].t=1;
                srr++;
                rr[srr].gt=e[spt].l-1;
                rr[srr].idx=0;
                rr[srr].t=0;

                e[spt].r=ei[i]+dpi[i]*(j-1);
                e[spt].r=e[spt].r*2-1;

                srr++;
                rr[srr].gt=e[spt].r;
                rr[srr].idx=spt;
                rr[srr].t=2;
                srr++;
                rr[srr].gt=e[spt].r+1;
                rr[srr].idx=0;
                rr[srr].t=0;

                e[spt].s=si[i]+dsi[i]*(j-1);
                e[spt].d=di[i]+ddi[i]*(j-1);
            }
        }

        roirachoa();
        sort(e+1,e+1+spt,mycmp);
        e[spt+1].d=-123124;
        e[0].d=-12321;
        res=0;
        //cout<<endl;
        //cout<<sl<<endl;
        //FOR(i,1,spt) cout<<e[i].l<<' '<<e[i].r<<' '<<e[i].s<<' '<<e[i].d<<endl;
        FOR(i,1,spt)
        {
            if (e[i].d!=e[i-1].d) bd=i;
            if (e[i].d!=e[i+1].d)
            {
                kt=i;
                //cout<<bd<<' '<<kt<<endl;
                FOR(j,bd,kt)
                {
                    bool ok=false;
                    if (get(1,1,sl,e[j].l,e[j].r)<e[j].s) res++;
                }

                FOR(j,bd,kt)
                    update(1,1,sl,e[j].l,e[j].r,e[j].s);
            }
        }
        cout<<"Case #"<<st<<": "<<res<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

