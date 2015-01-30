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
int TC;
int n,a[1000000+10];
int res,cnt,x;

bool check(int x)
{
    cnt=0;
    FOR(i,1,n)
    {
        if (a[i]==x) cnt++;
        //if (n-i+cnt<=n/2) return false;
    }
    if (cnt>n/2) return true; else return false;
}

int main()
{
    //freopen("Ahalim2.inp","r",stdin);
    //freopen("Ahalim2.out","w",stdout);
    cin>>TC;
    while (TC>0)
    {
        cin>>n;
        FOR(i,1,n) scanf("%d",&a[i]);
        res=-1;
        FOR(i,1,4)
        {
            x=a[(rand())%n+1];
            if (check(x))
            {
                res=x;
                break;
            }
        }
        cout<<res<<endl;
        TC--;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}


