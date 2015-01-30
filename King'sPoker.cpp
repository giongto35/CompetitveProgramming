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

const int maxn = 5;
int a[3],b[3];
int res[3];

int check(int a[],int &c)
{
    sort(a,a+3);
    int res = 1 ;
    FOR(i,1,2) res +=(a[i] == a[i-1]);
    if (a[0] != a[1]) c = a[0];
    if (a[2] != a[1]) c = a[2];
    return res;
}

bool compare(int a[], int b[])
{
    int c1;
    int c2;
    int t1 = check(a,c1);
    int t2 = check(b,c2);
    if (t1 > t2) return true; else
        if (t1 < t2) return false; else
    {
        if (t1 == 3) return a[0] > b[0]; else
        if (t1 == 2) {
            if (a[1] == b[1]) return c1 > c2;
            else return a[1] > b[1];
        } else return false;
    }
}

int main()
{
    //freopen("KingPoker.inp","r",stdin);
    //freopen("KingPoker.out","w",stdout);
    while (true)
    {
        scanf("%d%d%d",&a[0],&a[1],&a[2]);
        if (a[0] == 0 && a[1] == 0 && a[2] == 0) break;

        res[0] = 13;
        res[1] = 13;
        res[2] = 13;
        FOR(i,1,13)
        FOR(j,1,13)
        FOR(k,1,13)
        {
            b[0] = i; b[1] = j; b[2] = k;
            if (compare(b,a))
            {
                if (compare(res,b)) FOR(l,0,2) res[l] = b[l];
            }
        }
        if (compare(res,a) == false) cout<<'*'<<endl;else
        {FOR(i,0,1) cout<<res[i]<<' ';cout<<res[2]<<endl;}
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

