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
#define ll long long
#define SIZE(c) (c).size()

typedef vector<int> VI ;
typedef vector<string> VS ;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;

template<class T> inline int size(const T&c) { return c.size(); }

using namespace std;
int fastMax(int x, int y) { return (((y-x)>>(32-1))&(x^y))^y; }
int fastMin(int x, int y) { return (((y-x)>>(32-1))&(x^y))^x; }

const int maxn = 1058576;
long long F[30][2];
int cur[30];
int a[maxn];
int n,m,q,sn;
int BIT[maxn];
int maxso;
int u;
long long res;

void roirachoa()
{
    vector<int> b(a+1,a+sn+1);
    sort(b.begin(),b.end());
    vector<int>::iterator it = unique(b.begin(),b.end());
    b.resize(distance(b.begin(),it));
    maxso = b.size();
    for (int i = 1; i <= sn; i++)
        a[i] = find(b.begin(),b.end(),a[i]) - b.begin() + 1;
}

pair<ll,ll> sum[30];
vector<int> seg[30];

inline void Merge(vector<int> &a, vector<int> &b, vector<int> &c) {
    for(int i = 0, j = 0, k = 0; i < a.size() || j < b.size(); )
    if (i < a.size() && (j == b.size() || a[i] < b[j])) c[k++] = a[i++];
    else c[k++] = b[j++];
}

void init(int u, int i, int l, int r) {
    seg[i].resize(r-l+1);
    if (l == r) {
    seg[i][0] = a[l];
      return;
     }
     int mid = (l+r)/2;
     init(u-1, i*2, l, mid);
     init(u-1, i*2+1, mid+1, r);

     pair<ll, ll> it = make_pair(0, 0);
     for(int j = 0; j < seg[i*2].size(); j++)
        it.first += lower_bound(seg[i*2+1].begin(), seg[i*2+1].end(), seg[i*2][j]) - seg[i*2+1].begin();
     for(int j = 0; j < seg[i*2+1].size(); j++)
        it.second += lower_bound(seg[i*2].begin(), seg[i*2].end(), seg[i*2+1][j]) - seg[i*2].begin();


     sum[u].first += it.first;
     sum[u].second += it.second;

     Merge(seg[i*2], seg[i*2+1], seg[i]);
}

int main()
{
    //freopen("C414.inp","r",stdin);
    //freopen("C414.out","w",stdout);
    scanf("%d",&n);
    sn = (1 << n);
    for (int i = 1; i <= sn; i ++) scanf("%d",&a[i]);
    roirachoa();
    memset(BIT,0,sizeof(BIT));
    init(n,1,1,sn);
    FOR(i,1,n)
    {
        F[i][0] = sum[i].first;
        F[i][1] = sum[i].second;
    }
    scanf("%d",&q);
    for (int i = 1; i <= q; i++)
    {
        scanf("%d",&u);
        for(int i = u; i >= 1; i--) cur[i] = 1-cur[i];
        res = 0;
        for(int i = 1; i <= n; i++)
            res = res + F[i][cur[i]];
        //cout<<res<<endl;
        printf("%I64d\n",res);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}


