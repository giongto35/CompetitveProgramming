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
int n,m;
int a[100000*2+10];
int s[3];
int res1,res2,res3,res4,tg;

void calc(int n,int m,int &res1,int &res2)
{
    s[1]=n;s[2]=m;
    int sl=n+m;
    res1=0;res2=0;
    a[0]=2;
    FOR(i,1,sl)
    {
        if (i%2==0) if (s[3-a[i-1]]>0) a[i]=3-a[i-1]; else a[i]=a[i-1];
        if (i%2==1) if (s[a[i-1]]>0) a[i]=a[i-1]; else a[i]=3-a[i-1];
        s[a[i]]--;
        //cout<<a[i];
        if (i>1){if (a[i]==a[i-1]) res1++; else res2++;}
    }
}

int main()
{
    //freopen("B257.inp","r",stdin);
    //freopen("B257.out","w",stdout);
    cin>>n>>m;
    calc(n,m,res1,res2);
    calc(m,n,res3,res4);
    if (res1>res3) cout<<res1<<' '<<res2; else
    cout<<res3<<' '<<res4;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
