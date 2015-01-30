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
int res,T,n;
int a[1000+10];
int main()
{
    //freopen("ahalim4.inp","r",stdin);
    //freopen("ahalim4.out","w",stdout);
    cin>>T;
    FOR(ct,1,T){
        cin>>n;
        res=0;
        FOR (i,1,n)
        {
            cin>>a[i];
            if (i>1)
            FOR(j,1,i-1)
            if (a[i]>=a[j]) res++;
        }
        cout<<res<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

