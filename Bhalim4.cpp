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
long long a[30+10];
map<long long,bool> c;
bool co;
long long n;
int p,T;

void GEN(int i,long long sum)
{
    if (i==p/2+1)
    {
        c[sum]=true;
        return ;
    }
    GEN(i+1,sum+a[i]);
    GEN(i+1,sum);
}

void GEN2(int i,long long sum)
{
    if (i==p+1)
    {
        if (c[n-sum]) co=true;
        return ;
    }
    GEN2(i+1,sum+a[i]);
    if (co) return ;
    GEN2(i+1,sum);
    if (co) return ;
}

int main()
{
    //freopen("Bhalim4.inp","r",stdin);
    //freopen("Bhalim4.out","w",stdout);
    cin>>T;
    FOR(ct,1,T)
    {
        cin>>n;
        cin>>p;
        FOR(i,1,p)
        cin>>a[i];
        c.clear();
        GEN(1,0);
        co=false;
        GEN2(p/2+1,0);
        if (co) cout<<"YES"<<endl;else cout<<"NO"<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

