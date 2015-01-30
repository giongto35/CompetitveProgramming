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
const long double oo=1100000000000000000;
vector<long double> res;
long double l,r,temp;
long double n;

long double calc(long double u,long double l)
{
    long double r;
    u=u*2+1;
    r=u*(u-1)/2;
    FOR(i,1,l)
    {
        r=r+u;
        u=u*2;
    }
    return r;
}

int main()
{
    //freopen("B325.inp","r",stdin);
    //freopen("B325.out","w",stdout);
    cin>>n;
    //n=calc(3,63);
    //cout<<fixed<<setprecision(0)<<n<<endl;
    FOR(i,0,65)
    {
        l=0;
        r=1;
        while (calc(r,i)<=n&&r<=oo/2) r=r*2;
        temp=-1;
        while (l<=r)
        {
            long double mid = (trunc)((l+r) / 2);
            long double c=calc(mid,i);
            if (c==n)
            {
                temp=mid;
                break;
            }
            else
            if (c<n) l=mid+1;
            else
                r=mid-1;
        }
        if (temp!=-1)
        {
            temp=temp*2+1;
            FOR(j,1,i) temp=temp*2;
            //cout<<temp<<' '<<i<<endl;
            res.push_back(temp);
        }
    }
    if (res.size()==0) cout<<-1;
    else
    {
        unique(res.begin(),res.end());
        sort(res.begin(),res.end());
        //union(res)
        FOR(i,0,res.size()-1)
        cout<<fixed<<setprecision(0)<<res[i]<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

