#include "iostream"
#include "cstdio"
#include "cstdlib"
#include "cstring"
#include "algorithm"
using namespace std;

typedef pair<int,int> pii;
#define fi first
#define se second

const int N = 1000001;

int T, m, n, t, sign, spt;
int p[N], a[N], cnt[N];
long long res;
pii b[700000];

void Sieve(){
    for(int i = 1; i < N; i++) a[i] = 1;
    for(int i = 2; i < N; i++)
        if (!p[i]){
            p[i] = a[i] = i;
            cnt[i] = 1;
            for(int j = i+i; j < N; j+=i){
                p[j] = i;
                a[j] *= i;
                cnt[j]++;
            }
        }
    for(int i = 2; i < N; i++)
        if (i == a[i]){
            ++spt;
            b[spt].fi = i;
            b[spt].se = (cnt[i] % 2 == 1) ? 1 : -1;
        }
}

int main(){
    freopen("raygun.inp", "r", stdin);
    freopen("RAYGUN.out", "w", stdout);

    Sieve();
    cin >> T;
    for(int test = 1; test <= T; test++){
        printf("Case %d: ", test);
        scanf("%d %d", &m, &n);
        if (m == 0 || n == 0){
            printf("%d\n", (m^n) != 0);
            continue;
        }
        res = 0;
        for(int i = 1; i <= spt; i++)
            res += (long long)b[i].se * (m/b[i].fi) * (n/b[i].fi);
        res = (long long)m*n - res + 2;
        printf("%lld\n", res);
    }
    return 0;
}









