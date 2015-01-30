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
int BIT[maxn];
int n,m;
bool used1[maxn],used2[maxn];
int a[maxn],b[maxn];
int res;
struct mycmp{
bool operator()(pair<int,int> u,pair<int,int> v)
{
    return ((a[u.first]+b[u.second])% m>=(a[v.first]+b[v.second])%m);
}
};
multiset<pair<int,int> ,mycmp> s;

int get(int i)
{
    int gt=0;
    while (i>=1)
    {
        gt+=BIT[i];
        i=i-(i & (-i));
    }
    return gt;
}

void update(int i,int gt)
{
    while (i<=n)
    {
        BIT[i]=BIT[i]+gt;
        i=i+(i & (-i));
    }
}

int bnrsearch(int c)
{
    int l=0;
    int r=n;
    int res=0;
    while (l<=r)
    {
        int mid = (l+r)/2;
        if (get(mid)>=c)
        {
            res=mid;
            r=mid-1;
        }
        else
            l=mid+1;
    }
    return res;
}

int main()
{
    freopen("E313.inp","r",stdin);
    //freopen("E313.out","w",stdout);
    cin>>n>>m;
    FOR(i,1,n) cin>>a[i];
    FOR(i,1,n) cin>>b[i];
    sort(a+1,a+1+n);
    sort(b+1,b+1+n);
    FOR(i,1,n) update(i,1);
    FOR(i,1,n)
    {
        int l=1;
        int r=n;
        res=n;
        while (l<=r)
        {
            int mid = (l+r)/2;
            if (a[i]+b[mid]<=m-1)
            {
                res=mid;
                l=mid+1;
            }
            else
                r=mid-1;
        }
        s.insert(make_pair(i,res));
        if (res!=n)
        s.insert(make_pair(i,n));
        //cout<<i<<' '<<res<<endl;
    }
    int cnt = n;
    //FOR(i,1,n) cout<<a[i]<<' ';cout<<endl;
    //FOR(i,1,n) cout<<b[i]<<' ';cout<<endl;
    while (cnt>0&&s.size()>0)
    {
        //cout<<s.size()<<endl;
        multiset<pair<int,int> >::iterator v=s.begin();
        s.erase(v);
        pair<int,int> u=*v;
        //cout<<s.size()<<' '<<u.first<<' '<<u.second<<endl;
        if (used1[u.first]==true);
        else
        if (used2[u.second]==true)
        {
            int x = get(u.second);
            x = bnrsearch(x);
            //cout<<"APR : "<<u.first<<' '<<u.second<<' '<<x<<' '<<s.size()<<' '<<u.first<<' '<<x<<endl;
            if (x!=0)
            {
                //cout<<"TR TANG "<<s.size()<<' '<<endl;
                //s.insert(make_pair(u.first,x));
                s.insert( make_pair (u.first,x) );
                //cout<<"CO TANG "<<s.size()<<' '<<endl;
            }
        }
        else
        {
            used1[u.first]=true;
            used2[u.second]=true;
            update(u.second,-1);
            cout<<(a[u.first]+b[u.second])%m<<' ';
            cnt--;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

