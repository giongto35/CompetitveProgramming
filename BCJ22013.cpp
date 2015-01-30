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

int n,T;
long long p;
long long res1,res2;
int main()
{
    freopen("B-large-practice.in","r",stdin);
    freopen("BCJ22013.out","w",stdout);
    scanf("%d",&T);
    for (int sT = 1; sT <= T; sT++)
    {
        cin>>n>>p;
        int cnt = (int)log2(p);
        res2 = 0;
        for (int j = n - 1; j >= n - cnt ; j--)
        res2 += (1ll << j);
        if (p == (1ll <<n))
            res1 = (1ll <<n) - 1;
        else
        {
            p = (1ll << n) - p  + 1;
            cnt = (int)log2(p - 1) + 1;
            res1 = (1ll << (n + 1 - cnt)) - 2;
        }
        cout<<"case #"<<sT<<": "<<res1<<' '<<res2<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

