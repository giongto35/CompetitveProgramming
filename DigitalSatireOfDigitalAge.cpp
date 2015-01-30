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

const int n = 7;
const int m = 18;
int T;
char a[10][20];
char res[10][20];
string st;
int l;
int r;
int vt1,vt2;
int b,b2;

void movec(int tu,int td,int u,int d,int l)
{
    int j = u;
    FOR(i,tu,td)
    {
        FOR(k,l,l+7)
        res[i][k] = a[j][k];
        j++;
    }
}

int weight(char c)
{
    int res = 0 ;
    while (c > 0)
    {
        if (c % 2 == 1) res += 500; else res += 250;
        c /= 2;
    }
    return res;
}

int main()
{
    //freopen("Balance.inp","r",stdin);
    //freopen("Balance.out","w",stdout);
    cin>>T;
    FOR(z,1,T)
    {
        printf("Case %d:\n",z);
        getline(cin,st);
        FOR(i,1,n)
        {
            getline(cin,st);
            FOR(j,1,m) a[i][j] = st[j-1];
        }
        l = 0;
        r = 0;
        FOR(i,1,n)
        FOR(j,1,8)
        {
            if (isalpha(a[i][j])) l+=weight(a[i][j]);
            if (a[i][j] == '_') vt1 = i;
        }
        FOR(i,1,n)
        FOR(j,10,17)
        {
            if (isalpha(a[i][j])) r+=weight(a[i][j]);
            if (a[i][j] == '_') vt2 = i;
        }
        if (l<r) b = 1;
        else
            if (l == r) b = 2; else b = 3;
        if (vt1<vt2) b2 = 1;
        else
            if (vt1 == vt2) b2 = 2; else b2 = 3;
        FOR(i,1,n) FOR(j,1,m) res[i][j] = '.';
        FOR(i,1,n) res[i][9] = '|',res[i][10] = '|';
        if (b == b2) printf("The figure is correct.\n");
        else
        {
            if (b == 1)
            {
                movec(1,5,vt1-4,vt1,1);
                movec(3,7,vt2-4,vt2,11);
            }
            else
            if (b == 2)
            {
                movec(2,6,vt1-4,vt1,1);
                movec(2,6,vt2-4,vt2,11);
            }
            else
            if (b == 3)
            {
                movec(3,7,vt1-4,vt1,1);
                movec(1,5,vt2-4,vt2,11);
            }
            FOR(i,1,n)
            {
                FOR(j,1,m) printf("%c",res[i][j]);
                printf("\n");
            }
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
