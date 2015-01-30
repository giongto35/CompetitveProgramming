#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <string>
#include <set>
using namespace std;
#define FOR(i, a, b) for(int i=a; i<=b; i++)
#define DOW(i, a, b) for(int i=a; i>=b; i--)
#define FOREACH(it, c) for(typeof(c.begin()) it=c.begin(); it!=c.end(); it++)
#define RESET(c, val) memset(c, val , sizeof(c))
#define maxn 100005
//#include <conio.h>
set<int> s;
int f[maxn];
int n, k, u, v, a[maxn];
char ch;

void update(int i, int v) {
    while (i<=n) f[i]+=v, i+=i&(-i);
}
int get(int i) {
    int res=0;
    while (i!=0) res+=f[i], i-=i&(-i);
    return res;
}
int main() {
    //freopen("test.inp", "r", stdin);
    //freopen("test.ou", "w", stdout);
    while (scanf("%d%d\n", &n, &k)!=EOF) {
        s.clear(); RESET(f, 0);
        FOR(i, 1, n) {
            scanf("%d", &a[i]);
            if (a[i]==0) s.insert(i);
            else if (a[i]<0) update(i, 1);
        }
        scanf("\n");
        FOR(i, 1, k) {
            scanf("%c%d%d\n", &ch, &u, &v);
            if (ch=='C') {
                if (a[u]>0 && v<0) update(u, 1);
                else if (a[u]<0 && v>0) update(u, -1);
                else if (a[u]==0 && v!=0) {
                    s.erase(u); 
                    if (v<0) update(u, 1);
                } else if (v==0 && a[u]!=0) {
                    s.insert(u);
                    if (a[u]<0) update(u, -1);
                }
                a[u]=v;
            } else {
                if (s.lower_bound(u)!=s.end() && *s.lower_bound(u)<=v) printf("0");
                else {
                    if ((get(v)-get(u-1))%2==1) printf("-");
                    else printf("+");
                }
            }
        }
        printf("\n");
    }

    //getch();
    return 0;
}
