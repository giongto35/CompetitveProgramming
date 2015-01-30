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

const int maxn  = 200;
const int maxl = 1000000;
string st;
int rnd[maxl+10];
int ok[maxn];
bool c[maxn];
int spt;
int res;

/*void swap(char &c1, char &c2)
{
    char tg;
    tg = c1;c1=c2;c2=tg;
}*/
int main()
{
    //freopen("C376.inp","r",stdin);
    //freopen("C376.out","w",stdout);
    getline(cin,st);
    //FOR(i,0,st.length()-1)  rnd[i+1] = i;
    FOR(x,1,80)
    {
        FOR(i,1,st.length()-1)
        {
            swap(st[rand() % (i+1)], st[i]);
        }
        res = 0;
        FOR(i,0,st.length()-1)
        {
            res = (res * 10 + (st[i] - '0')) % 7;
        }
        if (res == 0) {cout<<st; return 0;}
    }
    cout<<0;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

