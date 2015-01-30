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

long long l,r;
const int maxn=10000000+10;
int F[maxn];
int d[100];
int T;

bool checkpal(long long so)
{
    int spt=0;
    while (so>0)
    {
        d[++spt]=so%10;
        so/=10;
    }
    int i=1;
    int j=spt;
    //FOR(i,1,spt) cout<<d[i];
    FOR(i,1,spt)
    while (i<=j)
        {
            if (d[i]!=d[j]) return false;
            i++;
            j--;
        }
    return true;
}

int calc(long long s)
{
    s=sqrt(s);
    return F[s];
}

void process()
{
    F[0]=0;
    FOR(i,1,10000000)
    {
        long long so=(long long)i*(long long)i;
        if (checkpal(i)&&checkpal(so)) F[i]=F[i-1]+1;else
        F[i]=F[i-1];
    }
    //cout<<F[10000000]<<endl;
}
int main()
{
    freopen("C-large-1.in","r",stdin);
    freopen("FairAndSquare.out","w",stdout);
    cin>>T;
    process();
    FOR(st,1,T)
    {
        cin>>l>>r;
        cout<<"Case #"<<st<<": ";
        cout<<calc(r)-calc(l-1)<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

