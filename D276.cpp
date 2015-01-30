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
const int maxn=100;
long long l,r;
int s;
int s1[maxn+10];
int s2[maxn+10];
long long kq;
int main()
{
    //freopen("D276.inp","r",stdin);
    //freopen("D276.out","w",stdout);
    cin>>l>>r;
    s=0;
    while(l>0)
    {
       s1[++s]=l%2;
       l/=2;
    }
    s=0;
    while(r>0)
    {
       s2[++s]=r%2;
       r/=2;
    }
    kq=0;
    DOW(i,maxn,1)
    {
        if (s1[i]!=s2[i])
        {
            kq=1;
            FOR(j,1,i) kq*=2;
            kq-=1;
            break;
        }
    }
    cout<<kq;
    fclose(stdin);
    fclose(stdout);
    return 0;
}


