/*
 * File:   GRAPH_.cpp
 * Author: TMB
 * Problem GRAPH_
 * Created on January 10, 2013, 9:16 AM
 */

#include <cstdio>
#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

#define pb push_back

int n, m, nbridge, ncut;
vector<int> a[10010];
int num[10010], low[10010], nchild[10010], par[10010];
bool root[10010];

/*
 *
 */

void go(const int u, const int pr) {
        low[u] = num[u] = ++m;
        for(int i = 0; i < a[u].size(); i++)
                if (a[u][i] != pr)
                        if (num[a[u][i]]) low[u] = min(low[u], num[a[u][i]]);
                        else {
                                nchild[u]++;
                                par[a[u][i]] = u;
                                go(a[u][i], u);
                                low[u] = min(low[u], low[a[u][i]]);
                        }
}

int main() {
      freopen("B3178.inp", "r", stdin);
        scanf("%d%d", &n, &m);
        for(; m; m--) {
                int u, v;
                scanf("%d%d", &u, &v);
                a[u].pb(v); a[v].pb(u);
        }
        for(int i = 1; i <= n; i++)
                if (!num[i]) root[i] = 1, go(i, -1);

        nbridge = ncut = 0;
        for(int i = 1; i <= n; i++) {
                if (!root[i] && low[i] == num[i]) nbridge++;
                bool ok = 0;
                for(int j = 0; j < a[i].size(); j++)
                        if (par[a[i][j]] == i && low[a[i][j]] >= num[i]) {
                                ok = 1;
                                break;
                        }
                if ((nchild[i] > 1 || !root[i]) && ok) ncut++;
        }
        for(int i = 1; i <= n; i++)  cout<<i<<' '<<num[i]<<' '<<low[i]<<endl;
        printf("%d %d", ncut, nbridge);
        return 0;
}

