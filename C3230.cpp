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

typedef vector<int> VI ;
typedef vector<string> VS ;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;

template<class T> inline int size(const T&c) { return c.size(); }

using namespace std;
int fastMax(int x, int y) { return (((y-x)>>(32-1))&(x^y))^y; }
int fastMin(int x, int y) { return (((y-x)>>(32-1))&(x^y))^x; }

const int maxn = 500+10;
int a[maxn][3];
bool E[maxn][maxn];
int u[maxn];
int v[maxn];
int numedge,T,n,k,best_cover,cover;
bool valid;

void Steven() {
    int E = numedge;
    int V = n * 3;
//    cout<<V<<' '<<E<<endl;
  int i; k = V / 3 * 2;
  best_cover = -1;
  for (cover = 0; cover < (1<<V); cover++) { // cover is a bitmask that describes the vertex cover, this is O(2^V * E) brute force algorithm
    if (__builtin_popcount(cover) != k) continue; // skip this cover if the size of cover is not k, works with C++11 GNU compilers

    valid = true;
    for (i = 0; i < E && valid; i++)
      if (!((cover & (1<<u[i])) | (cover & (1<<v[i])))) // if neither u[i] or v[i] is on in 'cover', this 'cover' is invalid
        valid = false;

    if (valid)
      best_cover = cover;
  }
  if (best_cover == -1) {
    printf("0\n");
  } else {
    printf("1\n");
  }
}
int main()
{
    freopen("A3230.inp","r",stdin);
    //freopen("A3230.out","w",stdout);
    cin >>T;
    cout<<T<<endl;
    while (T>0){
        cin>>n;
        numedge = 0;
		FOR(i, 0, n-1) FOR(j, 0, 2) scanf("%d", &a[i][j]);
        for (int i = 0; i <= 3*n-1; i++)
        for (int j = 0; j <= 3*n - 1;j++) E[i][j]=true;
        for (int i = 0; i <= n-1; i++)
        for (int j = 0; j <= 2; j++)
        {
            for (int ki = i + 1; ki <= n-1; ki++)
            for (int kj = 0; kj <= 2; kj++)
            {
                if (a[i][j] + a[ki][kj] != 0)
                {
                    E[i*3+j][ki*3+kj] = false;
                }
            }
        }
        for (int i = 0; i <= 3*n-1; i++)
        for (int j = i+1; j<= 3*n - 1;j++)
            if (E[i][j])
                {
                    numedge++;
                    u[numedge - 1] = i;
                    v[numedge - 1] = j;
                }
        T--;
        cout<<n*3<<' '<<numedge<<endl;
        FOR (i,0,numedge-1) cout<<u[i]<<' '<<v[i]<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

