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

int M;

unsigned x = 123456789, y = 362436069, z = 521288629, w = 88675123;

unsigned next_BP() { // do not alter this function

  unsigned t = x ^ (x << 11);

  x = y; y = z; z = w;

  w = (w ^ (w >> 19)) ^ (t ^ (t >> 8));

  return w % M;

}

long long s;
long long s2;
long long a;
long double bc;
long long E;
long long sl;
int N,res;
int main()
{
    //freopen("Bhalim7.inp","r",stdin);
    //freopen("Bhalim7.out","w",stdout);
    while (scanf("%d%d%d",&N,&E,&M)==3)
    {
        res=1;
        s=0;
        sl=0;
        s2=0;
        FOR(i,1,N)
        {
            a=next_BP();
            sl+=1;
            s+=a;
            s2+=a*a;
            bc=s2-s*s/sl;
            //cout<<a<<' '<<s<<' '<<s2<<' '<<bc<<endl;
            if (bc>E)
            {
                res++;
                s=a;
                s2=a*a;
                sl=1;
            }
        }
        cout<<res<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

