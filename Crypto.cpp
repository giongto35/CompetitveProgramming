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

int a[200];
int calc[1000];
int main()
{
    //freopen("","r",stdin);
    freopen("out.out","w",stdout);
    string s1 = "attack at dawn";
    string s2 = "attack at dust";
    string es1 = "6c73d5240a948c86981bc294814d";
    string es2 = "";
    for (char c = '0'; c <= '9'; c++) calc[c] = c - '0';
    for (char c= 'a'; c <= 'f'; c++) calc[c] = c - 'a' + 10;
    FOR(i,0,s1.length()-1)
    {
        int v = (s1[i] ^ s2[i]) ^ calc[es1[i]];
        if (v < 10) es2 += (char)(v + '0');else
        es2+=(char)(v - 10 +'a');
    }
    cout<<es2<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

