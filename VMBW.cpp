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
#define mp(a,b) make_pair((a),(b))

typedef vector<int> VI ;
typedef vector<string> VS ;
template<class T> inline int size(const T&c) { return c.size(); }

using namespace std;
int fastMax(int x, int y) { return (((y-x)>>(32-1))&(x^y))^y; }
int fastMin(int x, int y) { return (((y-x)>>(32-1))&(x^y))^x; }
const int maxn=100000+10;
const int hs=500;
int res[2][2];
int cnt[maxn][2];
vector<int> a[maxn];
vector<int> b[maxn];
bool big[maxn];
int c[maxn];
int u,v,n,m,q;
char temp[10];

int main()
{
    //freopen("VMBW.inp","r",stdin);
    //freopen("VMBW.out","w",stdout);
    cin>>n>>m;
    FOR(i,1,m)
    {
        cin>>u>>v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    FOR(i,1,n) cin>>c[i];
    FOR(i,1,n)
        FOR(j,0,a[i].size()-1) cnt[i][c[a[i][j]]]++,res[c[i]][c[a[i][j]]]++;
    FOR(i,1,n)
    {
        //cout<<a[i].size()<<' '<<hs<<' '<<((int)a[i].size()>-1)<<endl;
        if (a[i].size()>hs) big[i]=true;
    }
    FOR(i,1,n)
    {
        if (big[i])
        FOR(j,0,a[i].size()-1)
        if (big[a[i][j]]) b[i].push_back(a[i][j]);
    }
    cin>>q;
    FOR(i,1,q)
    {
        scanf("%s",&temp);
        if (temp[0]=='s')
        {
            scanf("%d",&u);
            if (big[u]==false)
            {
                FOR(i,0,a[u].size()-1)
                {
                   int v=a[u][i];
                   res[c[u]][c[v]]--;
                   res[c[v]][c[u]]--;
                   res[1-c[u]][c[v]]++;
                   res[c[v]][1-c[u]]++;
                   if (big[v])
                   {
                       cnt[v][c[u]]--;
                       cnt[v][1-c[u]]++;
                   }
                }
                c[u]=1-c[u];
            }
            else
            {
                res[c[u]][0]-=cnt[u][0];
                res[c[u]][1]-=cnt[u][1];
                res[0][c[u]]-=cnt[u][0];
                res[1][c[u]]-=cnt[u][1];
                res[1-c[u]][0]+=cnt[u][0];
                res[1-c[u]][1]+=cnt[u][1];
                res[0][1-c[u]]+=cnt[u][0];
                res[1][1-c[u]]+=cnt[u][1];
                FOR(i,0,b[u].size()-1)
                {
                    int v=b[u][i];
                    //cout<<"c "<<u<<' '<<v<<endl;
                    cnt[v][c[u]]--;
                    cnt[v][1-c[u]]++;
                }
                c[u]=1-c[u];
            }
            //FOR(i,1,n) cout<<cnt[i][0]<<' '<<cnt[i][1]<<endl;
        }
        else
        {
            scanf("%d%d",&u,&v);
            if (u==v) cout<<res[u][v]/2<<endl;
            else
            cout<<res[u][v]<<endl;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
