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
const int maxn=1000000+10;
int F[maxn][2];
string s;
int main()
{
    //freopen("E279.inp","r",stdin);
    //freopen("E279.out","w",stdout);
    getline(cin,s);
    //s=string(s.rbegin(),s.rend());
    int i=0;
    int res=0;
    s=s+"00";
    while (i<=s.length()-1)
    {
        if (s[i]=='1')
        {
            int j=i;
            while (s[i+1]=='1'||(s[i+1]=='0'&&s[i+2]!='0')) i++;
            int sum1=0;
            int sum0=0;
            FOR(k,j,i)
            if (s[k]=='1') sum1++; else sum0++;
            res=res+min(sum1,2+sum0);
        }
        i++;
    }
    cout<<res;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
