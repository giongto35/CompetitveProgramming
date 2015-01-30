#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <set>
#include <list>
#include <map>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <deque>
using namespace std;
#define FOR(i,a,b) for (int i=a; i<=b; i++)
#define DOW(i,a,b) for (int i=a; i>=b;i--)
#define FOREACH(it,a) for (typeof(a.begin()) it=a.begin();it!=a.end();it++)
#define maxn 10005

bool avail[maxn];
vector<int> s[maxn];
int m, n, k, top, st[maxn], match[maxn], u, v;
bool found;
map<string, int> mm;
int test;
string S, S1;

void dfs(int x) {
    FOREACH(y, s[x])
        if (avail[*y]) {
            avail[*y]=false;
            if (match[*y]==0) found=true;
                else dfs(match[*y]);
            if (found) { match[*y]=x; return; }
        }
}
int main() {
    freopen("Bmini6.inp","r",stdin);
    //freopen("assign.out","w",stdout);
    //XXL, XL, L, M , S, and XS
    mm["XXL"]=0;
    mm["XL"] =1;
    mm["L"]  =2;
    mm["M"]  =3;
    mm["S"]  =4;
    mm["XS"] =5;
    cin >> test;
    FOR(t, 1, test) {
        scanf("%d%d\n", &m, &n); k=m/6;
        FOR(i, 1, m) s[i].clear();
        FOR(i, 1, n) {
            cin >> S; S1=S;
            FOR(j, k*mm[S]+1, k*(mm[S]+1)) s[j].push_back(i);
            cin >> S;
            if (S!=S1)
            FOR(j, k*mm[S]+1, k*(mm[S]+1)) s[j].push_back(i);
        }
        memset(match, 0, sizeof(match));
        top=m; FOR(i, 1, m) st[i]=i;
        while (true) {
            memset(avail, true, sizeof(avail));
            int old = top;
            int i=0;
            while (i<top) {
                i++;
                found=false;
                dfs(st[i]);
                if (found) { st[i]=st[top]; top--; i--; }
           }
           if (old == top) break;
        }
        int res = 0;
        FOR(i, 1, n) if (match[i]>0) res++;//printf("%d ", match[i]);
        if (res==n) cout << "YES"<< endl;
        else cout << "NO" << endl;
    }
   //ystem("pause");
    return 0;
}
