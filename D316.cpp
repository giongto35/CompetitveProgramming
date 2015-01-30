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
const int cmod =1000000007;
int s1,s2;
long long F[1000000+10];
int n,u;
long long res;
int main()
{
    freopen("D316.inp","r",stdin);
    //freopen("D316.out","w",stdout);
    cin>>n;
    FOR(i,1,n)
    {
        cin>>u;
        if (u==1) s1++;
        else s2++;
    }
    //cout<<s1<<' '<<s2<<endl;
    F[0]=1;
    res=1;
    FOR(i,1,s1)
    {
        //F[i]=(F[i-2]*(((long long)(s1-(i-2))*(s1-(i-2)-1)/2)%cmod))%cmod;
        F[i]=(F[i-1]+(long long)(i-1)*F[i-2])%cmod;
        //cout<<res<<' '<<i<<' '<<F[i]<<endl;
        //res=(res+F[i])%cmod;
    }
    res=F[s1];
    //cout<<res<<endl;
    for(int i=s1+1;i<=s1+s2;i++)
    {
        res=((long long)res*i)%cmod;
    }
    cout<<res<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

