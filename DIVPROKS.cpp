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
const int hs = 18;
map<int,long long> ch;
int res,res2;

void gen(int vt,int tr,long long a)
{
    if (vt==hs)
    {
        res2++;
        //if (a==9) cout<<ch[a]<<endl;
        if (ch[a]==0) res++,ch[a]=1;
        return;
    }
    FOR(i,tr,9)
    gen(vt+1,i,a*i);
}

int main()
{
//    freopen("DIVPRO.inp","r",stdin);
//    freopen("DIVPRO.out","w",stdout);
    gen(1,1,1);
    cout<<res<<' '<<res2;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

