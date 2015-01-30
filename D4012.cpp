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
#include <conio.h>
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

const int maxn = 100+10;
string n;
int m;
int M10[maxn];
long long M20[maxn];
int a[maxn];
int cnt;
map<long long, long long> F;

void decode(long long i, int a[10])
{
    for (int k = 0; k <= 9; k++)
    {
        a[k] = i % 20;
        i /= 20;
    }
}

long long encode(const int a[10])
{
    long long s = 0;
    for (int k = 9; k >= 0; k--)
        s = s * 20 + a[k];
    return s;
}

long long rec(long long i,int j)
{
    if (i == 0)
    {
        return (j == 0);
    }
    long long code = i * 1000 + j;
    if (F.count(code) > 0) return F[code];
    //cnt++;
    //if (cnt % 100000 == 0) cout<<cnt<<endl;
    //int a[10];
    int scs = 0;
    F[code] = 0;

    long long c = i;
    for (int k = 0; k <= 9; k++)
    {
        scs += i % 20;
        i /= 20;
    }
    i = c;
    long long sum =0;
    for (int k = 0; k <= 9; k++)
        {
            if (i % 20 > 0)
                sum = sum + rec(c-M20[k]*(i % 20)+M20[k]*(i % 20-1),(j + k * M10[scs-1]) % m);
            i/= 20;
        }

    F[code] = sum;
    return sum;
}
int main()
{

    //freopen("D401.inp","r",stdin);
    //freopen("D401.out","w",stdout);
    cin>>n>>m;
    M10[0] = 1 % m;
    M20[0] = 1;
    for (int i = 1; i<= 20; i++)
        M10[i] = (M10[i-1] * 10) % m;
    for (int i = 1; i<= 9; i++)
        M20[i] = (M20[i-1] * 20);

    for (int i = 0; i < (int)n.length(); i++)
        a[n[i] - '0']++;
    long long s1 = rec(encode(a),0);
    long long s2 = 0;
    if (a[0] > 0)
    {
        a[0]--;
        s2 = rec(encode(a),0);
    }
    cout<<s1 - s2<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

