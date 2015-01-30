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

string st,st2;
const int maxn = 40+2;
int n,p;
int T;
int res;
int S[maxn][maxn][maxn];

inline int sum(const int z1,const int y1,const  int x1,const  int z2,const  int y2,const  int x2)
{
    //z1--;y1--;x1--;
    return S[z2][y2][x2]
    - S[z2][y2][x1-1] - S[z2][y1-1][x2] - S[z1-1][y2][x2]
    + S[z2][y1-1][x1-1] + S[z1-1][y2][x1-1] + S[z1-1][y1-1][x2]
    - S[z1-1][y1-1][x1-1];
}

bool check(int v)
{
    int t;
    if ((v * v * v * p) % 100 == 0) t = (v * v * v * p) / 100;
    else t = (v * v * v * p) / 100 + 1;
    FOR(i,1,n-v+1)
    FOR(j,1,n-v+1)
    FOR(k,1,n-v+1)
    {
        //cout<<sum(i,j,k,i+v-1,j+v-1,k+v-1)<<' '<<t<<endl;
        if (sum(i,j,k,i+v-1,j+v-1,k+v-1) >= t)
            return true;
    }
    return false;
}

int main()
{
    //freopen("CUBE.inp","r",stdin);
    //freopen("CUBE.out","w",stdout);
    cin>>T;
    FOR(i,1,T)
    {
        scanf("%d%d",&n,&p);
        getline(cin,st);
        getline(cin,st);
        getline(cin,st2);
        int d = 0;
        FOR(i,1,n)
        FOR(j,1,n)
        FOR(k,1,n)
        S[i][j][k] = S[i-1][j][k] + S[i][j-1][k] + S[i][j][k-1]
                   - S[i-1][j-1][k] - S[i-1][j][k-1] - S[i][j-1][k-1]
                   + S[i-1][j-1][k-1] + (st[d] == st2[d++]);
        res = -1;
        DOW(sz,n,1)
        if (check(sz))
        {
            res = sz;
            break;
        }
        int cnt = 0;
            int t; int v = res;
            if ((v * v * v * p) % 100 == 0) t = (v * v * v * p) / 100; else t = (v * v * v * p) / 100 + 1;
        FOR(i,1,n-v+1)
        FOR(j,1,n-v+1)
        FOR(k,1,n-v+1)
        {
            if (sum(i,j,k,i+v-1,j+v-1,k+v-1) >= t) cnt++;
        }
        if (res == -1) cout<<res<<endl; else
        cout<<res<<' '<<cnt<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

