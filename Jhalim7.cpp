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
int R1,C1,R2,C2,R,C,K;
int BIT[3][4*100000+10];
long long res;
int n,m,T;
void update(int i,int k,int gt)
{
    while (i<=max(n,m))
    {
        BIT[k][i]+=gt;
        i=i+(i & (-i));
    }
}


int get(int i,int k)
{
    int gt=0;
    while (i>=1)
    {
        gt+=BIT[k][i];
        i=i-(i & (-i));
    }
    return gt;
}

int main()
{
    //freopen("jhalim7.inp","r",stdin);
    //freopen("jhalim7.out","w",stdout);
    cin>>T;
    FOR(ct,1,T)
    {
        scanf("%d%d",&n,&m);
        memset(BIT,0,sizeof(BIT));
        while(true)
        {
            scanf("%d",&R1);
            if (R1==0) break;
            else
            if (R1==-1)
            {
                scanf("%d%d",&R,&K);
                update(R,1,K);
            }
            else
            if (R1==-2)
            {
                scanf("%d%d",&C,&K);
                update(C,2,K);
            }
            else
            {
                scanf("%d%d%d",&C1,&R2,&C2);
                if (R1<=R2&&C1<=C2&&R1>=1&&R1<=n&&R2>=1&&R2<=n&&C1>=1&&C1<=m&&C2>=1&&C2<=m)
                {
                    res =(long long)(get(R2,1)-get(R1-1,1))*(long long)(C2-C1+1);
                    res+=(long long)(get(C2,2)-get(C1-1,2))*(long long)(R2-R1+1);
                    printf("%lld\n",res);
                }
                else
                    printf("Wrong Query.\n");
            }
        }
        printf("\n");
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

