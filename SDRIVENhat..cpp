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
#include <ctime>
#include <queue>
using namespace std ;

#define FOREACH(it,c) for( __typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define FOR(i,a,b) for( int i=(a),_b=(b);i<=_b;i++)
#define DOW(i,b,a) for( int i=(b),_a=(a);i>=_a;i--)
#define REP(i,n) FOR(i,0,(n)-1)
#define DEP(i,n) DOW(i,(n)-1,0)
#define all(a) (a).begin() , (a).end()

typedef vector<int> VI ;
typedef vector<string> VS ;
template<class T> inline int size(const T&c) { return c.size(); }

const int N = 10005;
const double pi = acos(-1.0);

int n, m;
int L[N], S[N];
double dp[N*21];
double res;

void write(double x){
    printf("%.5lf\n", x);
}

int main(){
    //freopen("SDRIVE.inp", "r", stdin);
    //freopen("SDRIVE.out", "w", stdout);

    cin >> n >> m;
    for(int i = 1; i <= n; i++) scanf("%d", &L[i]);
    for(int i = 1; i <= n; i++) scanf("%d", &S[i]);

    for(int i = m+1; i <= m*(n+1); i++) dp[i] = 1e12;
    for(int i = 1; i <= n; i++)
        if (L[i] == 0){
            for(int j = 1; j <= m; j++)
                for(int k = 1; k <= m; k++)
                    if (S[i]/100 - abs(j-k) >= 0){
                        double t = fabs(j - k + 0.0);
                        t = sqrt(100*t*t + S[i]*S[i]);
                        dp[i*m+j] = min(dp[i*m+j], dp[(i-1)*m+k] + t);
                    }
        }
        else{
            double R = S[i] + 5.0;
            if (L[i] ==  2)
                for(int j = 1; j <= m; j++){
                    dp[i*m+j] = min(dp[i*m+j], dp[(i-1)*m+j] + pi*R / 2);
                    R += 10.0;
                }
            else
                for(int j = m; j >= 1; j--){
                    dp[i*m+j] = min(dp[i*m+j], dp[(i-1)*m+j] + pi*R / 2);
                    R += 10.0;
                }
        }
    res = 1e12;
    for(int i = n*m+1; i <= (n+1)*m; i++) res = min(res, dp[i]);

    printf("%.2lf\n", res);

    return 0;
}
