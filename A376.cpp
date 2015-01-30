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
#include <iomanip>

using namespace std ;

#define FOREACH(it,c) for( __typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define FOR(i,a,b) for( int i=(a),_b=(b);i<=_b;i++)
#define DOW(i,b,a) for( int i=(b),_a=(a);i>=_a;i--)
#define REP(i,n) FOR(i,0,(n)-1)
#define DEP(i,n) DOW(i,(n)-1,0)
#define all(a) (a).begin() , (a).end()
#define mp(a,b) make_pair((a),(b))
#define RESET(c,x) memset (c, x, sizeof (c))
#define oo 1000111000
#define PI acos(-1.0)
#define fi first
#define se second
#define SIZE(c) (c).size()

typedef vector<int> VI ;
typedef vector<string> VS ;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;

template<class T> inline int size(const T&c) { return c.size(); }

using namespace std;
int fastMax(int x, int y) { return (((y-x)>>(32-1))&(x^y))^y; }
int fastMin(int x, int y) { return (((y-x)>>(32-1))&(x^y))^x; }

string st;
long long s[3];
int vt;
int main()
{
    //freopen("A376.inp","r",stdin);
    //freopen("A376.out","w",stdout);
    getline(cin,st);
    int c = 0;
    FOR(i,0,st.length()-1)
    {
        if (st[i]=='^') vt = i;
    }
    FOR(i,0,st.length()-1)
    {
        if (st[i]=='^') c++;
        if (st[i]!='=')
            s[c] = s[c] + (st[i] - '0') * (c == 0) * (vt - i) + (st[i] - '0') * (c==1) * (i - vt);

    }
    if (s[0] >  s[1]) cout<<"left"; else
        if (s[0] < s[1]) cout<<"right"; else
        cout<<"balance";
    fclose(stdin);
    fclose(stdout);
    return 0;
}

