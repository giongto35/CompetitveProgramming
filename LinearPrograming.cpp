// m - number of (less than) inequalities, n - number of variables
// C - (m+1) by (n+1) array of coefficients:
// row 0 - objective function coefficients
// row 1:m - less-than inequalities
// column 0:n-1 - inequality coefficients
// column n - inequality constants (0 for objective function)
// X[n] - result variables
// return value - maximum value of objective function
// (-inf for infeasible, inf for unbounded)

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
#include <iomanip>

using namespace std ;

#define FOREACH(it,c) for( __typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define FOR(i,a,b) for( int i=(a),_b=(b);i<=_b;i++)
#define DOW(i,b,a) for( int i=(b),_a=(a);i>=_a;i--)
#define REP(i,n) FOR(i,0,(n)-1)
#define DEP(i,n) DOW(i,(n)-1,0)
#define all(a) (a).begin() , (a).end()
#define mp(a,b) make_pair((a),(b))
#define RESET(c,x) memset (c, x, sizeof (c))
#define oo 1000111000
#define PI acos(-1.0)
#define fi first
#define se second
#define SIZE(c) (c).size()
#define MAXM 400 // leave one extra
#define MAXN 400 // leave one extra
#define EPS 1e-9
#define INF 1.0/0.0
double A[MAXM][MAXN],C[MAXM][MAXN];
double X[MAXN];
int basis[MAXM], out[MAXN], T, m, n;
void pivot(int m, int n, int a, int b) {
   int i,j;
   for (i=0;i<=m;i++)
      if (i!=a)
         for (j=0;j<=n;j++)
            if (j!=b)
               A[i][j] -= A[a][j] * A[i][b] / A[a][b];
   for (j=0;j<=n;j++)
      if (j!=b) A[a][j] /= A[a][b];
   for (i=0;i<=m;i++)
      if (i!=a) A[i][b] = -A[i][b]/A[a][b];
         A[a][b] = 1/A[a][b];
   swap(basis[a], out[b]);
}
double simplex(int m, int n, double C[][MAXN], double X[]) {
   int i,j,ii,jj; // i,ii are row indexes; j,jj are column indexes
   for (i=1;i<=m;i++)
      for (j=0;j<=n;j++)
         A[i][j] = C[i][j];
   for (j=0;j<=n;j++) A[0][j] = -C[0][j];
   for (i=0;i<=m;i++) basis[i] = -i;
   for (j=0;j<=n;j++) out[j] = j;
   for(;;) {
      for (i=ii=1;i<=m;i++)
         if (A[i][n]<A[ii][n] || (A[i][n]==A[ii][n] && basis[i]<basis[ii]))
            ii=i;
      if (A[ii][n] >= -EPS) break;
      for (j=jj=0;j<n;j++)
         if (A[ii][j]<A[ii][jj]-EPS || (A[ii][j]<A[ii][jj]-EPS && out[i]<out[j]))
            jj=j;
      if (A[ii][jj] >= -EPS) return -INF;
      pivot(m,n,ii,jj);
   }
   for(;;) {
      for (j=jj=0;j<n;j++)
         if (A[0][j]<A[0][jj] || (A[0][j]==A[0][jj] && out[j]<out[jj]))
            jj=j;
      if (A[0][jj] > -EPS) break;
      for (i=1,ii=0;i<=m;i++)
         if ((A[i][jj]>EPS) &&
               (!ii || (A[i][n]/A[i][jj] < A[ii][n]/A[ii][jj]-EPS) ||
            ((A[i][n]/A[i][jj] < A[ii][n]/A[ii][jj]+EPS) && (basis[i] < basis[ii]))))
         ii=i;
      if (A[ii][jj] <= EPS) return INF;
      pivot(m,n,ii,jj);
   }
   for (j=0;j<n;j++)
      X[j] = 0;
   for (i=1;i<=m;i++)
      if (basis[i] >= 0)
         X[basis[i]] = A[i][n];
   return A[0][n];
}

int main()
{/*
    C[0][0] = 60; C[0][1] = 30; C[0][2] = 20; C[0][3] = 0; C[0][4] = 0; C[0][5] = 0; C[0][6] = 0;
    C[1][0] = 8;  C[1][1] =  6; C[1][2] =  1; C[1][3] = 1; C[1][4] = 0; C[1][5] = 0; C[1][6] = 0; C[1][7] = 48;
    C[2][0] = 2;  C[2][1] =1.5; C[2][2] =0.5; C[2][3] = 0; C[2][4] = 1; C[2][5] = 0; C[2][6] = 0; C[2][7] = 8;
    C[3][0] = 4;  C[3][1] =  2; C[3][2] =1.5; C[3][3] = 0; C[3][4] = 0; C[3][5] = 1; C[3][6] = 0; C[3][7] = 20;
    C[4][0] = 0;  C[4][1] =  2; C[4][2] =  0; C[4][3] = 0; C[4][4] = 0; C[4][5] = 0; C[4][6] = 1; C[4][7] = 5;*/
    freopen("LPTEST.in","r",stdin);
    freopen("LPTEST.out","w",stdout);
    scanf("%d",&T);
    while (T>0)
    {
        memset(C,0,sizeof(C));
        scanf("%d %d",&m,&n);
        for (int j = 0; j < n; j++)
            scanf("%lf",&C[0][j]);
        for (int i = 1; i <= m; i++)
        {
            for (int j = 0; j < n; j++)
            scanf("%lf",&C[i][j]);
            scanf("%lf",&C[i][m+n]);
        }
        for (int i = 1; i <= m; i++) C[i][i+n-1] = 1;

        printf("%\lf\n",simplex(m,n+m,C,X));
        for (int i = 0; i <= n-1; i++)
        printf("%.6lf ",X[i]);
        printf("\n");
        T--;
    }
}
