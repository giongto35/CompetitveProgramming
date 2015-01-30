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
const int maxso=210;
const int hs=102;
int a[maxn];
int F[maxn];
int BIT[2][300];
int len,n,x,y,nx,ny;
void update(int i,int k,int gt)
{
    while (i<=maxso)
    {
        BIT[k][i]=max(BIT[k][i],gt);
        i=i+(i & (-i));
    }
}


int get(int i,int k)
{
    int gt=0;
    while (i>=1)
    {
        gt=max(BIT[k][i],gt);
        i=i-(i & (-i));
    }
    return gt;
}

int main()
{
    //freopen("Bhalim5.inp","r",stdin);
    //freopen("Bhalim5.out","w",stdout);

    while(true)
    {
        scanf("%d%d%d",&n,&x,&y);
        if (n==0) return 0;
        FOR(i,1,n)
        {
            scanf("%d",&a[i]);
            a[i]+=hs;
        }
        memset(BIT,0,sizeof(BIT));
        int res=0;
        FOR(i,1,n)
        {
            F[i]=get(a[i]-1,1-(a[i]%2))+1;
            update(a[i],a[i]%2,F[i]);
            if (a[i]%2==1)
            {
                nx=(F[i]+1)/2;
                ny=F[i]/2;
            }
            else
            {
                nx=F[i]/2;
                ny=(F[i]+1)/2;
            }
            /*if (nx>=x&&ny>=y) res=max(res,nx);
            if (a[i]%2==1)
            {
                if (F[i]%2==1) nx--; else ny--;
            }
            else
            {
                if (F[i]%2==1) ny--; else nx--;

            }
            if (nx>=x&&ny>=y) res=max(res,nx+ny);
            */
            if (a[i]%2==1)
            {
                nx=min(x,y+1);
                ny=min(y,x);
                res=max(res,min(F[i],nx+ny));
            }
            else
            {
                nx=min(x,y);
                ny=min(y,x+1);
                res=max(res,min(F[i],nx+ny));
            }
        }
        cout<<res<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}



