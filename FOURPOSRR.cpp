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
    const long long MN = 100111;

    int n, a[MN];
    struct Pos {
    int p1, p2, p3, p4;
    } x[MN], tmp[MN];

    bool operator < (const Pos &a, const Pos &b) {
    return a.p1 < b.p1;
    }

    #define _(x) ((x) & (-(x)))

    vector<int> f[MN], nodes[MN];

    inline void update(int x, int y, int k) {
    for(int u = x; u <= n; u += _(u)) {
    for(int v = lower_bound(nodes[u].begin(), nodes[u].end(), y) - nodes[u].begin() + 1;
    v <= nodes[u].size(); v += _(v))
    f[u][v] += k;
    }
    }

    inline int get(int x, int y) {
    int res = 0;
    for(int u = x; u > 0; u -= _(u)) {
    for(int v = lower_bound(nodes[u].begin(), nodes[u].end(), y) - nodes[u].begin() + 1;
    v > 0; v -= _(v))
    res += f[u][v];
    }
    return res;
    }

    long long res;
    void conquer(int l, int r) {
    if (l == r) return ;

    int mid = (l + r) >> 1;
    conquer(l, mid);
    conquer(mid+1, r);

    FOR(i,l,r) tmp[i] = x[i];

    // FOR(i,l,mid) cout << x[i].p2 << ' ' << x[i].p3 << ' ' << x[i].p4 << " "; cout << endl;
    // FOR(i,mid+1,r) cout << x[i].p2 << ' ' << x[i].p3 << ' ' << x[i].p4 << " "; cout << endl;

    int j = l, i1 = l;
    FOR(i2,mid+1,r) {
    while (i1 <= mid && tmp[i1].p2 < tmp[i2].p2) {
    update(tmp[i1].p3, tmp[i1].p4, +1);
    // cout << "Add: " << tmp[i1].p3 << ' ' << tmp[i1].p4 << endl;
    x[j++] = tmp[i1];
    ++i1;
    }
    res += get(tmp[i2].p3, tmp[i2].p4);
    // cout << "Get: " << tmp[i2].p3 << ' ' << tmp[i2].p4 << ' ' << res << endl;
    x[j++] = tmp[i2];
    }
    FOR(z,l,i1-1) {
    update(tmp[z].p3, tmp[z].p4, -1);
    // cout << "Remove: " << tmp[z].p3 << ' ' << tmp[z].p4 << endl;
    }
    while (i1 <= mid) x[j++] = tmp[i1++];
    }

    void solve() {
    res = 0;
    FOR(i,1,n) {
    int u = x[i].p3;
    while (u <= n) {
    nodes[u].push_back(x[i].p4);
    u += _(u);
    }
    u = x[i].p3;
    while (u > 0) {
    nodes[u].push_back(x[i].p4);
    u -= _(u);
    }
    }
    FOR(i,1,n) {
    sort(nodes[i].begin(), nodes[i].end());
    nodes[i].resize(unique(nodes[i].begin(), nodes[i].end()) - nodes[i].begin());
    f[i].resize(nodes[i].size() + 3);
    }

    // FOR(i,1,n) cout << x[i].p1 << ' ' << x[i].p2 << ' ' << x[i].p3 << ' ' << x[i].p4 << endl;
    conquer(1, n);
    cout << res << endl;
    return ;

    long long res2 = 0;
    sort(x+1, x+n+1);
    // FOR(i,1,n) cout << x[i].p1 << ' ' << x[i].p2 << ' ' << x[i].p3 << ' ' << x[i].p4 << endl;

    FOR(i,1,n) FOR(j,i+1,n) {
    if (x[i].p2 < x[j].p2
    && x[i].p3 < x[j].p3
    && x[i].p4 < x[j].p4
    && x[i].p1 < x[j].p1) {
    ++res2;
    }
    }
    cout << res2 << endl;
    }

    int main() {
        freopen("FOURPOS.inp","r",stdin);
    GN(n);
    FOR(i,1,n) GN(a[i]);
    FOR(i,1,n) x[a[i]].p1 = i;

    FOR(i,1,n) GN(a[i]); reverse(a+1, a+n+1);
    FOR(i,1,n) x[a[i]].p2 = i;

    FOR(i,1,n) GN(a[i]);
    FOR(i,1,n) x[a[i]].p3 = i;

    FOR(i,1,n) GN(a[i]); reverse(a+1, a+n+1);
    FOR(i,1,n) x[a[i]].p4 = i;

    sort(x+1, x+n+1);
    solve();
    return 0;
    }

