
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
long long BIT[100000+10];
int a[100000+10];
int temp;
int n,k,c,u,v;
char ch;

inline void update(int i,int gt)
{
    temp=gt-a[i];
    a[i]=gt;
    while (i<=n)
    {
        BIT[i]+=temp;
        i=i+(i & (-i));
    }
}

inline long long get(int i)
{
    long long gt=0;
    while (i>=1)
    {
        gt+=BIT[i];
        i=i-(i & (-i));
    }
    return gt;
}

int main()
{
   // freopen("Chalim3.inp","r",stdin);
   // freopen("Chalim3.out","w",stdout);
    while (scanf("%d%d\n", &n,&k) ==2)
    {
        memset(BIT,0,sizeof(BIT));
        memset(a,0,sizeof(a));
        //cout<<n<<' '<<k<<endl;
        FOR(i,1,n)
        {
            scanf("%d",&c);
            if (c==0) update(i,n+1);
            else
            if (c>0) update(i,0);
            else
            update(i,1);
        }
        scanf("%\n");
        //cout<<get(n,0)<<' '<<get(n,1)<<endl;
        FOR(i,1,k)
        {
            scanf("%c%d%d\n", &ch, &u, &v);
//            cout<<ch<<' '<<u<<' '<<v<<endl;
            if (ch=='C')
            {
                if (v==0) update(u,n+1);
                else
                if (v>0) update(u,0);
                else update(u,1);
            }
            else
            {
                int res=get(v)-get(u-1);
                if (res>n) cout<<0;
                else
                {
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
