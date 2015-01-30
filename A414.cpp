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

int n,k;
vector<int> res;
map<int,bool> m;
int main()
{
    //freopen("A414.inp","r",stdin);
    //freopen("A414.out","w",stdout);
    scanf("%d%d",&n,&k);
    if (n==1)
    {
        if (k == 0)
            cout<<"1";
        else
            cout<<"-1";
        return 0;
    }
    int spair = n / 2 - 1;
    m.clear();
    if (k <= spair)
    {
        cout<<-1;
        return 0;
    }
    else
    {
        res.push_back(k - spair);
        res.push_back((k - spair)*2);
        m[k-spair] = true;
        m[(k-spair)*2] = true;
    }
    for (int i = 1; i <= spair; i++)
    {
        while(true){
            int u = ((long long)rand()*rand()) % 1000000000 + 1;
            if (m[u] == false && m[u+1] ==false)
            {
                res.push_back(u);
                res.push_back(u+1);
                m[u] = true;
                m[u+1] = true;
                break;
            }
        }
    }
    if (n % 2 == 1)
    {
        while(true){
            int u = ((long long)rand()*rand()) % 1000000000 + 1;
            if (m[u] == false)
            {
                res.push_back(u);
                m[u] = true;
                break;
            }
        }
    }
    FOREACH(it,res)
        printf("%d ",*it);
    fclose(stdin);
    fclose(stdout);
    return 0;
}

