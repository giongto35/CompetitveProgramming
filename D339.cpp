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

const int maxn=200000+10;
int a[maxn];
int IT[maxn*4];
int mid,n,m,u,gt;

void build(int node,int l,int r)
{
    if (l==r)
    {
        //cout<<node<<' '<<a[l]<<endl;
        IT[node]=a[l];
        return;
    }
    int mid=(l+r)/2;
    build(node*2,l,mid);
    build(node*2+1,mid+1,r);
    if ((int)log2(r-l+1) %2 == 1)
        IT[node]=IT[node*2] | IT[node*2+1];
    else
        IT[node]=IT[node*2] ^ IT[node*2+1];
}

void update(int node,int l,int r,int u,int gt)
{
    //cout<<u<<' '<<l<<' '<<r<<endl;
    if (u<l||u>r) return;
    if (l==r&&u==l)
    {
        IT[node]=gt;
        return;
    }
    int mid=(l+r)/2;
    update(node*2,l,mid,u,gt);
    update(node*2+1,mid+1,r,u,gt);
    if ((int)log2(r-l+1) %2 == 1)
        IT[node]=IT[node*2] | IT[node*2+1];
    else
        IT[node]=IT[node*2] ^ IT[node*2+1];

}

int main()
{
    //freopen("D339.inp","r",stdin);
    //freopen("D339.out,"w",stdout);
    scanf("%d%d",&n,&m);
    n=(1<<n);
    FOR(i,1,n) scanf("%d",&a[i]);
    build(1,1,n);
    //cout<<IT[1]<<' '<<IT[2]<<' '<<IT[3]<<' '<<IT[4]<<' '<<IT[5]<<' '<<IT[6]<<' '<<IT[7]<<endl;
    FOR(i,1,m)
    {
        scanf("%d%d",&u,&gt);
        update(1,1,n,u,gt);
        cout<<IT[1]<<endl;
        //cout<<IT[1]<<' '<<IT[2]<<' '<<IT[3]<<' '<<IT[4]<<' '<<IT[5]<<' '<<IT[6]<<' '<<IT[7]<<endl;
        //return 0;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

