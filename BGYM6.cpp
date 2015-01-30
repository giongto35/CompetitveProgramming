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

const int maxn = 10000+10;
const int MAX = 10000;
int nz,nr,sz;

vector<int> ke[maxn];
bool vis[maxn];
int fr,re;
int q[maxn];
int d[maxn];
int T,id,u;
int maxd[maxn];
vector<int> ll;

int main()
{
    //freopen("BGYM6.inp","r",stdin);
    //freopen("","w",stdout);
    scanf("%d",&T);
    while (T--)
    {
        scanf("%d%d",&nz,&nr);
        for (int i = 1; i <= nz; i++)
        {
            scanf("%d%d",&id,&sz);
            ke[id].resize(sz);
            for (int j = 0; j < sz; j++)
            {
                scanf("%d",&ke[id][j]);
            }
        }
        ll.clear();
        for (int x = 1; x <= nr; x++){
            scanf("%d",&sz);
            for (int j = 0; j < sz; j++)
            {
                scanf("%d", &u);
                ll.push_back(u);
            }
        }
        memset(maxd,0,sizeof(maxd));
        for (int x = 0;  x < ll.size(); x++) {
            //cout<<ll[x]<<endl;
            for (int i = 0; i <= MAX; i++)
            {
                d[i] = oo;
            }
            d[ll[x]] = 0 ;
            q[1] = ll[x];
            fr = 0;
            re = 1;
            //cout<<"ABC"<<d[0]<<endl;
            while (fr < re)
            {
                int u = q[++fr];
                //if (u == 0) cout<<"DKM"<<' '<<fr<<' '<<re<<endl;
                for (int i = 0; i < ke[u].size(); i++)
                {
                    if (d[ke[u][i]] == oo)
                    {
                        d[ke[u][i]] = d[u] + 1;
                        q[++re] = ke[u][i];
                    }
                }
            //cout<<"ABC"<<d[0]<<endl;

            }
            for (int i = 0; i <= MAX; i++)
            {
                maxd[i] = max(maxd[i], d[i]);
            }
            //cout<<maxd[0]<<' '<<d[0]<<endl;
            /*for (int i = 7390; i <= 7411; i++)
                cout<<maxd[i]<<' ';
            cout<<endl;*/
        }
        pair<int,int> res = make_pair(oo,oo);
        for (int i = 0; i <= MAX; i++)
        {
            res = min(res, make_pair(maxd[i], i));
            //cout<<res.first<<' '<<res.second<<endl;
        }
        cout<<res.first + 1<<' '<<res.second<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

