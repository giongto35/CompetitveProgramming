#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <string>
using namespace std;
#define FOR(i, a, b) for(int i=a; i<=b; i++)
#define DOW(i, a, b) for(int i=a; i>=b; i--)
#define FOREACH(it, c) for(typeof(c.begin()) it=c.begin(); it!=c.end(); it++)
#define RESET(c, val) memset(c, val , sizeof(c))
#define maxn 5000
#define oo 100000000
#define maxm 100005

int n, m, test, ns;
int win[maxn];
int a[maxn][maxn], x[maxn], k;
struct edge{ int x; int y; int c; int f; } e[maxm];
vector<int> s[maxn];
int las, fir, res;
int q[maxm], tra[maxn];
string ST[maxn];

int cf(int i) {return e[i].c-e[i].f;}
bool findF() {
    RESET(tra, 0);
    fir=0, las=0;
    q[0]=1; tra[1]=-1;
    while (fir<=las) {
        int u=q[fir]; fir++;
        FOREACH(i, s[u])
            if (tra[e[*i].y]==0 && cf(*i)>0) {
                tra[e[*i].y]=*i;
                las++, q[las]=e[*i].y;
                if (q[las]==n) return true;
            }
    }
    return false;
}
void IncFlow() {
    int u=n, delta=oo, i;
    while (u!=1) {
        i=tra[u];
        delta=min(delta, cf(i));
        u=e[i].x;
    }
    res+=delta;
    u=n;
    while (u!=1) {
        i=tra[u];
        e[i].f+=delta;
        if (i<=m) e[i+m].f-=delta; else e[i-m].f-=delta;
        u=e[i].x;
    }
}
int main() {
     freopen("C6.inp", "r", stdin);
   // freopen("test.out", "w", stdout);
    test=0;
    while (cin >> ns) {
        if (ns == -1) break;
        printf("Case %d:\n", ++test);
        FOR(i, 1, ns) {
               cin >> ST[i] >> win[i] >> m >> x[i];
               FOR(j, 1, ns) scanf("%d", &a[i][j]);
        }
        FOR(i, 1, ns) {
            k = win[i] + x[i];

            bool flag = false;
            FOR(j, 1, ns) if (j != i && win[j] > k) flag = true;
            if (flag) {
                cout << "Team " << ST[i] << " is eliminated." << endl;
                continue;
            }
            m = 0;
            FOR(j, 1, ns) if (j != i) {
                   m ++;
                   e[m].x = 1; e[m].y = j + 1; e[m].f = 0; e[m].c = k - win[j];
            }
            n = ns + 1; int T = n + ns*(ns-1)/2 + 1 - (ns-1), Count = 0;
            FOR(j, 1, ns) FOR(z, j + 1, ns) if (j != i && z != i) {
                   n ++;
                   m ++;
                   e[m].x = j + 1; e[m].y = n; e[m].f = 0; e[m].c = oo;
                   m ++;
                   e[m].x = z + 1; e[m].y = n; e[m].f = 0; e[m].c = oo;
                   m ++;
                   e[m].x = n; e[m].y = T; e[m].f = 0; e[m].c = a[j][z];
                   Count += a[j][z];
            } n ++;
            FOR(j, 1, m) {
                e[j+m]=e[j];
                swap(e[j+m].x, e[j+m].y); e[j+m].c=0;
            }
            FOR(j, 1, n) s[j].clear();
            FOR(j, 1, m*2) s[e[j].x].push_back(j);
            res=0;
            while (findF()) IncFlow();
            if (res < Count) cout << "Team " << ST[i] << " is eliminated." << endl;
        }
        cout << endl;
    }
    return 0;
}
