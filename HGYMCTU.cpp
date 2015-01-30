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

string st;
const int maxn = 100+10;
unsigned long long a[maxn];
unsigned long long Fmin[maxn][maxn];
unsigned long long Fmax[maxn][maxn];
int dau[maxn];
int cnt,n;

unsigned long long calc(unsigned long long a, unsigned long long b, int dau)
{
    if (dau == 1) return a + b;
    else return a * b;
}

int main()
{
    //freopen("HGYMCTU.inp","r",stdin);
    //freopen("","w",stdout);
    while(getline(cin,st))
    {
        if (st == "END") break;
        string temp = "";
        cnt = 0;
        for (int i = 0; i < st.length(); i++)
        {
            if (st[i] == '+' || st[i] == '*')
            {
                cnt++;
                if (st[i] == '+')
                    dau[cnt] = 1;
                else
                    dau[cnt] = 2;
                a[cnt] = atoi(temp.c_str());
                temp = "";
            }
            else
                temp += st[i];
        }
        cnt++;
        a[cnt] = atoi(temp.c_str());
        n = cnt;

        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                {
                    Fmin[i][j] = 9223372036854775807;
                    Fmax[i][j] = 0;
                }
        for (int i = 1; i <= n; i++)
            {
                Fmin[i][i] = a[i];
                Fmax[i][i] = a[i];
            }
        for (int i = n; i >= 1; i--)
            for (int j = i + 1; j <= n; j++)
        {
            for (int k = i; k < j; k++)
            {
                Fmin[i][j] = min(Fmin[i][j], calc(Fmin[i][k],Fmin[k+1][j],dau[k]));
                Fmax[i][j] = max(Fmax[i][j], calc(Fmax[i][k],Fmax[k+1][j],dau[k]));
            }
        }
        cout<<Fmin[1][n]<<' '<<Fmax[1][n]<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

