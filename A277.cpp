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
const int maxn = 200+10;
int a[maxn][maxn];
vector<int> c[maxn];
bool b[maxn][maxn];
bool used[maxn];
bool cocanh;
int cnt,n,m;

void DFS(int u)
{
    used[u]=true;
    FOR(i,0,c[u].size()-1)
    {
        if (used[c[u][i]]==false)
            DFS(c[u][i]);
    }
}

int main()
{
    //freopen("A277.inp","r",stdin);
    //freopen("A277.out","w",stdout);
    cin>>n>>m;
    cocanh=false;
    FOR(i,1,n)
    {
        cin>>a[i][0];
        if (a[i][0]!=0) cocanh=true;
        FOR(j,1,a[i][0])
        {
            cin>>a[i][j];
            b[i][a[i][j]]=true;
        }
    }
    FOR(i,1,n)
    FOR(j,i+1,n)
    FOR(k,1,m)
    {
        if (b[i][k]&&b[j][k])
        {
            c[i].push_back(j);
            c[j].push_back(i);
        }
    }
    memset(used,sizeof(used),false);
    FOR(i,1,n)
        if (used[i]==false)
        {
            cnt++;
            DFS(i);
        }
    if (cocanh==false) cout<<n;
    else
        cout<<cnt-1;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

