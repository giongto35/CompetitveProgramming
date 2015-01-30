    #include <sstream>
    #include <iomanip>
    #include <iostream>
    #include <cstdio>
    #include <cstring>
    #include <cstdlib>
    #include <cmath>
    #include <algorithm>
    #include <vector>
    #include <set>
    #include <map>
    #include <stack>
    #include <queue>
    #include <string>
    #include <deque>
    #include <complex>

    #define FOR(i,a,b) for(int i=(a),_b=(b); i<=_b; i++)
    #define FORD(i,a,b) for(int i=(a),_b=(b); i>=_b; i--)
    #define REP(i,a) for(int i=0,_a=(a); i<_a; i++)
    #define FORN(i,a,b) for(int i=(a),_b=(b);i<_b;i++)
    #define DOWN(i,a,b) for(int i=a,_b=(b);i>=_b;i--)
    #define SET(a,v) memset(a,v,sizeof(a))
    #define sqr(x) ((x)*(x))
    #define ll long long
    #define F first
    #define S second
    #define PB push_back
    #define MP make_pair

    #define DEBUG(x) cout << #x << " = "; cout << x << endl;
    #define PR(a,n) cout << #a << " = "; FOR(_,1,n) cout << a[_] << ' '; cout << endl;
    #define PR0(a,n) cout << #a << " = "; REP(_,n) cout << a[_] << ' '; cout << endl;
    using namespace std;

    //Buffer reading
    int INP,AM,REACHEOF;
    const int BUFSIZE = (1<<12) + 17;
    char BUF[BUFSIZE+1], *inp=BUF;
    #define GETCHAR(INP) { \
    if(!*inp && !REACHEOF) { \
    memset(BUF,0,sizeof BUF);\
    int inpzzz = fread(BUF,1,BUFSIZE,stdin);\
    if (inpzzz != BUFSIZE) REACHEOF = true;\
    inp=BUF; \
    } \
    INP=*inp++; \
    }
    #define DIG(a) (((a)>='0')&&((a)<='9'))
    #define GN(j) { \
    AM=0;\
    GETCHAR(INP); while(!DIG(INP) && INP!='-') GETCHAR(INP);\
    if (INP=='-') {AM=1;GETCHAR(INP);} \
    j=INP-'0'; GETCHAR(INP); \
    while(DIG(INP)){j=10*j+(INP-'0');GETCHAR(INP);} \
    if (AM) j=-j;\
    }
    //End of buffer reading

    const long double PI = acos((long double) -1.0);
    const int MN = 100111;

    int n, a[MN], v[MN];
    long double x[MN];

    long double get(long double t) {
    FOR(i,1,n) x[i] = a[i] + v[i] * t;
    return *max_element(x+1, x+n+1) - *min_element(x+1, x+n+1);
    }

    void duyet() {
    long double res = *max_element(a+1, a+n+1) - *min_element(a+1, a+n+1);

    FOR(i,1,n) FOR(j,1,n) {
    if (v[j] == v[i]) continue;
    long double t = (a[i] - a[j]) / (long double) (v[j] - v[i]);

    if (t < 0) continue;

    res = min(res, get(t));
    }
    if (abs(res) < 1e-6) res = 0.0;
    cout << (fixed) << setprecision(3) << res / 2.0 << endl;
    }

    long double range(long double l, long double r, int MAX_TURN = 200) {
    long double res = 1e100;
    res = min(res, get(r));
    REP(turn,MAX_TURN) {
    long double x1 = (l*2 + r) / 3.0;
    long double x2 = (l + r*2) / 3.0;
    long double y1 = get(x1), y2 = get(x2);

    res = min(res, min(y1, y2));

    if (y1 < y2) r = x2;
    else l = x1;
    }
    return res;
    }

    void solve() {
    long double res = *max_element(a+1, a+n+1) - *min_element(a+1, a+n+1);
    res = min(res, range(0, 1e10));
    if (res < 0) res = 0;
    if (abs(res) < 1e-6) res = 0.0;
    cout << (fixed) << setprecision(3) << res / 2.0 << endl;
    }

    int main() {
        freopen("C11ANT.inp","r",stdin);
    scanf("%d", &n);
    FOR(i,1,n) scanf("%d", &a[i]);
    FOR(i,1,n) scanf("%d", &v[i]);

    if (n <= 100) duyet(); else solve();
    return 0;
    }
