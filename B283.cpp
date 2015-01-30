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
const int maxn=2*100000+10;
int a[maxn];
int used[maxn][2];
long long sum[maxn][2];
int n;
bool ok;

void DFS(int i,int j)
{
    used[i][j]=1;
    int ni,nj;
    if (j==0) ni=i+a[i]; else ni=i-a[i];
    nj=1-j;
    //if (i==6&&j==0) cout<<i<<' '<<a[i]<<' '<<j<<' '<<ni<<' '<<nj<<' '<<sum[ni][nj]<<endl;

    if (ni<=0||ni>n) {sum[i][j]=a[i];used[i][j]=2;return;}
    if (ni==1) {sum[i][j]=-1;used[i][j]=2;return;}
    if (used[ni][nj]==1) {sum[i][j]=-1;used[i][j]=2;return;}
//    if (i==6&&j==0) cout<<i<<' '<<a[i]<<' '<<j<<' '<<ni<<' '<<nj<<' '<<sum[ni][nj]<<endl;
    if (used[ni][nj]==0) DFS(ni,nj);
    if (sum[ni][nj]==-1) sum[i][j]=-1;else
    sum[i][j]=a[i]+sum[ni][nj];
    used[i][j]=2;
}

int main()
{
    //freopen("B283.in","r",stdin);
    //freopen("B283.out","w",stdout);
    cin>>n;
    FOR(i,2,n) cin>>a[i];
    FOR(i,2,n)
    FOR(j,0,1)
    {
        if (i==9&&j==1) ok=true;
        if (used[i][j]==0)
        DFS(i,j);
    }
    FOR(i,1,n-1)
    {
        a[1]=i;
        int u=1+i;
        if (u<=0||u>n) cout<<i<<endl;
        else
        if (sum[u][1]==-1) cout<<-1<<endl;
        else
        cout<<i+sum[u][1]<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

