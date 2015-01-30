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

const int maxn = 1000+10;
int a[maxn];
int b[maxn];
int res[maxn];
bool used[maxn];
bool ok;
int n;
int T;

void rec(int vt)
{
    if (vt == n + 1)
    {
        //for (int i = 1; i <= n; i++) cout<<res[i]<<' '; cout<<endl;
        ok = true;
        for (int i = n; i >= 1; i--)
        {
            int gt = 1;
            for (int j = i + 1; j <= n; j++)
                if (res[j] < res[i]) gt = max(gt,b[j] + 1);
            if (gt != b[i])
            {
                ok = false;
                break;
            }
        }
        if (ok) return;
    }
    for (int i = 1; i <= n; i++)
    {
        if (used[i]==false){
            used[i] = true;
            res[vt] = i;
            int gt = 1;
            for (int j = 1; j < vt; j++)
                if (res[vt] > res[j]) gt = max(gt,a[j] + 1);
            bool dc = true;
            for (int j = 1; j < vt; j++)
            {
                if (res[vt] < res[j] && b[vt] >= b[j]) dc = false;
                if (res[vt] == res[j] && b[vt] > b[j]) dc = false;
            }
            /*if (res[1] == 4 && res[2] == 5 && vt == 7)
            {
                for (int i = 1; i <= n; i++) cout<<res[i]<<' '; cout<<endl;
                cout<<gt<<endl;
            }*/
            if (a[vt] == gt && dc) rec(vt+1);
            if (ok) return ;
            used[i] = false;
        }
    }
}

int main()
{
    freopen("CCJ2013.inp","r",stdin);
    //freopen("CCJ2013.out","w",stdout);
    scanf("%d",&T);
    for (int sT = 1; sT <= T; sT++)
    {
        memset(used,false,sizeof(used));
        scanf("%d",&n);
        for (int i = 1; i <= n; i++)
            scanf("%d",&a[i]);
        for (int i = 1; i <= n; i++)
            scanf("%d",&b[i]);
        ok = false;
        rec(1);
        cout<<"Case #"<<sT<<": ";
        for (int i = 1; i <= n; i++)
            cout<<res[i]<<' ';
        cout<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

