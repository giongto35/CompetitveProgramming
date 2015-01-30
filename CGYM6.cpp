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

const double eps = 0.000001;
double X;
int x;
bool F[100000];
int a[2000];
int u,T,n;

int main()
{
    //freopen("CGYM6.inp","r",stdin);
    //freopen("CGYM6.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin>>T;
    while (T--)
    {
        cin>>X;
        memset(F,false,sizeof(F));
        cin>>n;
        for (int j = 1; j <= n; j++)
        {
            cin>>a[j];
            while (a[j]  % 2 == 0) a[j] /= 2;
        }

        X = X * 8;
        if (abs(X-int(X+0.5)) > eps)
            {
                cout<<"no"<<endl;
                continue;
            }
        x = int(X + 0.5);

        F[0] = true;
        for (int i = 0; i <= x; i++)
        {
            if (F[i])
            {
                //cout<<F[i]<<' ';
                for (int j = 1; j <= n; j++)
                {
                    //cout<<i<<' '<<a[j]<<endl;
                    if (i + a[j] <= x)
                    F[i + a[j]] = true;
                }
            }
        }
        if (F[x]) cout<<"yes"<<endl;
        else cout<<"no"<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

