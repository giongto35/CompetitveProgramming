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
long long n;
const double eps =0.1;
long long res,res2;
long long l,r;
long long a,b,c,n2,z;

long long bnrsearch(long long l,long long r,long long x)
{
    long long res=l;
    long long mid;
    //cout<<l<<' '<<r<<endl;
    while (l<=r)
    {
        mid = (l+r)/2;
        //cout<<mid<<' '<<x<<' '<<mid<<' '<<(n+0.0)/x/mid<<endl;
        if (x+mid>(n+0.0)/x/mid)
        {
            //cout<<"CO"<<endl;
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
    //freopen("C292.inp","r",stdin);
    //freopen("C292.out","w",stdout);
    cin>>n;
    res=0;
    if (n%3!=0)
    {
        cout<<"0";
    }
    else
    {
        n/=3;
        int gh1=pow(n+eps,(double)1/3);
        double gh2=pow(4*n+eps,(double)1/3);
        res2=0;
        for(int x=1;x<=gh1;x++)
        {
            if (n%x!=0) continue;
            l=max(x,(int)gh2-x+1);
            //cout<<gh2<<endl;
            //getch();
            n2=n/x;
            r=sqrt(n2+eps);
            l=bnrsearch(l,r,x);
            //cout<<x<<' '<<l<<' '<<n/x/l<<endl;
            for(long long y=l;y<=r;y++)
            {
                if (n2%y!=0) continue;
                z=n2/y;
                if (x<=y&&y<=z&&(x+y+z)%2==0)
                {

                    b=(x+y)-z;
                    c=(y+z)-x;
                    a=(z+x)-y;
                    if (a>0&&b>0&&c>0)
                    {
                        if (a==b&&a==c) res++;
                        else
                        if (a==b||a==c||c==b) res+=3;
                        else
                        res+=6;
                    //cout<<' '<<x<<' '<<y<<' '<<z<<' '<<a<<' '<<b<<' '<<c<<endl;
                    }
                    //else
                        //cout<<x<<' '<<y<<' '<<z<<' '<<a<<' '<<b<<' '<<c<<endl;
                }
            }
        }
        cout<<res<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

