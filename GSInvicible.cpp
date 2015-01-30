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
#include <cstring>
#include <ctime>
#include <queue>
#define FOR(i,a,b) for(long i=a; i<=b; i++)
#define FORD(i,a,b) for(long i=a; i>=b; i--)
#define SWAP(a,b) {typeof(a) tmp=a; a=b; b=tmp;}
#define MAXN 20
using namespace std;

long start,target,n,ke[MAXN][MAXN],xs[MAXN][MAXN];
double x[MAXN],a[MAXN][MAXN],b[MAXN],sum[MAXN];

void inp() {
    memset(ke,0,sizeof ke);
    memset(sum,0,sizeof sum);
    memset(xs,0,sizeof xs);
    memset(b,0,sizeof b);
    memset(a,0,sizeof a);

    scanf("%ld %ld %ld",&n,&start,&target);
    FOR(i,1,n-1) {
        long u,v;
        scanf("%ld %ld",&u,&v);
        scanf("%ld",&xs[u][v]);
        xs[v][u]=xs[u][v];
        ke[u][v]=ke[v][u]=1;
    }
}

void init() {
    FOR(i,1,n) {
        sum[i]=0;
        FOR(j,1,n)
            sum[i]+=xs[i][j];
    }

    FOR(i,1,n) {
        a[i][i]=1;
        if (i==target) b[i]=0;
        else {
            b[i]=1;
            FOR(j,1,n)
            if (j!=i)
                a[i][j]=-xs[i][j]/sum[i];
        }
    }
}

void solve() {
    FOR(j,1,n-1) {
        long u=0;
        FOR(i,j,n)
            if (abs(a[i][j])>abs(a[u][j])) u=i;
        if (!u) continue;

        SWAP(b[j],b[u]);
        FOR(k,1,n)
            SWAP(a[j][k],a[u][k]);

        FOR(i,j+1,n) {
            b[i]-=b[j]*a[i][j]/a[j][j];
            FORD(k,n,j)
                a[i][k]-=a[j][k]*a[i][j]/a[j][j];
        }
    }

    FORD(i,n,1) {
        double sum=0;
        FOR(j,i+1,n) sum+=a[i][j]*x[j];
        if (!a[i][i]) x[i]=0; else x[i]=(b[i]-sum)/a[i][i];
    }
    printf("%.5lf\n",x[start]);
}

int main() {
    long _; scanf("%ld",&_);
    while (_--) {
        inp();
        init();
        solve();
    }
    return 0;
}
