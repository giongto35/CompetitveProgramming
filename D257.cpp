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
int a[100000+10];
int dau[100000+10],doidau[100000+10];
long long sum;
int ht;
int n;
int main()
{
    //freopen("D257.inp","r",stdin);
    //freopen("D257.out","w",stdout);
    cin>>n;
    FOR (i,1,n)
        scanf("%d",&a[i]);
    sum=a[n];
    dau[n]=1;
    doidau[1]=1;
    DOW (i,n-1,1)
    {
        if (sum>a[i]) sum-=a[i],dau[i]=-1,doidau[i+1]=1;
        else
        sum=a[i]-sum,dau[i]=1,doidau[i+1]=-1;
//        cout<<i<<' '<<dau[i]<<' '<<doidau[i+1]<<endl;
    }

    ht =1;
    FOR (i,1,n)
    {
        ht=ht*doidau[i];
        if (dau[i]*ht==1) cout<<'+'; else cout<<'-';
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

