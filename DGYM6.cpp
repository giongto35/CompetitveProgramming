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

const int maxn = 10000;

int cnt[20];
long long F[100][10];
int T,n,m,q,l;
string st;
int main()
{
    //freopen("DGYM6.inp","r",stdin);
    //freopen("","w",stdout);
    scanf("%d",&T);
    while (T--){

        scanf("%d%d%d",&m,&n,&q);
            getline(cin,st);
        memset(cnt,0,sizeof(cnt));
        for (int i = 1; i <= m; i++)
        {
            getline(cin,st);
            cnt[st.length()]++;
        }

        while(q--)
        {
            scanf("%d",&l);
            memset(F,0,sizeof(F));
            F[0][0] = 1;
            for (int i = 1; i <=l; i++)
            {
                for (int j = 1; j <= n; j++)
                {
                    for (int k = 1; k <= min(10,i); k++)
                    {
                        F[i][j] = F[i][j] + F[i - k][j - 1] * cnt[k];
                    }

                }
            }
            cout<<F[l][n]<<endl;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

