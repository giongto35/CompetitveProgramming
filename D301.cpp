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
const int maxn=2*100000+10;
vector<pair<int,int> > q[maxn],q2[maxn];
int vt[maxn];
int l,r,n,m;
int BIT[maxn];
int a[maxn];
long long res[maxn];

void add(int i)
{
    while (i<=n)
    {
        BIT[i]+=1;
        i=i+(i & (-i));
    }
}

long long get(int i)
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
    //freopen("D301.inp","r",stdin);
    //freopen("D301.out","w",stdout);
    cin>>n>>m;
    FOR(i,1,n)
    {
        scanf("%d",&a[i]);
        vt[a[i]]=i;
    }
    FOR(i,1,m)
    {
        scanf("%d%d",&l,&r);
        q[r].push_back(make_pair(i,l));
        q2[l].push_back(make_pair(i,r));
    }
    FOR(i,1,n)
    {
        FOR(j,1,sqrt(a[i]))
        {
            if (a[i]%j==0)
            {
                if (vt[j]!=0&&vt[j]<=i)
                    add(vt[j]);
                if (j!=a[i]/j&&vt[a[i]/j]<=i)
                    add(vt[a[i]/j]);
            }
        }
        FOR(j,0,q[i].size()-1)
            res[q[i][j].first]=get(i)-get(q[i][j].second-1);
    }
    memset(BIT,0,sizeof(BIT));
    DOW(i,n,1)
    {
        FOR(j,1,sqrt(a[i]))
        {
            if (a[i]%j==0)
            {
                if (vt[j]!=0&&vt[j]>i) add(vt[j]);
                if (j!=a[i]/j&&vt[a[i]/j]>i) add(vt[a[i]/j]);
            }
        }
        FOR(j,0,q2[i].size()-1)
            res[q2[i][j].first]+=get(q2[i][j].second)-get(i-1);
    }
    FOR(i,1,m)
    cout<<res[i]<<endl;

    fclose(stdin);
    fclose(stdout);
    return 0;
}

