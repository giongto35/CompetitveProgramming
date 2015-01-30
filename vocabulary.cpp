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
vector<int> a[maxn];
bool mark[maxn];
int mX[maxn],mY[maxn],rX[maxn],rY[maxn];
int cnt[maxn][30];
int cnt2[maxn][30];
int n,res,m;
int find(int x)
{
    if (x == 0) return 1;
    if (mark[x]) return 0;
    mark[x] = 1;
    FOREACH(it,a[x])
    {
        int y = (*it);
        if (find(mY[y]))
        {
            mX[x] = y; mY[y] = x;
            return 1;
        }
    }
    return 0;
}

int matching()
{
    memset(mX,0,sizeof(mX));
    memset(mY,0,sizeof(mY));
    res = 0;
    for(int i = 1; i <= n; i++)
    if (mX[i] == 0) {
        memset(mark, 0, sizeof mark);
        res += find(i);
    }
    return res;
}

string st;

bool check(int u, int v)
{
    for (int i = 0; i <= 'z' - 'a'; i++)
        if (cnt[u][i] < cnt2[v][i]) return false;
    return true;
}

int main()
{
    //freopen("vocabulary.inp","r",stdin);
    //freopen("vocabulary.out","w",stdout);
    while (scanf("%d%d",&n,&m) == 2){
        getline(cin,st);
        memset(cnt,0,sizeof(cnt));
        memset(cnt2,0,sizeof(cnt2));
        for (int i = 1 ; i <=  n; i++)
            {
                getline(cin,st);
                for (int j = 0; j < (int)st.length(); j++)
                    cnt[i][st[j] - 'a'] ++;
            }
        for (int i = 1 ; i <= m; i++)
            {
                getline(cin,st);
                for (int j = 0 ; j < (int)st.length(); j++)
                    cnt2[i][st[j] - 'a']++;
            }
        for (int i = 1; i <= n; i++)
        {
            a[i].clear();
            for (int j = 1 ; j <= m; j++)
                if (check(i,j))
                    a[i].push_back(j);
        }
        cout<<matching()<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

