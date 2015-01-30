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
#include <complex>
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

const int maxn = 300000+10;

int n;
typedef complex<double> base;
base a[maxn];
base b[maxn];
base c[maxn];
base d[maxn];
int cnt[maxn];
int rev[maxn];
int nm;
int u;
base wlen_pw[maxn];
void eval(base a[], int n, bool invert) {
    for (int i=0; i<n; ++i)
        if (i < rev[i]) swap (a[i], a[rev[i]]);
    for (int len=2; len<=n; len<<=1) {
        double ang = 2*PI/len * (invert?-1:+1);
        int len2 = len>>1;
        base wlen (cos(ang), sin(ang));
        wlen_pw[0] = base (1, 0);
        for (int i=1; i<len2; ++i)
            wlen_pw[i] = wlen_pw[i-1] * wlen;
        for (int i=0; i<n; i+=len) {
            base t,
                *pu = a+i,
                *pv = a+i+len2,
                *pu_end = a+i+len2,
                *pw = wlen_pw;
            for (; pu!=pu_end; ++pu, ++pv, ++pw) {
                t = *pv * *pw;
                *pv = *pu - t;
                *pu += t;
            }
        }
    }
    if (invert)
        for (int i=0; i<n; ++i)
            a[i] /= n;
}

void calc_rev(int n, int log_n) {
    for (int i=0; i<n; ++i) {
        rev[i] = 0;
        for (int j=0; j<log_n; ++j)
            if (i & (1<<j))
                rev[i] |= 1<<(log_n-1-j);
    }
}

void FFT()
{
    int outN = 1;
    n = 100000;
    int lgN = 0;
    while (outN < n) outN *= 2, lgN ++;
    outN *= 2;
    //cout<<outN<<' '<<lgN<<endl;
    calc_rev(outN, lgN + 1);
    eval(a, outN, false);
    eval(b, outN, false);
    for (int i = 0; i <= outN; i++)
        d[i] = a[i] * b[i];
    eval(d, outN, true);
}


int main()
{
    freopen("POST2.inp","r",stdin);
    //freopen("POST2.out","w",stdout);
    scanf("%d",&n);
    nm = n;
    memset(cnt,0,sizeof(cnt));
    for (int i = 1; i <= n; i++)
    {
        scanf("%d",&u);
        cnt[u + 50000]++;
        a[u + 50000] = cnt[u + 50000];
    }
    memset(cnt,0,sizeof(cnt));
    for (int i = 1; i <= n; i++)
    {
        scanf("%d",&u);
        cnt[u + 50000]++;
        b[u + 50000] = cnt[u + 50000];
    }
    FFT();
    memset(cnt,0,sizeof(cnt));
    base res = base(0,0);
    for (int i = 1; i <= nm; i++)
    {
        scanf("%d",&u);
        //cout<<u + 100000<<' '<< d[u + 100000]<<endl;
        //cnt[u]++;
        //c[u] = cnt[u];
        res = res + d[u + 100000];
    }
    cout<<(round)(real(res))<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

