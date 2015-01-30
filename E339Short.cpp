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

const int maxn=1000+10;
int a[maxn];
int c[maxn];
int d[maxn];
vector<pair<int,int> > kq;
int spt;
int n;

int cnt (int l,int r)
{
    int res=0;
    for (int i=l;i<=r;i+=2)
        res=res+abs(d[i+1]-d[i])+1;
    return res;
}

void reverse (int l,int r)
{
    int tg;
    while (l<=r)
    {
        tg=d[l];d[l]=d[r];d[r]=tg;
        l++;
        r--;
    }
}
int main()
{
    freopen("E339.inp","r",stdin);
    //freopen("E339.out","w",stdout);
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d",&a[i]);
    bool ok=true;
    FOR(i,1,n) if (a[i]!=i) ok=false;
    if (ok)
    {
        cout<<0;
        return 0 ;
    }
    int i=1;
    while (i<=n)
    {
        int j=i;
        if (a[j]+1==a[j+1])
        {
            while (j<n&&a[j]+1==a[j+1]) j++;
        }
        else
        {
            while (j<n&&a[j]-1==a[j+1]) j++;
        }
        c[++spt]=a[i];
        c[++spt]=a[j];
        i=j+1;
    }


    for(int i1=1;i1<=spt;i1+=2)for(int j1=i1+1;j1<=spt;j1+=2)
    {
        FOR (k,1,spt) d[k]=c[k];
        reverse(i1,j1);
        bool ok=true;
        FOR(i,2,spt) if (d[i]<d[i-1]) {ok=false;break;}
        if (ok)
        {
            FOR (k,1,spt) d[k]=c[k];

            cout<<1<<endl;
            kq.push_back(make_pair(cnt(1,i1-2)+1,cnt(1,j1)));
            reverse(i1,j1);
            DOW(i,kq.size()-1,0) cout<<kq[i].first<<' '<<kq[i].second<<endl;
            return 0;
        }
    }

    for(int i1=1;i1<=spt;i1+=2)for(int j1=i1+1;j1<=spt;j1+=2)
    for(int i2=1;i2<=spt;i2+=2)for(int j2=i2+1;j2<=spt;j2+=2)
    {
        FOR (k,1,spt) d[k]=c[k];
        reverse(i1,j1);
        reverse(i2,j2);
        bool ok=true;
        FOR(i,2,spt) if (d[i]<d[i-1]) {ok=false;break;}
        if (ok)
        {
            FOR (k,1,spt) d[k]=c[k];

            cout<<2<<endl;
            kq.push_back(make_pair(cnt(1,i1-2)+1,cnt(1,j1)));
            reverse(i1,j1);
            kq.push_back(make_pair(cnt(1,i2-2)+1,cnt(1,j2)));
            reverse(i2,j2);
            DOW(i,kq.size()-1,0) cout<<kq[i].first<<' '<<kq[i].second<<endl;
            return 0;
        }
    }
    FOR(i,1,spt) cout<<c[i]<<' ';cout<<endl;
    for(int i1=1;i1<=spt;i1+=2)for(int j1=i1+1;j1<=spt;j1+=2)
    for(int i2=1;i2<=spt;i2+=2)for(int j2=i2+1;j2<=spt;j2+=2)
    for(int i3=1;i3<=spt;i3+=2)for(int j3=i3+1;j3<=spt;j3+=2)
    {
        FOR (k,1,spt) d[k]=c[k];
        reverse(i1,j1);
        reverse(i2,j2);
        reverse(i3,j3);
        bool ok=true;
        FOR(i,2,spt) if (d[i]<d[i-1]) {ok=false;break;}
        if (ok)
        {
            FOR (k,1,spt) d[k]=c[k];

            cout<<3<<endl;
            kq.push_back(make_pair(cnt(1,i1-2)+1,cnt(1,j1)));
            reverse(i1,j1);
            kq.push_back(make_pair(cnt(1,i2-2)+1,cnt(1,j2)));
            reverse(i2,j2);
            kq.push_back(make_pair(cnt(1,i3-2)+1,cnt(1,j3)));
            reverse(i3,j3);
            DOW(i,kq.size()-1,0) cout<<kq[i].first<<' '<<kq[i].second<<endl;
            return 0;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

