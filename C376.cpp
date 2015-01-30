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
char ch[4] = {'1','6','8','9'};
string st;
int rnd[maxl+10];
int ok[maxn];
int c0;
bool c[maxn];
int spt;
bool found;
int l;
void factgen(int n)
{
    if (n==4)
    {
        int res = 0;
        FOR(j,0,st.length()-1)
        res = (res * 10 + st[j] - '0') % 7;
        if (res == 0)
        {
            cout<<st<<endl;
            found = true;
        }
        return;
    }
    FOR(i,0,3)
    {
        char j = ch[i] ;
        if (!ok[j])
        {
            st[l - n] = j ;
            ok[j]=true;
            factgen(n+1);
            if (found) return;
            ok[j]=false;
        }
    }
}

int main()
{
    //freopen("C376.inp","r",stdin);
    //freopen("C376.out","w",stdout);
    getline(cin,st);
    l = st.length() - 1;
    FOR(i,0,l) if (st[i] == '0') c0++;
    l -= c0;
    FOR(i,0,st.length()-1)
    {
        FOR(j,0,3)
        if (st[i] == ch[j])
        {
            swap(st[i], st[l - j]);
        }
    }
    factgen(0);

    fclose(stdin);
    fclose(stdout);
    return 0;
}

