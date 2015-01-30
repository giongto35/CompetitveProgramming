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
const int maxn = 200000+10;
vector<int> a[maxn];
pair<int,int> b[maxn];
vector<int> c[maxn];
int used[maxn];
int fr[maxn],re[maxn];
int D[maxn];
bool cyc;
int spt;
int cnt;
int n,m,u;
int List[maxn];

void DFS(int u)
{
    D[u]=1;
    FOR(i,0,c[u].size()-1)
    {
        if (D[c[u][i]]==1) cyc=true;
        else if (D[c[u][i]]==0) DFS(c[u][i]);
        if (cyc) return ;
    }
    List[cnt]=u;
    cnt--;
    D[u]=2;
}

int main()
{
    //freopen("D274.inp","r",stdin);
    //freopen("D274.out","w",stdout);
    cin>>n>>m;
    FOR(i,1,n)
    FOR(j,1,m)
    {
        cin>>u;
        a[i].push_back(u);
    }
    int snode=m;
    FOR(i,1,n)
    {
        FOR(j,1,m)
        {
            b[j]=make_pair(a[i][j-1],j);
        }
        sort(b+1,b+m+1);
        b[0].first=-1231;
        b[m+1].first=-1231;
        spt=0;
        FOR(j,1,m)
        {
            if (b[j].first!=b[j-1].first) fr[++spt]=j;
            if (b[j].first!=b[j+1].first) re[spt]=j;
        }
        FOR(j,2,spt)
        {
            if (b[fr[j-1]].first==-1) continue;
            snode++;
            //cout<<fr[j-1]<<' '<<re[j-1]<<' '<<fr[j]<<' '<<re[j]<<endl;
            FOR(k,fr[j-1],re[j-1]) c[b[k].second].push_back(snode);
            FOR(k,fr[j],re[j]) c[snode].push_back(b[k].second);
        }
    }/*
    FOR(i,1,snode)
    {
        FOR(j,0,c[i].size()-1)
        cout<<i<<' '<<c[i][j]<<endl;
    }*/

    cnt=snode;
    cyc=false;
    FOR(i,1,snode) if (D[i]==0) DFS(i);
    if (cyc)
    {
        cout<<-1;
        return 0;
    }
    int dem;
    FOR(i,1,snode) if (List[i]<=m) cout<<List[i]<<' ',dem++;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
