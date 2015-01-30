#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long int64;
#define pb push_back

const int N = 40005;

struct IT {
    int mn, cnt, add;
} T[N*4];

int TT, w, h, p, q, n, x, y, a, b, c, d, u, v, s;
int xx[1000005], yy[1000005];
vector<int> obs[N];

void build(int i, int l, int r) {
    if (l == r) {
        T[i].cnt = 1;
        return;
    }
    int mid = (l + r) >> 1;
    build(i + i, l, mid);
    build(i + i + 1, mid + 1, r);
    T[i].cnt = T[i + i].cnt + T[i + i + 1].cnt;
}

void update(int i, int l, int r) {
    if (r < u || v < l) return;
    if (u <= l && r <= v) {
        T[i].add += s;
        T[i].mn += s;
        return;
    }
    int mid = (l + r) >> 1;
    update(i + i, l, mid);
    update(i + i + 1, mid + 1, r);
    if (T[i + i].mn < T[i + i + 1].mn) {
        T[i].mn = T[i + i].mn;
        T[i].cnt = T[i + i].cnt;
    }
    if (T[i + i].mn > T[i + i + 1].mn) {
        T[i].mn = T[i + i + 1].mn;
        T[i].cnt = T[i + i + 1].cnt;
    }
    if (T[i + i].mn == T[i + i + 1].mn) {
        T[i].mn = T[i + i].mn;
        T[i].cnt = T[i + i].cnt + T[i + i + 1].cnt;
    }
    T[i].mn += T[i].add;
}

int main(){
    freopen("dead_pixels.txt", "r", stdin);
    freopen("45.out", "w", stdout);

    cin >> TT;
    for(int test = 1; test <= TT; test++){
        cin >> w >> h >> p >> q >> n >> x >> y >> a >> b >> c >> d;
        for(int i = 0; i < w; i++) obs[i].clear();
        xx[0] = x; yy[0] = y;
        obs[x].pb(y);
        for(int i = 1; i < n; i++){
            xx[i] = ((int64)xx[i-1]*a + (int64)yy[i-1]*b + 1) % w;
            yy[i] = ((int64)xx[i-1]*c + (int64)yy[i-1]*d + 1) % h;
            obs[xx[i]].pb(yy[i]);
        }
        for(int i = 1; i < N*4; i++) T[i].mn = T[i].cnt = T[i].add = 0;
        build(1, 1, h);
        int res = 0;
        for(int i = 0; i < p-1; i++)
            for(int j = 0; j < obs[i].size(); j++){
                v = obs[i][j]+1;
                u = max(1, v-q+1);
                v = min(v, h);
                s = 1;
                update(1, 1, h);
            }
        for(int i = 0; i < w; i++)
            obs[i].pb(h);
        v = h+1;
        u = max(1, v-q+1);
        s = 1; v = h;
        update(1, 1, h);
        for(int i = p-1; i < w; i++){
            if (i - p >= 0)
                for(int j = 0; j < obs[i-p].size(); j++){
                    v = obs[i-p][j]+1;
                    u = max(1, v-q+1);
                    v = min(v, h);
                    s = -1;
                    update(1, 1, h);
                }
            for(int j = 0; j < obs[i].size(); j++){
                v = obs[i][j]+1;
                u = max(1, v-q+1);
                v = min(v, h);
                s = 1;
                update(1, 1, h);
            }
            //cout << T[1].mn << " " << T[1].cnt << endl;
            //cout<<T[1].cnt<<endl;
            if (T[1].mn == 0)
                res += T[1].cnt;
        }
        printf("Case #%d: %d\n", test, res);
    }

    return 0;
}
