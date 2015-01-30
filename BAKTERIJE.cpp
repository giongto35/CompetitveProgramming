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
using namespace std ;

#define FOREACH(it,c) for( __typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define FOR(i,a,b) for( int i=(a),_b=(b);i<=_b;i++)
#define DOW(i,b,a) for( int i=(b),_a=(a);i>=_a;i--)
#define REP(i,n) FOR(i,0,(n)-1)
#define DEP(i,n) DOW(i,(n)-1,0)
#define all(a) (a).begin() , (a).end()
#define push(a,b) (a).push_back((b))

typedef vector<int> VI ;
typedef vector<string> VS ;
template<class T> inline int size(const T&c) { return c.size(); }

using namespace std;
int n,m,k,X,Y;
string d;
const int maxn=50+10;
int a[maxn][maxn];
int TY,TX;
int d[maxn][maxn][4];
struct location
{
    int y;
    int x;
    int d;
} q[maxn*maxn*4];
int fr,re;

void BFS(int Y,int X,int D)
{
    fr=0;
    re=1;
    q[re]=makeloc(Y,X,D);

}

int main()
{
    freopen("BAKTERIJE.inp","r",stdin);
    freopen("BAKTERIJE.out","w",stdout);
    cin>>n>>m>>k;
    cin>>TY>>TX;
    FOR(i,1,k)
    {
        cin>>Y>>X>>d;
        FOR(j,1,n)

        {
            getline(cin,st);
            FOR(k,1,m)
                a[j][k]=st[k-1];
        }
        BFS(Y,X,D);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

