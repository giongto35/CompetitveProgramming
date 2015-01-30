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
struct student
{
    int a;
    int b;
    int cs;
} a[maxn];
int n,p,k,k2;
long long f[maxn];
long long sumgrey,sumplease,resgrey,resplease;
struct cmp
{
    bool operator()( int u, int v)  {/*
        if (a[u].a==a[v].a) return a[u].b<a[v].b;
        else
        return a[u].a<a[v].a;*/
        return make_pair(make_pair(a[u].a, a[u].b), u)<make_pair(make_pair(a[v].a, a[v].b), v);
    }
};

set<int ,cmp > s;
int vt;

bool mycmp1(student a,student b)
{
    if (a.b==b.b)
    {
        return a.a<b.a;
    }
    return a.b<b.b;
}

bool mycmp2(student a,student b)
{
    if (a.b==b.b)
    {
        return a.a>b.a;
    }
    return a.b<b.b;
}

void update(int sep)
{
    if (resgrey<sumgrey||(resgrey==sumgrey&&resplease<sumplease))
    {
        resgrey=sumgrey;
        resplease=sumplease;
        vt=sep;
    }
}

void process()
{
    FOR(i,1,n) f[i]=f[i-1]+a[i].b;
    //FOR(i,1,n) cout<<a[i].a<<' '<<a[i].b<<endl;
    s.clear();
    DOW(i,n,n-k+1)
    {
        s.insert(i);
        sumgrey+=a[i].a;
        sumplease=f[i-1]-f[i-k2-1];
        //cout<<i<<' '<<sumgrey<<' '<<sumplease<<endl;
        //update(i);
    }
    update(n-k+1);
    DOW(i,n-k,k2+1)
    {
        //set<int, cmp>::iterator it=s.begin();
        //FOREACH(it,s) cout<<a[(*it)].a<<' '<<a[(*it)].b<<" / ";cout<<endl;
        int u=*s.begin();//*s.begin();
        sumplease=f[i-1]-f[i-k2-1];
        if (a[i].a>a[u].a||(a[i].a==a[u].a&&a[i].b>a[u].b))
        {
            //cout<<"rep "<<u<<" "<<i<<' '<<a[u].a<<' '<<a[i].a<<endl;
            s.erase(u);
            sumgrey-=a[u].a;
            s.insert(i);
            sumgrey+=a[i].a;
        }
        update(i);
        //cout<<i<<' '<<sumgrey<<' '<<sumplease<<endl;
    }
    //cout<<resgrey<<' '<<resplease<<endl;
}

void trace()
{
    s.clear();
    DOW(i,n,n-k+1) s.insert(i);
    DOW(i,n-k,vt)
    {
        //set<int, cmp >::iterator it=s.begin();
        int u=*s.begin();
        if (a[i].a>a[u].a||(a[i].a==a[u].a&&a[i].b>a[u].b))
        {
            //cout<<"Xoa "<<u<<" Them "<<i<<' '<<s.size()<<endl;
            s.erase(u);
            //cout<<"after erase "<<s.size()<<endl;
            //FOREACH(t,s) cout<<*t<<' ';cout<<endl;
            //cout<<"insert "<<i<<endl;
            s.insert(i);
            //cout<<"after insert "<<s.size()<<endl;
            //FOREACH(t,s) cout<<*t<<' ';cout<<endl;
        }
    }
    set<int,cmp>::iterator it;
    //cout<<s.size()<<endl;
    FOREACH(it,s) cout<<a[*it].cs<<' ';
    FOR(i,vt-k2,vt-1) cout<<a[i].cs<<' ';
}

int main()
{
    //freopen("C332.inp","r",stdin);
    //freopen("C332.out","w",stdout);
    cin>>n>>p>>k;
    FOR(i,1,n) cin>>a[i].a>>a[i].b,a[i].cs=i;
    k2=p-k;
    sort(a+1,a+1+n,mycmp2);
    process();
    trace();
    //sort(a+(p-k)+1,a+1+n,mycmp2);
    //FOR(i,1,p) cout<<a[i].cs<<' ';
    fclose(stdin);
    fclose(stdout);
    return 0;
}

