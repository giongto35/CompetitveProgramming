
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
int T[2][100000+10],BIT[2][100000+10];
int a[2][100000+10];
int n,k,c,u,v;
char ch;

void update(int i,int k,int gt)
{
    int temp=gt-a[k][i];
    a[k][i]=gt;
    while (i<=n)
    {
        BIT[k][i]+=temp;
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
    freopen("Chalim3.inp","r",stdin);
   // freopen("Chalim3.out","w",stdout);
    while (scanf("%d%d", &n,&k) ==2)
    {
        memset(BIT,0,sizeof(BIT));
        memset(a,0,sizeof(a));
        //cout<<n<<' '<<k<<endl;
        FOR(i,1,n)
        {
            scanf("%d",&c);
            if (c==0) update(i,0,1);
            else
            if (c>0) update(i,1,0);
            else
            update(i,1,1);
        }
        //cout<<get(n,0)<<' '<<get(n,1)<<endl;
        FOR(i,1,k)
        {
            cin>>ch;
            scanf("%d%d",&u,&v);
//            cout<<ch<<' '<<u<<' '<<v<<endl;
            if (ch=='C')
            {
                if (a[0][i]==1) update(u,0,0);
                if (a[1][i]==1) update(u,1,0);
                if (v==0) update(u,0,1);
                else
                if (v>0) update(u,1,0);
                else update(u,1,1);
            }
            else
            {
                int res=get(v,0)-get(u-1,0);
                //cout<<u<<' '<<v<<' '<<get(v,0)<<' '<<get(u-1,0)<<' '<<res<<endl;

                if (res>0) cout<<0;
                else
                {
                    res=get(v,1)-get(u-1,1);
                    if (res%2==0) cout<<'+';
                    else
                    cout<<'-';
                }
            }
        }
        cout<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
