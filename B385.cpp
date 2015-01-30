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

const int maxn = 5000+10;
string st;
int res;
bool F[maxn][maxn];
int main()
{
    //freopen("B385.inp","r",stdin);
    //freopen("B385.out","w",stdout);
    getline(cin,st);
    res = 0;
    FOR(i,0,st.length()-4)
    {
        //string v = (string)st[i]+st[i+1]+st[i+2]+st[i+3];
        string v = st.substr(i,4);
        if (v=="bear")
        F[i][i+3] = true;
    }
    DOW(i,st.length()-1,0)
    FOR(j,i+4,st.length()-1)
    F[i][j] = F[i+1][j] | F[i][j-1];
    FOR(i,0,st.length()-1)
    FOR(j,i,st.length()-1)
    {if (F[i][j])res++;}
    cout<<res<<endl;

    fclose(stdin);
    fclose(stdout);
    return 0;
}

