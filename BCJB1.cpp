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
const int maxn=1000000+10;
int x,y,tg;
int a[maxn];
int T,s,t,k;
bool rev;
bool rx,ry;
int main()
{
    freopen("B-large-practice.in","r",stdin);
    freopen("BCJB1.out","w",stdout);
    cin>>T;
    FOR(cT,1,T)
    {
        cin>>x>>y;
        rx=false;ry=false;
        if (x<0) x=-x,rx=true;
        if (y<0) y=-y,ry=true;
        s=0;
        k=0;
        while (s<x+y||(s>(x+y)&&(s-(x+y))%2==1)) s+=++k;
        FOR(i,1,k) a[i]=1;
        DOW(i,k,1)
        if (s-i*2>=x+y)
        {
            s-=i*2;
            a[i]=-1;
        }
        rev=false;
        if (y>x)
        {
            int tg=x;x=y;y=tg;
            rev=true;
        }
        DOW(i,k,1)
        {
            if (a[i]==1&&y>=i)
            {
                y-=i;
                a[i]=2;
            }
        }
        if (rev)
        {
            FOR(i,1,k)
            {
                if (a[i]==-1) a[i]=-2;else
                if (a[i]==1) a[i]=2;else
                if (a[i]==2) a[i]=1;
            }
        }
        if (rx) FOR(i,1,k) if (a[i]==-1||a[i]==1) a[i]=-a[i];
        if (ry) FOR(i,1,k) if (a[i]==-2||a[i]==2) a[i]=-a[i];
        cout<<"Case #"<<cT<<": ";
        FOR(i,1,k)
        {
            if (a[i]==1) cout<<'E';
            if (a[i]==-1) cout<<'W';
            if (a[i]==2) cout<<'N';
            if (a[i]==-2) cout<<'S';
        }
        cout<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

