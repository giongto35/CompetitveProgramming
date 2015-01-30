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
int a[maxn],n,m;
char com;
double s[maxn];
int ch,qh,vt;

inline void update(int hl,int hr,int dau)
{
    double sum=0;
    int tg;
    if (hr<hl) tg=hr,hr=hl,hl=tg;
    double y=1;
    FOR(i,1,1000)
    {
        if (i<=hl) sum+=1;
        else
        if (i<=hr)
        {
            double x = (double)(hr-i)/(double)(hr-hl);
            sum+=(x+y)/(2.0);
            y=x;
        }
        //cout<<hl<<' '<<hr<<' '<<sum<<' '<<i<<' '<<y<<endl;
        s[i]=s[i]+dau*sum;
    }
}

int main()
{
    //freopen("akvarij.inp","r",stdin);
    //freopen("akvarij.out","w",stdout);
    scanf("%d%d",&n,&m);
    FOR(i,0,n-1) scanf("%d",&a[i]);
    FOR(i,0,n-2) update(a[i],a[i+1],1);
    FOR(i,1,m)
    {
        cin>>com;
        if (com=='Q')
        {
            scanf("%d",qh);
            printf("%0.3f\n",qh*(n-1)-s[qh]);
        }
        else
        {
            scanf("%d %d",vt,ch);
            if (vt>0) update(a[vt-1],a[vt],-1),update(a[vt-1],ch,+1);
            if (vt<n-1) update(a[vt],a[vt+1],-1),update(ch,a[vt+1],+1);
            a[vt]=ch;
        }
        //getline(cin,st);
        //cout<<"abc"<<com<<' '<<qh<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

