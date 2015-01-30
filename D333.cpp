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
const int maxn = 1000+10;
int a[maxn][maxn],b[maxn][maxn],spt;
vector <int> r[maxn];
int ok[maxn][maxn];
int res,n,m,le,ri;
bool check (int val)
{
    FOR(i,1,n) r[i].clear();
    FOR(i,1,n)
    FOR(j,1,m)
    if (a[i][j]>=val) r[i].push_back(j);
    FOR(i,1,n)
    {
        FOR(j,0,r[i].size()-1)
        FOR(k,j+1,r[i].size()-1)
        {
            if (ok[r[i][j]][r[i][k]]==val) return true;
            else
            ok[r[i][j]][r[i][k]]=val;
        }
    }
    return false;
}

int main()
{
    //freopen("D333.inp","r",stdin);
    //freopen("D333.out","w",stdout);
    cin>>n>>m;
    FOR(i,1,n)
    FOR(j,1,m)
    {
        scanf("%d",&a[i][j]);
    }
    le=0;
    ri=1000000000;
    while (le<=ri)
    {
        int mid = (le+ri) / 2;
        if (check(mid))
        {
            res= mid;
            le=mid+1;
        }
        else ri=mid-1;
    }
    cout<<res<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

