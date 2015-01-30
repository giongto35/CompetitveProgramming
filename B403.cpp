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

const int maxn = 5000;
int n,m;
int gtmax;
int a[maxn],b[maxn];
map<int,bool> bad;
map<int,int> F[maxn];
int vt;
bool prime [ 100000];
int p[100000];
int sp;
vector<pair<int,int> > gcd,gmin;
vector<pair<int,int> > f[maxn];

void rec(int i,int j)
{
//  cout<<i<<' '<<j<<' '<<F[i][j]<<endl;
    int c = F[i][j];
    if (j <= 1000000000 / b[i])
        {
            //cout<<"TINH "<<c+1<<' '<<i<<' '<<j*a[i]<<endl;
            F[i][j * b[i]] = c + 1;
            rec(i, j * b[i]);
        }
    if (i < m)
        {
            F[i+1][j] = c;
            rec(i + 1, j);
        }
}

void sieve(int n)
{
    int i = 2;
    while (i * i <= n)
    {
        int j = i * i;
        while (j  <= n)
        {
            prime[j] = true;
            j += i;
        }
        i += 1;
    }
    for (int i = 2; i <= n; i++)
    if (prime[i] == false)
        p[++sp] = i;
}

int calc(vector<pair<int,int>> t)
{
    int res = 0;
    FOREACH(it,t)
        res += (*it).second;
    return res;
}

int main()
{
    freopen("B403.inp","r",stdin);
    //freopen("B403.out","w",stdout);
    scanf("%d%d",&n,&m);
    for (int i = 1; i <= n; i++) scanf("%d",&a[i]);
    for (int i = 1; i <= m; i++) scanf("%d",&b[i]),bad[b[i]] = true;
    //sieve(sqrt(1000000000));
    for (int i = 1; i <= n; i++)
    {
        int v = a[i];
        for (int j = 2; j * j <= a[i]; j++)
        {
            if (a[i] % j == 0)
            {
                pair<int,int> tf;
                tf.first = j;
                while (v % j == 0)
                {
                    tf.second ++;
                    v /= j;
                }
                f[i].push_back(tf);
                if (bad[f[i].first]) f[i].second = -f[i].second;
            }
        }
        if (v  > 1)
            f[i].push_back(make_pair(v,1));
        f[i].sort(f[i].begin(),f[i].end());
    }
    while (true)
    {
        gcd = f[1];
        int gtmin = calc();
        for (int i = 2; i <= n; i++)
        {
            FOREACH(it,gcd)
            {
                vector<pair<int,int>>::iterator pr = find(f[i].begin(), f[i].end(), (*it).first);
                if (pr != f[i].end())
                {
                    if ((*it).second < 0) (*it).second ++;
                    else (*it).second --;
                }
            }
            int temp = calc();
            if (gtmin < temp)
            {
                gtmin = temp;
                gmin = gcd[i];
                vt = i;
            }
        }

        for (int i = 1; i <= vt; i++)
        {
            FOREACH(it,gmin)
            {
                vector<pair<int,int>>::iterator pr = find(f[i].begin(), f[i].end(), (*it).first);
                if (pr != f[i].end())
                    (*pr).second -= (*it).second;
            }
        }
    }
    int res =0 ;
    for (int i  =1 ; i <= n; i++)
        res += calc(f[i]);
    cout<<res<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

