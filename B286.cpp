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
const int maxn = 1000000+10;
int a[maxn*3];
int r,n;
int main()
{
    //freopen("B286.inp","r",stdin);
    //freopen("B286.out","w",stdout);
    cin>>n;
    FOR(i,1,n) a[i]=i;
    r=1;
    FOR(i,2,n)
    {
        r++;
        if (n%i!=0)
            a[r+n-1]=a[r+(n/i)*i-1];
        DOW(j,n/i,1)
            a[r+j*i-1]=a[r+(j*i)-1-i];
        //FOR(i,1,n) cout<<a[r+i-1]<<' ';cout<<endl;
    }
    FOR(i,1,n) cout<<a[r+i-1]<<' ';
    fclose(stdin);
    fclose(stdout);
    return 0;
}

