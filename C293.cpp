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
const double eps =0.000000001;
long long n,res;
int main()
{
    //freopen("C293.inp","r",stdin);
    //freopen("C293.out","w",stdout);
    cin>>n;
    double gh1=pow(n,(double)1/3);
    FOR(i,1,gh1)
    {
        FOR(j,i,pow(n-(long long)i*i*i,(double)1/3))
        {
            int k=n-(long long)i*i*i-(long long)j*j*j;
            double kr= pow(k,(double)1/3);
            cout<<i<<' '<<j<<' '<<kr<<endl;
            if (abs(kr-(int)(kr+eps))<=eps)res++;
        }
    }
    cout<<res<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

