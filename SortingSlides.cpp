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

const int maxn = 10000;
struct rect
{
    int ymin;
    int ymax;
    int xmin;
    int xmax;
} R[maxn];
int cnt;
vector<int> a[maxn];
bool mark[maxn];
int mX[maxn],mY[maxn],rX[maxn],rY[maxn];
int x[maxn],y[maxn];
int n,res;
vector<pair<int,int> > ans;
int find(int x)
{
    if (x == 0) return 1;
    if (mark[x]) return 0;
    mark[x] = 1;
    FOREACH(it,a[x])
    {
        int y = (*it);
        if (find(mY[y]))
        {
            mX[x] = y; mY[y] = x;
            return 1;
        }
    }
    return 0;
}

int matching()
{
    memset(mX,0,sizeof(mX));
    memset(mY,0,sizeof(mY));
    res = 0;
    for(int i = 1; i <= n; i++)
    if (mX[i] == 0) {
        memset(mark, 0, sizeof mark);
        res += find(i);
    }
    return res;
}

int main()
{
    //freopen("SortingSlides.inp","r",stdin);
    //freopen("","w",stdout);
    while (true){
        scanf("%d",&n);
        if (n == 0) break;
        for (int i  = 1; i <= n; i++)
            {
                scanf("%d%d%d%d",&R[i].xmin,&R[i].xmax,&R[i].ymin,&R[i].ymax);
                a[i].clear();
            }
        for (int i = 1; i <= n; i++)
            {
                scanf("%d%d",&x[i],&y[i]);
                for (int j = 1; j <=n; j++)
                {
                    if (x[i] >= R[j].xmin && x[i] <= R[j].xmax && y[i] >= R[j].ymin && y[i] <= R[j].ymax)
                    {
                        a[i].push_back(j);
                    }
                }
            }
        int smax = matching();
		cnt++;
        cout<<"Heap "<<cnt<<endl;
        //
        memcpy(rX,mX,sizeof(mX));
        memcpy(rY,mY,sizeof(mY));
        ans.clear();
        for (int i = 1; i <= n; i++)
        {
            a[i].erase(find(a[i].begin(),a[i].end(),rX[i]));
            if (matching() < smax)
                ans.push_back(make_pair(rX[i],i));
            a[i].push_back(rX[i]);
        }

        sort(ans.begin(),ans.end());
        if (ans.size() == 0) cout<<"none"; else
        for(int i = 0; i < (int)ans.size(); i++)
            if (i == 0) printf("(%c,%d)",(char)('A' + ans[i].first - 1),ans[i].second);
                else   printf(" (%c,%d)",(char)('A' + ans[i].first - 1),ans[i].second);
        cout<<endl;
        cout<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
