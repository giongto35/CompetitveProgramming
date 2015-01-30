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
const int maxn=100000+10;
vector<int> a[maxn];
int sl[maxn];
int bd;
int md;
int cnt;
bool mark[maxn];
int n,m,u,v;
int d[maxn];

void DFS(int u)
{
    mark[u]=true;
    cnt++;
    FOR(i,0,a[u].size()-1)
        if (mark[a[u][i]]==false) DFS(a[u][i]);
}

int main()
{
    //freopen("B292.inp","r",stdin);
    //freopen("B292.out","w",stdout);
    cin>>n>>m;
    FOR(i,1,m)
    {
        cin>>u>>v;
        a[u].push_back(v);
        a[v].push_back(u);
        d[u]++;
        d[v]++;
    }
    bd=0;
    md=1;
    FOR(i,1,n)
    {
      if (d[i]==1) bd=i;
      if (d[i]>md) md=i;
      sl[d[i]]++;
    }
    memset(mark,false,sizeof(mark));
    if (bd!=0&&d[md]<=2)
    {
        if (sl[1]==2&&sl[2]==n-2)
        {
            DFS(bd);
            if (cnt==n) cout<<"bus topology"<<endl;
            else
                cout<<"unknown topology"<<endl;
        }
        else
            cout<<"unknown topology"<<endl;
    }
    else
    {
        if (sl[2]==n)
        {
            DFS(1);
            if (cnt==n) cout<<"ring topology"<<endl;
            else
                cout<<"unknown topology"<<endl;
        }
        else
        if (d[md]==n-1&&sl[1]==n-1)
        {
            DFS(md);
            if (cnt==n) cout<<"star topology"<<endl;
            else
                cout<<"unknown topology"<<endl;
        }
        else
        cout<<"unknown topology"<<endl;

    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

