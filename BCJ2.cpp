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

const int maxn = 1000+10;
const int oo = 1000000000;
int a[maxn];
vector<int> b;
int F[maxn][maxn];
int T,sT,n;
map<int,int> ma;
bool used[maxn];
int pre[maxn][maxn];

void roirac(){
    sort(b.begin(),b.end());
    ma.clear();
    for (int i = 0; i < b.size(); i++) ma[b[i]] = i+1;
    for (int i = 1; i <= n; i++)
        a[i] = ma[a[i]];
}

void preprocessing()
{
    memset(used,false,sizeof(used));
    for (int i = 0; i <= n; i++)
    {
        int sum= 0 ;
        for (int j = 1; j <= n; j++)
        {
            sum += (used[a[j]] == false);
            pre[i][a[j]] = sum;
        }
        used[i+1] = true;
    }
}

int main()
{
    freopen("B-large.in","r",stdin);
    freopen("BCJ2.out","w",stdout);
    scanf("%d",&T);

    for (int sT = 1; sT <= T; sT++)
    {
        scanf("%d",&n);
        b.clear();
        for (int i = 1; i <= n; i++) scanf("%d",&a[i]),b.push_back(a[i]);
        roirac();

        preprocessing();
        for (int i = 0; i <= n + 1; i ++)
        for (int j = 0; j <= n + 1; j ++)
        F[i][j] = oo;
        F[0][0] = 0;
        for (int i = 0; i <= n ; i ++)
        for (int j = 0; j <= n - i; j ++)
        {
            if (i == 0 && j == 0) continue;
            int cnt = i + j;
            if (i > 0)
            F[i][j] = min(F[i][j],F[i-1][j] + pre[cnt-1][cnt] - 1);
            if (j > 0)
            F[i][j] = min(F[i][j], F[i][j-1] + ((n - (cnt-1)) - pre[cnt-1][cnt]));
        }
        int res = oo;
        for (int i = 0; i <= n; i++)
            res = min(res,F[i][n-i]);
        cout<<"Case #"<<sT<<": "<<res<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

