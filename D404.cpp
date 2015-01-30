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

const int maxn = 1000000+10;
const int cmod = 1000000007;
string st;
int F[maxn][7];


int main()
{
    //freopen("D404.inp","r",stdin);
    //freopen("D404.out","w",stdout);
    getline(cin,st);
    //for (int i = 1; i<=1000000; i++ ) st = st.append("*");
    //cout<<"XONG"<<endl;
    int n = st.length();
    st = " " + st;
    if (st[1] == '?')
    {
        F[1][0] = 1;
        F[1][3] = 1;
        F[1][4] = 1;
    }
    else
    {
        if (st[1] == '*') F[1][0] = 1;else
        if (st[1] == '1') F[1][3] = 1;else
        if (st[1] == '0') F[1][4] = 1;
    }
    for(int i = 1; i < n; i++)
    {
        //j == 0
        if (st[i+1] == '*' || st[i+1] == '?')
        {
            F[i+1][0] = (F[i+1][0] + F[i][0]) % cmod;
            F[i+1][0] = (F[i+1][0] + F[i][1]) % cmod;
            F[i+1][0] = (F[i+1][0] + F[i][3]) % cmod;
        }
        if (st[i+1] == '2' || st[i+1] == '?')
        {
            F[i+1][1] = (F[i+1][1] + F[i][0]) % cmod;
        }
        if (st[i+1] == '1' || st[i+1] == '?')
        {
            F[i+1][2] = (F[i+1][2] + F[i][0]) % cmod;
            F[i+1][3] = (F[i+1][3] + F[i][2]) % cmod;
            F[i+1][3] = (F[i+1][3] + F[i][4]) % cmod;
        }
        if (st[i+1] == '0' || st[i+1] == '?')
        {
            F[i+1][4] = (F[i+1][4] + F[i][2]) % cmod;
            F[i+1][4] = (F[i+1][4] + F[i][4]) % cmod;
        }
//      cout<<i<<' '<<F[i][0]<<' '<<F[i][1]<<' '<<F[i][2]<<' '<<F[i][3]<<' '<<F[i][4]<<endl;
    }
//      cout<<n<<' '<<F[n][0]<<' '<<F[n][1]<<' '<<F[n][2]<<' '<<F[n][3]<<' '<<F[n][4]<<endl;
    long long res = 0;
    res = (res + F[n][0]) % cmod;
    res = (res + F[n][2]) % cmod;
    res = (res + F[n][4]) % cmod;
    cout<<res<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

