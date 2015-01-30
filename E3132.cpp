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
int res,t;
struct kdl
{
    int first;
    int second;
    int t;
};
struct mycmp{
bool operator()(kdl u,kdl v)
{
    if ((a[u.first]+b[u.second])% m == (a[v.first]+b[v.second])%m)
    {
        return u.t>v.t;
    }
    return ((a[u.first]+b[u.second])% m>(a[v.first]+b[v.second])%m);
}
};
multiset<kdl ,mycmp> s;

int get(int i)
{
    if (i==0) return 0;
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

kdl make_kdl(int first,int second,int time)
{
    kdl u;
    u.first=first;
    u.second=second;
    u.t=time;
    return u;
}
int main()
{
    //freopen("B313.inp","r",stdin);
    //freopen("E313.out","w",stdout);
    s.clear();
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
        s.insert(make_kdl(i,res,0));
        if (res!=n)
        s.insert(make_kdl(i,n,0));
        //cout<<i<<' '<<res<<endl;
    }
    int cnt = n;
    //FOR(i,1,n) cout<<a[i]<<' ';cout<<endl;
    //FOR(i,1,n) cout<<b[i]<<' ';cout<<endl;
    while (cnt>0&&s.size()>0)
    {
        t++;
        //cerr<<s.size()<<endl;
        multiset<kdl >::iterator v=s.begin();
        //cerr<<(*v).first<<' '<<(*v).second<<' '<<(*v).t<<endl;
        kdl u=*v;
        s.erase(v);
        //cerr<<s.size()<<' '<<u.first<<' '<<u.second<<endl;
        //if (s.size()==166&&u.first==219&&u.second==1000) return 0;
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
                s.insert( make_kdl (u.first,x,t) );
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
        //if (s.size()==62&&u.first==752&&u.second==288) return 0;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

