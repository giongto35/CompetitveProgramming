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
vector<int> a[1000000+10];
int t,c;
int res1,res2,n;
int main()
{
    //freopen("A292.in","r",stdin);
    //freopen("A292.out","w",stdout);
    cin>>n;
    FOR(i,1,n)
    {
        cin>>t>>c;
        a[t].push_back(c);
    }
    c=0;
    res1=0;
    res2=0;
    FOR(i,1,1000000)
    {
        if (c>0) c--;
        FOR(j,0,a[i].size()-1)
        {
            c+=a[i][j];
            res1=max(res1,i+c);
        }
        res2=max(res2,c);
    }
    cout<<res1<<' '<<res2<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

